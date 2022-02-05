#define F_CPU 8000000UL
#include <util/delay.h>
#include <avr/interrupt.h>
#include "../MCAL/UART/UART.h"
#include "../ECUAL/Keypad/Keypad.h"

void Task_2(void)
{	
	uint8_t Key = KEYPAD_INVALID_KEY;
	Uart_init(9600);
	Keypad_Init();
	sei();
	while(1)
	{
		Key = Keypad_GetKey();
		if(Key != KEYPAD_INVALID_KEY)
		{
			Uart_SendPooling(Key);
			_delay_ms(1000);
		}
	}
}