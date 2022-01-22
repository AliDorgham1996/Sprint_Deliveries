/*
 * Indications.c
 *
 * Created: 1/16/2022 2:11:29 AM
 *  Author: Ali Hassan Dorgham
 */ 
#include "Indications.h"

void Basic_io_init(void)
{
	//row2
	DDRC  |= 1<<3;
	PORTC |= 1<<3;
	//led0
	DDRB  |= 1<<4;
	//led1
	DDRB  |= 1<<5;
	//led2
	DDRB  |= 1<<6;
	//led3
	DDRB  |= 1<<7;	
}

void Led_only_on(Led_t led)
{
	PORTB  &= ~(1<<4);
	PORTB  &= ~(1<<5);
	PORTB  &= ~(1<<6);
	PORTB  &= ~(1<<7);
	PORTB  |= (1<<led);
}