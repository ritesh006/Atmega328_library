/*
 * Lcd.c
 *
 * Created: 25-08-2022 12.59.36 PM
 * Author : DSI-LPT-060
 */ 

#include <avr/io.h>
#include <stdint.h>
#include "config.h"
#include <util/delay.h>


void lcd_data(unsigned char);
void lcd_cmd(unsigned char);
void lcd_string(unsigned char *);
void lcd_init();







int main(void)
{
	DDRD = 0xff;  /* port D configured as output */
	DDRB = DDRB | (1 << DDB0) | (1 << DDB1) | (1 << DDB2); /* B0, B1, B2 of port B configured as output */
    lcd_init();
    while (1) 
    {
		
		lcd_cmd(0x80);
		
		lcd_string("ritesh");
		
		
    }
}

