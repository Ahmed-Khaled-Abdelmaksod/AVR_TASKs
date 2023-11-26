/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Application file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : application
 * @brief  : contains the main application
 */
//#include<avr/io.h>
#include"HAL/LED/LED_interface.h"
#include"HAL/SSD/SSD_interface.h"
 // Set your microcontroller's clock frequency (e.g., 1 MHz)
#include <util/delay.h>
#define F_CPU 1000000UL

ssd_t ssd1 = {
	.port = PORTC_INDEX,
	.connection_type = SSD_DIRECT_CONNECTION,
	.ssd_common = SSD_COMMON_CATHOD
};
u8 counter = 0x00;
int main(void)
{
	SSD_init(&ssd1);

	while(1)
	{
		if(counter <= 9)
		{
			SSD_writeNumber(&ssd1,counter);
			counter++;
			_delay_ms(500);
		}
		else
		{
			counter++;
		}

	}


}

