#include "../MCAL/UART/UART.h"
#include "../Library/Constants.h"
#include "../ECUAL/LED/LED.h"
#include <avr/interrupt.h>

#define MAX_SIZE_CONSTRAIN    255U

typedef enum
{
	TRF_EN_init,
	TRF_EN_Stop,
	TRF_EN_Wait,
	TRF_EN_Start,
	TRF_EN_Test
}TRF_SYS_t;

_S TRF_SYS_t TRF = TRF_EN_init;

_S void clean_arr (uint8_t* arr);
_S void TRF_Next_State(uint8_t* arr);
_S void Console_Replay(LED_t LED_Num);

void Traffic_System(void)
{
	uint8_t arr [MAX_SIZE_CONSTRAIN] = {0};
	uint8_t index = 0;
	UART_Error_t result = UART_EN_valid; 
	sei();
	Uart_init(9600);
	LED_init_All();
	while(1)
	{
		switch(TRF)
		{
			case TRF_EN_init:
			{
				Uart_SendStringPooling("Enter  : ");
				result = Uart_ReceiveStringPooling(arr, MAX_SIZE_CONSTRAIN, '\r');
				if(result == UART_EN_END_BY_TERM)
				{
					TRF_Next_State(arr);				
				}
				else
				{
					LED_State_All(LED_EN_OFF);
					Uart_SendPooling('\r');
				}
				clean_arr(arr);
			}break;
			case TRF_EN_Stop:
			{
				Console_Replay(LED_0);
			}break;
			case TRF_EN_Wait:
			{
				Console_Replay(LED_1);
			}break;
			case TRF_EN_Start:
			{
				Console_Replay(LED_2);
			}break;
			case TRF_EN_Test:
			{
				Console_Replay(LED_3);
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
_S void TRF_Next_State(uint8_t* arr)
{
	if(0 == strcmp(arr, "START"))
	{
		TRF = TRF_EN_Start;
	}
	else if(0 == strcmp(arr, "STOP"))
	{
		TRF = TRF_EN_Stop;
	}
	else if(0 == strcmp(arr, "WAIT"))
	{
		TRF = TRF_EN_Wait;
	}
	else if(0 == strcmp(arr, "AT"))
	{
		TRF = TRF_EN_Test;
	}
	else{/*MISRA C*/}
}
_S void Console_Replay(LED_t LED_Num)
{
	LED_Only(LED_Num, LED_EN_ON);
	Uart_SendStringPooling("consol : ");
	Uart_SendStringPooling("OK");
	Uart_SendPooling('\r');
	TRF = TRF_EN_init;
}