#include "../MCAL/SPI/SPI.h"
#include "../Library/Registers.h"
#include "../Library/System_Delays/Delays.h"

void SPI_Driver(void)
{
	SPI_Init(SPI_EN_Master);
	Delay_Ms(1000);
	PORTB4 = 0;
	SPI_Transceive('A');
	PORTB4 = 1;
	while(1);
}
/*
void SPI_Driver(void)
{
	SPI_Init(SPI_EN_Slave);
	Delay_Ms(10);
	DDRA  = 0xFF;
	PORTA = SPI_Transceive(SPI_DUMMY);
	while(1);
}
*/