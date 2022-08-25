/*
 * Blinky.c
 *
 * Created: 24-08-2022 6.23.46 PM
 * Author : DSI-LPT-060
 */ 
#include <stdint.h>
#include "config.h"  
#include <avr/io.h>
#include <util/delay.h>

void delay(unsigned int ms)
{
	unsigned char i;
	for(;ms>0;ms--)
	{
		i=250;
		while(--i);
		i=247;
		while(--i);
	}
}

int main(void)
{
	DDRD = 0xff;
	
    while (1) 
    {
		PORTD = 0xff;
		//delay(1000);
		_delay_ms(10);
		
		PORTD = 0x00;
		_delay_ms(10);
		//delay(1000);
    }
}

