#include "../MCAL/UART/UART.h"
#include "../Library/Constants.h"
#include <avr/interrupt.h>

_S void clean_arr (uint8_t* arr);

void UART_Driver(void)
{
	uint8_t arr[UART_R_Buffer_Size] = {0};
	Uart_init(9600);
	sei();
	while(1)
	{
		Uart_ReceiveStringPooling(arr, UART_R_Buffer_Size, '\r');
		Uart_SendStringAsynch(arr);
		while(UART_EN_BUSY_Transmit == Uart_SendPooling('\r'));
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