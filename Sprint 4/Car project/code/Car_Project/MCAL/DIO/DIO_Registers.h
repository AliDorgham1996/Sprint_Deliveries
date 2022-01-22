#ifndef DIO_REGISTERS_H_
#define DIO_REGISTERS_H_

#include "avr/io.h"

#if 0
/*- GPIO_A REGISTERS-----------------------------------------------*/
#define PORTA				  (*((volatile uint8_t*)0x3B))
#define DDRA				  (*((volatile uint8_t*)0x3A))
#define PINA				  (*((volatile uint8_t*)0x39))

/*- GPIO_B REGISTERS-----------------------------------------------*/
#define PORTB				  (*((volatile uint8_t*)0x38))
#define DDRB				  (*((volatile uint8_t*)0x37))
#define PINB				  (*((volatile uint8_t*)0x36))

/*- GPIO_C REGISTERS-----------------------------------------------*/
#define PORTC			  (*((volatile uint8_t*)0x35))
#define DDRC			  (*((volatile uint8_t*)0x34))
#define PINC			  (*((volatile uint8_t*)0x33))

/*- GPIO_A REGISTERS-----------------------------------------------*/
#define PORTD			  (*((volatile uint8_t*)0x32))
#define DDRD			  (*((volatile uint8_t*)0x31))
#define PIND			  (*((volatile uint8_t*)0x30))

#endif


#endif /* DIO_REGISTERS_H_ */