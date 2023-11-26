/*
 * <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< DIO_program file >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 * @author : Ahmed Khaled Abdelmaksod Ebrahim
 * @layer  : MCAL
 * @brief  : contains all implementation of DIO interfaces
 */
#include"DIO_interface.h"

/**
 * @brief Set the direction of a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 * @param direction   Desired direction for the GPIO pin (DIO_INPUT or DIO_OUTPUT).
 */
void DIO_setDirectonPin(const pin_t *pin,u8 direction)
{
	if(direction == DIO_INPUT)
	{
		switch(pin->port)
		{
		case PORTA_INDEX:
			CLEAR_BIT(DDRA,pin->pin);
			break;
		case PORTB_INDEX:
			CLEAR_BIT(DDRB,pin->pin);
			break;
		case PORTC_INDEX:
			CLEAR_BIT(DDRC,pin->pin);
			break;
		case PORTD_INDEX:
			CLEAR_BIT(DDRD,pin->pin);
			break;
		}
	}
	else if(direction == DIO_OUTPUT)
	{
		switch(pin->port)
		{
		case PORTA_INDEX:
			SET_BIT(DDRA,pin->pin);
			break;
		case PORTB_INDEX:
			SET_BIT(DDRB,pin->pin);
			break;
		case PORTC_INDEX:
			SET_BIT(DDRC,pin->pin);
			break;
		case PORTD_INDEX:
			SET_BIT(DDRD,pin->pin);
			break;
		}
	}
}


/**
 * @brief Write a logic level to a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 * @param level   Desired logic level for the GPIO pin (DIO_LOW or DIO_HIGH).
 */
void DIO_writeLogicPin(const pin_t *pin,u8 level)
{
	if(level == DIO_LOW)
		{
			switch(pin->port)
			{
			case PORTA_INDEX:
				CLEAR_BIT(PORTA,pin->pin);
				break;
			case PORTB_INDEX:
				CLEAR_BIT(PORTB,pin->pin);
				break;
			case PORTC_INDEX:
				CLEAR_BIT(PORTC,pin->pin);
				break;
			case PORTD_INDEX:
				CLEAR_BIT(PORTD,pin->pin);
				break;
			}
		}
		else if(level == DIO_HIGH)
		{
			switch(pin->port)
			{
			case PORTA_INDEX:
				SET_BIT(PORTA,pin->pin);
				break;
			case PORTB_INDEX:
				SET_BIT(PORTB,pin->pin);
				break;
			case PORTC_INDEX:
				SET_BIT(PORTC,pin->pin);
				break;
			case PORTD_INDEX:
				SET_BIT(PORTD,pin->pin);
				break;
			}
		}
}



/**
 * @brief Read the logic level of a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 * @return u8   Logic level of the GPIO pin (DIO_LOW or DIO_HIGH).
 */
u8 DIO_readLogicPin(const pin_t *pin)
{
	u8 local_pin = 0x00;
	switch(pin->port)
	{
	case PORTA_INDEX:
		local_pin = GET_BIT(PINA,pin->pin);
		break;
	case PORTB_INDEX:
		local_pin = GET_BIT(PINB,pin->pin);
		break;
	case PORTC_INDEX:
		local_pin = GET_BIT(PINC,pin->pin);
		break;
	case PORTD_INDEX:
		local_pin = GET_BIT(PIND,pin->pin);
		break;
	}
	return local_pin;
}


/**
 * @brief Initialize a specific GPIO pin based on the configuration in the pin_t structure.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin with its configuration.
 */
void DIO_initPin(const pin_t *pin)
{
	DIO_setDirectonPin(pin,pin->direction);
	DIO_writeLogicPin(pin,pin->logic);
}



/**
 * @brief Toggle the logic level of a specific GPIO pin.
 *
 * @param pin   Pointer to the pin_t structure representing the GPIO pin.
 */
void DIO_togglePin(pin_t *pin)
{
	switch(pin->port)
	{
	case PORTA_INDEX :
		TOGGLE_BIT(PORTA,pin->pin);
		break;
	case PORTB_INDEX :
		TOGGLE_BIT(PORTB,pin->pin);
		break;
	case PORTC_INDEX :
			TOGGLE_BIT(PORTC,pin->pin);
			break;
	case PORTD_INDEX :
			TOGGLE_BIT(PORTD,pin->pin);
			break;
	}

}

/**
 * @brief Set the direction of an entire GPIO port.
 *
 * @param port       The GPIO port to configure (e.g., PORTA_INDEX).
 * @param direction  Desired direction for the GPIO port (DIO_INPUT or DIO_OUTPUT).
 */
void DIO_setDirectonPort(u8 port,u8 direction)
{
	switch(port)
	{
	case PORTA_INDEX :
		DDRA = direction;
		break;
	case PORTB_INDEX :
		DDRB = direction;
		break;
	case PORTC_INDEX :
		DDRC = direction;
		break;
	case PORTD_INDEX:
		DDRD = direction;
		break;
	}
}



/**
 * @brief Write a logic level to an entire GPIO port.
 *
 * @param port   The GPIO port to write to (e.g., PORTA_INDEX).
 * @param level  Desired logic level for the GPIO port (DIO_LOW or DIO_HIGH).
 */
void DIO_writeLogicPort(u8 port,u8 level)
{
	switch(port)
		{
		case PORTA_INDEX :
			PORTA = level;
			break;
		case PORTB_INDEX :
			PORTB = level;
			break;
		case PORTC_INDEX :
			PORTC = level;
			break;
		case PORTD_INDEX:
			PORTD = level;
			break;
		}
}



/**
 * @brief Read the logic levels of an entire GPIO port.
 *
 * @param port   The GPIO port to read from (e.g., PORTA_INDEX).
 * @return u8    Logic levels of the GPIO port as a byte.
 */
u8 DIO_readLogicPort(u8 port)
{
	u8 local_port = 0x00;
	switch(port)
	{
	case PORTA_INDEX :
		local_port = PINA;
		break;
	case PORTB_INDEX :
		local_port = PINB;
		break;
	case PORTC_INDEX :
		local_port = PINC;
		break;
	case PORTD_INDEX:
		local_port = PIND;
		break;
	}
	return local_port;
}



/**
 * @brief Initialize an entire GPIO port with specified direction and initial logic levels.
 *
 * @param port       The GPIO port to initialize (e.g., PORTA_INDEX).
 * @param direction  Desired direction for the GPIO port (DIO_INPUT or DIO_OUTPUT).
 * @param logic      Initial logic levels for the GPIO port (DIO_LOW or DIO_HIGH).
 */
void DIO_initPort(u8 port,u8 direction,u8 logic)
{
	DIO_setDirectonPort(port,direction);
	DIO_writeLogicPort(port,logic);
}



/**
 * @brief Toggle the logic levels of all pins in a specified GPIO port.
 *
 * @param port   The GPIO port to toggle (e.g., PORTA_INDEX).
 */
void DIO_togglePort(u8 port)
{
	switch(port)
	{
	case PORTA_INDEX :
		PORTA ^= 0xFF;
		break;
	case PORTB_INDEX :
		PORTB ^= 0xFF;
		break;
	case PORTC_INDEX :
		PORTC ^= 0xFF;
		break;
	case PORTD_INDEX:
		PORTD ^= 0xFF;
		break;
	}
}


/**
 * @brief Sets the direction of the high nibble (bits 7-4) of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @param direction Desired direction for the high nibble (use bits 7-4).
 */
void DIO_setDirectionHighNibble(u8 port,u8 direction)
{
	direction <<= 4; // 1100 0000
	switch(port)
	{
	case PORTA_INDEX :
		DDRA &= 0x0F; // 0000 0101
		DDRA |= direction; // 0b0000 0101  | 1100 0000 = 1100 0101
		break;
	case PORTB_INDEX :
		DDRB &= 0x0F; // 0000 0101
		DDRB |= direction; // 0b0000 0101  | 1100 0000 = 1100 0101
		break;
	case PORTC_INDEX :
		DDRC &= 0x0F; // 0000 0101
		DDRC |= direction; // 0b0000 0101  | 1100 0000 = 1100 0101
		break;
	case PORTD_INDEX:
		DDRD &= 0x0F; // 0000 0101
		DDRD |= direction; // 0b0000 0101  | 1100 0000 = 1100 0101
		break;
	}
}


/**
 * @brief Writes logic levels to the high nibble of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @param level Logic levels for the high nibble (use bits 7-4).
 */
void DIO_writeLogicHighNibble(u8 port,u8 level)
{
	level <<=4; // 1011 0000
	switch(port)
	{
	case PORTA_INDEX : // 1110 0110
		PORTA &= 0X0F; // 0000 0110
		PORTA |= level;// 0000 0110 | 1011 0000  = 1011 0110
		break;
	case PORTB_INDEX :
		PORTB &= 0X0F; // 0000 0110
		PORTB |= level;// 0000 0110 | 1011 0000  = 1011 0110
		break;
	case PORTC_INDEX :
		PORTC &= 0X0F; // 0000 0110
		PORTC |= level;// 0000 0110 | 1011 0000  = 1011 0110
		break;
	case PORTD_INDEX:
		PORTD &= 0X0F; // 0000 0110
		PORTD |= level;// 0000 0110 | 1011 0000  = 1011 0110
		break;
	}
}



/**
 * @brief Reads logic levels from the high nibble of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @return Logic levels of the high nibble (bits 7-4) of the specified port.
 */
u8 DIO_readLogicHighNibble(u8 port)
{
	u8 local_port = 0x00;
		switch(port)
		{
		case PORTA_INDEX :
			local_port = PINA & 0XF0;
			break;
		case PORTB_INDEX :
			local_port = PINB & 0XF0;
			break;
		case PORTC_INDEX :
			local_port = PINC & 0XF0;
			break;
		case PORTD_INDEX:
			local_port = PIND & 0XF0;
			break;
		}
		local_port >>= 4;
		return local_port;
}


/**
 * @brief Initializes the high nibble of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @param direction Desired direction for the high nibble (bits 7-4), use binary or hexadecimal literals.
 * @param logic Initial logic levels for the high nibble (bits 7-4), use binary or hexadecimal literals.
 */
void DIO_initHighNibble(u8 port,u8 direction,u8 logic)
{
	DIO_setDirectionHighNibble(port,direction);
	DIO_writeLogicHighNibble(port,logic);
}


/**
 * @brief Toggles the logic levels of the high nibble of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 */
void DIO_toggleHighNibble(u8 port)
{
	switch(port)
	{
	case PORTA_INDEX :
		PORTA ^= 0xF0;
		break;
	case PORTB_INDEX :
		PORTB ^= 0xF0;
		break;
	case PORTC_INDEX :
		PORTC ^= 0xF0;
		break;
	case PORTD_INDEX:
		PORTD ^= 0xF0;
		break;
	}
}



/**
 * @brief Sets the direction of the low nibble (bits 3-0) of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @param direction Desired direction for the low nibble (use bits 3-0).
 */
void DIO_setDirectionLowNibble(u8 port,u8 direction)
{
	direction &= 0x0F; // 0000 0110
		switch(port)
		{
		case PORTA_INDEX :
			DDRA &= 0xF0; // 0101 0000
			DDRA |= direction; // 0b0101 0000  | 0000 0110 = 0101 0110
			break;
		case PORTB_INDEX :
			DDRB &= 0xF0; // 0101 0000
			DDRB |= direction; // 0b0101 0000  | 0000 0110 = 0101 0110
			break;
		case PORTC_INDEX :
			DDRC &= 0xF0; // 0101 0000
			DDRC |= direction; // 0b0101 0000  | 0000 0110 = 0101 0110
			break;
		case PORTD_INDEX:
			DDRD &= 0xF0; // 0101 0000
			DDRD |= direction; // 0b0101 0000  | 0000 0110 = 0101 0110
			break;
		}
}



/**
 * @brief Writes logic levels to the low nibble (bits 3-0) of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @param level Logic levels for the low nibble (use bits 3-0).
 */
void DIO_writeLogicLowNibble(u8 port,u8 level)
{
	level &= 0x0F; // 0000 0110
	switch(port)
	{
	case PORTA_INDEX : // 1110 0110
		PORTA &= 0XF0; // 1110 0000
		PORTA |= level;// 1110 0000 | 0000 0110  = 1110 0110
		break;
	case PORTB_INDEX :// 1110 0110
		PORTB &= 0XF0; // 1110 0000
		PORTB |= level;// 1110 0000 | 0000 0110  = 1110 0110
		break;
	case PORTC_INDEX :// 1110 0110
		PORTC &= 0XF0; // 1110 0000
		PORTC |= level;// 1110 0000 | 0000 0110  = 1110 0110
		break;
	case PORTD_INDEX:// 1110 0110
		PORTD &= 0XF0; // 1110 0000
		PORTD |= level;// 1110 0000 | 0000 0110  = 1110 0110
		break;
	}
}



/**
 * @brief Reads logic levels from the low nibble (bits 3-0) of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @return Logic levels of the low nibble of the specified port.
 */
u8 DIO_readLogicLowNibble(u8 port)
{
	u8 local_port = 0x00;
	switch(port)
	{
	case PORTA_INDEX :
		local_port = PINA & 0X0F;
		break;
	case PORTB_INDEX :
		local_port = PINB & 0X0F;
		break;
	case PORTC_INDEX :
		local_port = PINC & 0X0F;
		break;
	case PORTD_INDEX:
		local_port = PIND & 0X0F;
		break;
	}
	return local_port;
}


/**
 * @brief Initializes the low nibble (bits 3-0) of a digital I/O port.
 * @param port Index of the I/O port ('A', 'B', 'C', 'D').
 * @param direction Desired direction for the low nibble (use bits 3-0).
 * @param logic Initial logic levels for the low nibble (use bits 3-0).
 */
void DIO_initLowNibble(u8 port,u8 direction,u8 logic)
{
	DIO_setDirectionLowNibble(port,direction);
	DIO_writeLogicLowNibble(port,logic);
}




void DIO_toggleLowNibble(u8 port)
{
	switch(port)
	{
	case PORTA_INDEX :
		PORTA ^= 0x0F;
		break;
	case PORTB_INDEX :
		PORTB ^= 0x0F;
		break;
	case PORTC_INDEX :
		PORTC ^= 0x0F;
		break;
	case PORTD_INDEX:
		PORTD ^= 0x0F;
		break;
	}
}

