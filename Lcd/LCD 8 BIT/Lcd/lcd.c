#include <avr/io.h>
#include <stdint.h>
#include "config.h"
#include <util/delay.h>



void lcd_data(unsigned char data)
{
	PORTD = data;
	PORTB = PORTB | (1 << PB0); //RS = 1 
	PORTB = PORTB & (~(1 << PB1)); //RW = 0
	PORTB = PORTB | (1 << PB2);   //EN = 1
	_delay_ms(1);
	PORTB = PORTB & (~(1 << PB2)); //EN = 0
	
}
 
void lcd_cmd(unsigned char command)
{
	PORTD = command;
	PORTB = PORTB & (~(1 << PB0));   //RS = 0
	PORTB = PORTB & (~(1 << PB1));   //RW = 0
	PORTB = PORTB | (1 << PB2);      //EN = 1
	_delay_ms(1);
	PORTB = PORTB & (~(1 << PB2));   //EN = 0
	
}

void lcd_string(unsigned char *d)
{
	//char i = 0;
	
	while(*d)
	{
		lcd_data(*d++);
	}
	
}

void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	
}