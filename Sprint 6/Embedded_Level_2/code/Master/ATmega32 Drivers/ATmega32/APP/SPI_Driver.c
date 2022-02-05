#include "../MCAL/SPI/SPI.h"
#include "../Library/Registers.h"
#include "../Library/System_Delays/Delays.h"

void SPI_Driver(void)
{
	uint8_t Data = 0;
	SPI_Init(SPI_EN_Master);
	Delay_Ms(100);
	DDRA  = 0xFF;
	PORTB4 = 0;
	while(1)
	{
		SPI_Send(Data);
		PORTA = Data;
		Data++;
		Delay_Ms(500);
	}
}