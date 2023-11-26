/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_interface file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : MCAL
 * @brief  : contains all headers of DIO peripheral
 */

#ifndef _DIO_INTERFACE_H
#define _DIO_INTERFACE_H


/**************** include section ****************/
#include"DIO_private.h"
#include"../../Libraries/STD_TYPES.h"
#include"../../Libraries/BIT_MATH.h"
/**************** define section ****************/
/*
 * pins declerations
*/
#define PIN0 (u8)0
#define PIN1 (u8)1
#define PIN2 (u8)2
#define PIN3 (u8)3
#define PIN4 (u8)4
#define PIN5 (u8)5
#define PIN6 (u8)6
#define PIN7 (u8)7

/**
 * Ports declerations
 */
#define PORTA_INDEX  (u8)0
#define PORTB_INDEX  (u8)1
#define PORTC_INDEX  (u8)2
#define PORTD_INDEX  (u8)3

/**
 * Ports logic levels
 */
#define DIO_HIGH 	(u8)1
#define DIO_LOW 	(u8)0


/**
 * Ports logic levels
 */
#define DIO_INPUT 	(u8)0
#define DIO_OUTPUT 	(u8)1

/**
 * define pin type
 */
typedef struct
{
	u8 direction;
	u8 logic;
	u8 pin;
	u8 port;
}pin_t;

/**************** interfaces section ****************/

void DIO_setDirectonPin(const pin_t *pin,u8 direction);
void DIO_writeLogicPin(const pin_t *pin,u8 level);
u8 DIO_readLogicPin(const pin_t *pin);
void DIO_initPin(const pin_t *pin);
void DIO_togglePin(pin_t *pin);


void DIO_setDirectonPort(u8 port,u8 direction);
void DIO_writeLogicPort(u8 port,u8 level);
u8 DIO_readLogicPort(u8 port);
void DIO_initPort(u8 port,u8 direction,u8 logic);
void DIO_togglePort(u8 port);

void DIO_setDirectionHighNibble(u8 port,u8 direction);
void DIO_writeLogicHighNibble(u8 port,u8 level);
u8 DIO_readLogicHighNibble(u8 port);
void DIO_initHighNibble(u8 port,u8 direction,u8 logic);
void DIO_toggleHighNibble(u8 port);


void DIO_setDirectionLowNibble(u8 port,u8 direction);
void DIO_writeLogicLowNibble(u8 port,u8 level);
u8 DIO_readLogicLowNibble(u8 port);
void DIO_initLowNibble(u8 port,u8 direction,u8 logic);
void DIO_toggleLowNibble(u8 port);


#endif
