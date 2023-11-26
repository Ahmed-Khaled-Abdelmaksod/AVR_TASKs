/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< SSD_interface file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : HAL
 * @brief  : contains all headers of Seven segment device HW
 */
#ifndef _SSD_INTERFACE_H_
#define _SSD_INTERFACE_H_
/**************** include section ****************/
#include"../../MCAL/DIO/DIO_interface.h"
#include"SSD_config.h"
#include"SSD_private.h"

/**************** define section ****************/
#define SSD_COMMON_CATHOD  		 (u8)0x00
#define SSD_COMMON_ANODE   		 (u8)0x01


#define SSD_HIGHER_NIBBLE  		 (u8)0x00
#define SSD_LOWER_NIBBLE   		 (u8)0x01
#define SSD_PORT                 (u8)0x02


#define SSD_DIRECT_CONNECTION    (u8)0x00
#define SSD_DECODER_CONNECTION   (u8)0x01

typedef struct
{

	pin_t enable;
	u8 port;
	u8 pins_location;
	u8 ssd_common;
	u8 connection_type;
}ssd_t; // with decoder


/**************** interfaces section ****************/

void SSD_init(const ssd_t *ssd);

void SSD_writeNumber(const ssd_t *ssd,u8 number);


	void SSD_enable(const ssd_t *ssd);
	void SSD_disable(const ssd_t *ssd);



#endif
