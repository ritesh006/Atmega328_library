/*
 * Lcd_4_Bit.c
 *
 * Created: 25-08-2022 4.19.18 PM
 *  Author: DSI-LPT-060
 */ 

#include <avr/io.h>
#include <stdint.h>
#include "config.h"
#include <util/delay.h>



void lcd_cmd(unsigned char command)
{
	PORTD = (command & 0xf0);
	PORTB = PORTB | (1 << PB2);      //EN = 1
	PORTB = PORTB & (~(1 << PB1));   //RW = 0
	PORTB = PORTB & (~(1 << PB0));   //RS = 0
	_delay_ms(1);
	PORTB = PORTB & (~(1 << PB2));   //EN = 0
	
	PORTD = ((command << 4) & 0xf0);
	PORTB = PORTB | (1 << PB2);      //EN = 1
	PORTB = PORTB & (~(1 << PB1));   //RW = 0
	PORTB = PORTB & (~(1 << PB0));   //RS = 0
	_delay_ms(1);
	PORTB = PORTB & (~(1 << PB2));   //EN = 0
	
	
}


void lcd_data(unsigned char data)
{
	PORTD = (data & 0xf0);
	PORTB = PORTB | (1 << PB2);      //EN = 1
	PORTB = PORTB & (~(1 << PB1));   //RW = 0
	PORTB = PORTB | (1 << PB0);		 //Rs = 1
	_delay_ms(10);
	PORTB = PORTB & (~(1 << PB2));   //EN = 0
	
	PORTD = ((data << 4) & 0xf0);
	PORTB = PORTB | (1 << PB2);      //EN = 1
	PORTB = PORTB & (~(1 << PB1));   //RW = 0
	PORTB = PORTB | (1 << PB0);		 //RS = 1
	_delay_ms(10);
	PORTB = PORTB & (~(1 << PB2));   //EN = 0
	
}


void lcd_init()
{
	lcd_cmd(0x38);
	lcd_cmd(0x06);
	lcd_cmd(0x0c);
	lcd_cmd(0x01);
	
}

void lcd_string(unsigned char *d)
{
	//char i = 0;
	
	while(*d)
	{
		lcd_data(*d++);
	}
	
}

