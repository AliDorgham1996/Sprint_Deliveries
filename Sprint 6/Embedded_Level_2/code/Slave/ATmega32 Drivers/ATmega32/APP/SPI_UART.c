#include "../Library/Registers.h"
#include "../MCAL/SPI/SPI.h"
#include "../MCAL/UART/UART.h"
#include "../Library/System_Delays/Delays.h"
#include <avr/interrupt.h>

#define MAX_SIZE_CONSTRAIN    255U

_S void clean_arr (uint8_t* arr);


void SPI_UART(void)
{
	uint8_t arr [MAX_SIZE_CONSTRAIN] = {0};
	SPI_Init(SPI_EN_Slave);
	Uart_init(9600);
	sei();
	while(1)
	{
		SPI_RecieveString(arr, '\0');
		Uart_SendStringPooling(arr);
		Uart_SendPooling('\r');
		Delay_Ms(100);
		clean_arr(arr);
	}
}
_S void clean_arr (uint8_t* arr)
{
	uint8_t index = 0;
	uint8_t size = strlen(arr);
	for(index = 0; index < size; index++)
	{
		arr [index] = 0;
	}
}