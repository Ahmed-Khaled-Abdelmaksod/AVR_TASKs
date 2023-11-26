/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_interface file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : HAL
 * @brief  : contains interfaces of led HW
 */
#ifndef _LED_INTERFACE_H_
#define _LED_INTERFACE_H_

/**************** include section ****************/
#include"../../MCAL/DIO/DIO_interface.h"


/**************** define section ****************/

#define LED_ACTIVE_LOW   (u8)0x00
#define LED_ACTIVE_HIGH  (u8)0x01


typedef struct
{
	pin_t pin;
	u8 connection_type;
}led_t;


/**************** interfaces section ****************/
void LED_init(const led_t *led);
void LED_turnOn(const led_t *led);
void LED_turnOff(const led_t *led);
void LED_toggle(led_t *led);


#endif
