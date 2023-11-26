/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< Application file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : application
 * @brief  : contains the main application
 */
//#include<avr/io.h>
#include"HAL/LED/LED_interface.h"
 // Set your microcontroller's clock frequency (e.g., 1 MHz)
#include <util/delay.h>
#define F_CPU 1000000UL
led_t led1 = {
		.pin.pin = PIN0,
		.pin.port = PORTC_INDEX,
		.pin.logic = DIO_LOW,
		.connection_type = LED_ACTIVE_HIGH
};
led_t led2 = {
		.pin.pin = PIN1,
		.pin.port = PORTC_INDEX,
		.pin.logic = DIO_LOW,
		.connection_type = LED_ACTIVE_HIGH
};
led_t led3 = {
		.pin.pin = PIN2,
		.pin.port = PORTC_INDEX,
		.pin.logic = DIO_LOW,
		.connection_type = LED_ACTIVE_LOW
};
u8 counter = 0x00;
int main(void)
{

	LED_init(&led1);
	LED_init(&led2);
	LED_init(&led3);
	while(1)
	{
		if(counter%1==0)
		{
			LED_toggle(&led1);
		}
	    if(counter%2==0)
		{
			LED_toggle(&led2);
		}
		if(counter%3==0)
		{
			LED_toggle(&led3);
		}
		_delay_ms(1000);
		counter++;
		if(counter == 255)
		{
			counter = 0;
		}
	}


}

