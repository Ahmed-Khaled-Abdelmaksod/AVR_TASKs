#include <util/delay.h>
#include "HAL/SSD/SSD_interface.h"


#define F_CPU 1000000UL

ssd_t ssd1 = {
    .port = PORTC_INDEX,
    .connection_type = SSD_DECODER_CONNECTION,
    .ssd_common = SSD_COMMON_ANODE,
    .pins_location = SSD_LOWER_NIBBLE,
    .enable.pin = PIN0,
    .enable.port = PORTB_INDEX,
    .enable.logic = DIO_LOW,
    .enable.direction = DIO_OUTPUT
};

ssd_t ssd2 = {
    .port = PORTA_INDEX,
    .connection_type = SSD_DECODER_CONNECTION,
    .ssd_common = SSD_COMMON_ANODE,
    .pins_location = SSD_LOWER_NIBBLE,
    .enable.pin = PIN1,
    .enable.port = PORTB_INDEX,
    .enable.logic = DIO_LOW,  // Note: Changed to LOW for common anode
    .enable.direction = DIO_OUTPUT
};
pin_t button = {
		.port = PORTC_INDEX,
		.pin = PIN4,
		.direction = DIO_INPUT
};
u8 reader = 0x00;
u8 counter = 0;
int main(void)
{
    SSD_init(&ssd1);
    SSD_init(&ssd2);

    while (1)
    {
    	reader = DIO_readLogicPin(&button);
    	SSD_writeNumber(&ssd1,counter%10);

    	SSD_writeNumber(&ssd2,(counter/10));
		_delay_ms(200);
    	if(reader == DIO_HIGH)
    	{
    		counter++;
    	}
    }
    return 0;
}
