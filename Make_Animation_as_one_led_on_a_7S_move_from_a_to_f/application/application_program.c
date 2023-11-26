#include <util/delay.h>
#include "HAL/SSD/SSD_interface.h"


#define F_CPU 1000000UL

ssd_t ssd1 = {
    .port = PORTC_INDEX,
    .connection_type = SSD_DIRECT_CONNECTION,
    .ssd_common = SSD_COMMON_CATHOD,
    .pins_location = SSD_LOWER_NIBBLE,
};


u8 counter = 0B00000001;
int main(void)
{
    SSD_init(&ssd1);
   //SSD_init(&ssd2);

    while (1)
    {
    	DIO_writeLogicPort(PORTC_INDEX,counter);
    	_delay_ms(500);
    	counter<<=1;
    	if(counter == 0x00)
    	{
    		counter = 0x01;
    	}
    }
    return 0;
}
