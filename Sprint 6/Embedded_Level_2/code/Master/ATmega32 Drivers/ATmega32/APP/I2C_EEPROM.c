#include "../MCAL/UART/UART.h"
#include "../ECUAL/EEPROM/I2C_EEPROM/I2C_EEPROM.h"
#include "../Library/System_Delays/Delays.h"
#include "../Library/Constants.h"

#include <avr/interrupt.h>

#define MAX_SIZE_CONSTRAIN    255U

_S void clean_arr (uint8_t* arr);
_S void Console_Replay(void);

typedef enum
{
	EEUART_init,
	EEUART_Write,
	EEUART_Read
}EEUART_t;

_S EEUART_t EPR_U = EEUART_init;

void I2C_EEPROM(void)
{
	uint8_t arr [MAX_SIZE_CONSTRAIN] = {0};
	uint8_t index = 0;
	UART_Error_t result = UART_EN_valid;
	sei();
	Uart_init(9600);
	LED_init_All();
	while(1)
	{
		switch(EPR_U)
		{
			case EEUART_init:
			{
				Uart_SendStringPooling("Enter  : ");
				result = Uart_ReceiveStringPooling(arr, MAX_SIZE_CONSTRAIN, '\r');
				if(result == UART_EN_END_BY_TERM)
				{
					TRF_Next_State(arr);
				}
				else
				{
					Uart_SendPooling('\r');
				}
				clean_arr(arr);
			}break;
			case EEUART_Write:
			{
				Console_Replay();
			}break;
			case EEUART_Read:
			{
				Console_Replay();
			}break;
			default:{/*MISRA C*/}break;
		}
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
_S void Console_Replay(void)
{
	Uart_SendStringPooling("consol : ");
	Uart_SendStringPooling("OK");
	Uart_SendPooling('\r');
	EPR_U = EEUART_init;
}