/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SSD_program file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : HAL
 * @brief  : contains all implementations of Seven segment interfaces
 */

#include"SSD_interface.h"

u8 common_cathod_numbers[10] = SSD_COMMON_CATHOD_ARRAY;

u8 common_anode_numbers[10]  = SSD_COMMON_ANODE_ARRAY;

/**
 * typedef struct
{
#if(ENABLE_BIT == ENABLE_BIT_ON)
	pin_t enable;
#endif
	u8 port;
	u8 pins_location;
	u8 ssd_common;
	u8 connection_type;
}ssd_t; // with decoder
 */


void SSD_init(const ssd_t *ssd)
{
#if(ENABLE_BIT == ENABLE_BIT_ON)
	DIO_initPin(&(ssd->enable));
#endif
	if(ssd->connection_type == SSD_DIRECT_CONNECTION)
	{
		DIO_initPort(ssd->port,0xFF,DIO_LOW); // NOTE : the last pin will be the enable
	}
	else if(ssd->connection_type == SSD_DECODER_CONNECTION)
	{
		if(ssd->pins_location == SSD_HIGHER_NIBBLE)
		{
			DIO_initHighNibble(ssd->port,0xf0,DIO_LOW);
		}
		else if(ssd->pins_location == SSD_LOWER_NIBBLE)
		{
			DIO_initLowNibble(ssd->port,0x0f,DIO_LOW);
		}
	}
}

void SSD_writeNumber(const ssd_t *ssd,u8 number)
{
	if(ssd->connection_type == SSD_DIRECT_CONNECTION)
	{
		if(ssd->ssd_common == SSD_COMMON_CATHOD)
		{
			DIO_writeLogicPort(ssd->port,common_cathod_numbers[number]);
		}
		else if(ssd->ssd_common == SSD_COMMON_ANODE)
		{
			DIO_writeLogicPort(ssd->port,common_anode_numbers[number]);
		}

	}
	else if(ssd->connection_type == SSD_DECODER_CONNECTION)
	{
		if(ssd->pins_location == SSD_HIGHER_NIBBLE)
		{
			DIO_writeLogicHighNibble(ssd->port,number);
		}
		else if(ssd->pins_location == SSD_LOWER_NIBBLE)
		{
			DIO_writeLogicLowNibble(ssd->port,number);
		}
	}
}


#if(ENABLE_BIT == ENABLE_BIT_ON)
	void SSD_enable(const ssd_t *ssd)
	{
		if(ssd->ssd_common == SSD_COMMON_CATHOD)
		{
			DIO_writeLogicPin(&(ssd->enable),DIO_LOW);
		}
		else if(ssd->ssd_common == SSD_COMMON_ANODE)
		{
			DIO_writeLogicPin(&(ssd->enable),DIO_HIGH);
		}
	}
	void SSD_disable(const ssd_t *ssd)
	{
		if(ssd->ssd_common == SSD_COMMON_CATHOD)
		{
			DIO_writeLogicPin(&(ssd->enable),DIO_HIGH);
		}
		else if(ssd->ssd_common == SSD_COMMON_ANODE)
		{
			DIO_writeLogicPin(&(ssd->enable),DIO_LOW);
		}
	}
#endif
