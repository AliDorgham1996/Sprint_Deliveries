#include "../Library/Registers.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/UART/UART.h"
#include "../Library/System_Delays/Delays.h"
#include <avr/interrupt.h>

#define MAX_SIZE_CONSTRAIN    255U

_S void clean_arr (uint8_t* arr);

void SPI_UART(void)
{
	sei();
	uint8_t arr [MAX_SIZE_CONSTRAIN] = {"ALI"};
	SPI_Init(SPI_EN_Master);
	Delay_Ms(1000);
	Uart_init(9600);
	PORTB4 = 0;
	while(1)
	{
		Uart_ReceiveStringPooling(arr, MAX_SIZE_CONSTRAIN, '\r');
		SPI_SendString(arr);
		clean_arr(arr);
	}
}
/*
void SPI_UART(void)
{
	sei();
	uint8_t arr [MAX_SIZE_CONSTRAIN] = {0};
	SPI_Init(SPI_EN_Slave);
	Delay_Ms(10);
	Uart_init(9600);
	while(1)
	{
		SPI_RecieveString(arr,MAX_SIZE_CONSTRAIN);
		Uart_SendStringPooling(arr);
		clean_arr(arr);
	}
}
*/
_S void clean_arr (uint8_t* arr)
{
	uint8_t index = 0;
	uint8_t size = strlen(arr);
	for(index = 0; index < size; index++)
	{
		arr [index] = 0;
	}
}