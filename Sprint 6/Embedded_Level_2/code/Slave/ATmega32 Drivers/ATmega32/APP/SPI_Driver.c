#include "../MCAL/SPI/SPI.h"
#include "../Library/Registers.h"
#include "../Library/System_Delays/Delays.h"

void SPI_Driver(void)
{
	uint8_t Data = 0;
	SPI_Init(SPI_EN_Slave);
	DDRA  = 0xFF;
	while(1)
	{ 
		Data = SPI_Receive();
		PORTA = Data;
	}
}