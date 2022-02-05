#include "../MCAL/UART/UART.h"
#include "../ECUAL/EEPROM/I2C_EEPROM/I2C_EEPROM.h"
#include "../Library/System_Delays/Delays.h"
#include "../Library/Constants.h"
#include <math.h>
#include <avr/interrupt.h>

#define MAX_SIZE_CONSTRAIN    255U

_S void clean_arr (uint8_t* arr);
_S void Console_Replay(void);
_S void TRF_Next_State(uint8_t* arr);

typedef enum
{
	EEUART_init,
	EEUART_Write,
	EEUART_Read,
	EEUART_Address,
	EEUART_Data
}EEUART_t;

#define WRITTING_EE   0
#define READING_EE    1
#define NO_OPER_EE    2

_S EEUART_t  EPR_U = EEUART_init;
_S uint16_t Address = 0x0000;
_S uint8_t  Data = 0;
_S uint8_t  AddressFlag = DISABLE; 
_S uint8_t  OperationFlag = NO_OPER_EE;

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
				if(AddressFlag == ENABLE)
				{
					result = Uart_ReceiveStringPooling(arr, 5, '\r');
				}
				else
				{
					result = Uart_ReceiveStringPooling(arr, MAX_SIZE_CONSTRAIN, '\r');
				}
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
				Uart_SendStringPooling("consol : ");
				AddressFlag = ENABLE;
			}break;
			case EEUART_Read:
			{
				Uart_SendStringPooling("consol : ");
				AddressFlag = ENABLE;
			}break;
			case EEUART_Address:
			{
				Console_Replay();
			}break;
			case EEUART_Data:
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
_S void TRF_Next_State(uint8_t* arr)
{
	if(AddressFlag == ENABLE)
	{
		Address = atoi(arr);
		if(EPR_U ==  EEUART_Write)
		{
			I2C_EEPROM_Write(Address, Data);
		}
		else if(EPR_U ==  EEUART_Read)
		{
			I2C_EEPROM_Read(Address, &Data);
		}
		else{/*MISRA C*/}
	}
	else
	{
		if(0 == strcmp(arr, "WRITE"))
		{
			EPR_U =  EEUART_Write;
		}
		else if(0 == strcmp(arr, "READ"))
		{
			EPR_U = EEUART_Read;
		}
		else{/*MISRA C*/}
	}
}