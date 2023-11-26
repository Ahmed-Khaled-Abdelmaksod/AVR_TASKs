/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< LED_program file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : HAL
 * @brief  : contains program of LED HW
 */
#include "LED_interface.h"


/**
 * @brief Initialize a LED based on the provided configuration.
 * @param led Pointer to the led_t structure representing the LED configuration.
 */
void LED_init(const led_t *led)
{
	DIO_setDirectonPin(&(led->pin),DIO_OUTPUT);
}


/**
 * @brief Turn on the LED based on the provided configuration.
 * @param led Pointer to the led_t structure representing the LED configuration.
 */
void LED_turnOn(const led_t *led)
{
	if(led->connection_type == LED_ACTIVE_HIGH)
	{
		DIO_writeLogicPin(&(led->pin),DIO_HIGH);
	}
	else if(led->connection_type == LED_ACTIVE_LOW)
	{
		DIO_writeLogicPin(&(led->pin),DIO_LOW);
	}
}


/**
 * @brief Turn off the LED based on the provided configuration.
 * @param led Pointer to the led_t structure representing the LED configuration.
 */
void LED_turnOff(const led_t *led)
{
	if(led->connection_type == LED_ACTIVE_HIGH)
	{
		DIO_writeLogicPin(&(led->pin),DIO_LOW);
	}
	else if(led->connection_type == LED_ACTIVE_LOW)
	{
		DIO_writeLogicPin(&(led->pin),DIO_HIGH);
	}
}

/**
 * @brief Toggle the state of the LED based on the provided configuration.
 * @param led Pointer to the led_t structure representing the LED configuration.
 */
void LED_toggle(led_t *led)
{
	DIO_togglePin(&led->pin);
}
