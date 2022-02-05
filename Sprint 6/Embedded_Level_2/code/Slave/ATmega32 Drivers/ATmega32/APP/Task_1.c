#define  F_CPU  1000000UL
#include "../MCAL/SPI/SPI.h"
#include "../Library/Registers.h"
#include <util/delay.h>
#include <avr/interrupt.h>

void Task_1(void)
{
	uint8_t Data = 0;
	SPI_Init(SPI_EN_Slave);
	DDRC  = 0xFF;
	PORTC = 0xFF;
	sei();
	//PORTB4 = 1;
	while(1)
	{
		_delay_ms(50);
		Data = SPI_Transceive(SPI_DUMMY);
		if(Data == 'A')
		{
			PORTC = 0x0F;
		}
		else if(Data == 'B')
		{
			PORTC = 0xF0;
		}
		else if(Data == SPI_DUMMY)
		{
			PORTC = 0x00;
		}
	}
}