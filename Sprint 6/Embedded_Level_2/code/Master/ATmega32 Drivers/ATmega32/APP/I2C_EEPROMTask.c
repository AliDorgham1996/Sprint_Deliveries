#include "../MCAL/UART/UART.h"
#include "../ECUAL/EEPROM/I2C_EEPROM/I2C_EEPROM.h"
#include "../Library/System_Delays/Delays.h"
#include "../Library/Registers.h"
#include "../Library/Constants.h"
#include <math.h>
#include <avr/interrupt.h>

#define MAX_SIZE_CONSTRAIN    255U
#define ADDRESS_SIZE_U16      19
#define OPPERATION_SIZE       6

_S void clean_arr (uint8_t* arr);
_S uint64_t dtoi(uint8_t* arr);
_S void ConsoleReplay(void);
_S void TRF_Next_State(uint8_t* arr);

typedef enum
{
	EEUART_init,
	EEUART_Write,
	EEUART_Read
}EEUART_t;

_S EEUART_t  EPR_U = EEUART_init;

void I2C_EEPROMTask(void)
{
	sei();
	uint8_t  arr [MAX_SIZE_CONSTRAIN] = {0};
	uint16_t Address = 0x0000;
	uint8_t  Data = 0;
	UART_Error_t result = UART_EN_valid;
	I2C_EEPROM_init();
	Uart_init(9600);
	while(1)
	{
		clean_arr(arr);
		switch(EPR_U)
		{
			case EEUART_init:
			{
				Uart_SendStringPooling("Enter   : ");
				result = Uart_ReceiveStringPooling(arr, OPPERATION_SIZE, '\r');
				if(result == UART_EN_END_BY_TERM)
				{
					TRF_Next_State(arr);
				}
				else
				{
					Uart_SendPooling('\r');
				}
			}break;
			case EEUART_Write:
			{
				Uart_SendStringPooling("Address : ");
				result = Uart_ReceiveStringPooling(arr, ADDRESS_SIZE_U16, '\r');
				if(result == UART_EN_END_BY_TERM)
				{
					ConsoleReplay();
					while(UART_EN_BUSY_TimeOut==Uart_ReceivePooling(&Data));
					Uart_SendPooling('\r');
					Uart_SendStringPooling("consol  : OK");
					Uart_SendPooling('\r');
					Address = dtoi(arr);
					I2C_EEPROM_Write(Address, Data);
					EPR_U = EEUART_init;	
				}
				else
				{
					Uart_SendPooling('\r');
				}
			}break;
			case EEUART_Read:
			{
				Uart_SendStringPooling("Address : ");
				result = Uart_ReceiveStringPooling(arr, ADDRESS_SIZE_U16, '\r');
				if(result == UART_EN_END_BY_TERM)
				{
					ConsoleReplay();
					Address = dtoi(arr);
					I2C_EEPROM_Read(Address, &Data);
					Uart_SendPooling(Data);
					Uart_SendPooling('\r');
					EPR_U = EEUART_init;
				}
				else
				{
					Uart_SendPooling('\r');
				}
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
	if(0 == strcmp(arr, "WRITE"))
	{
		EPR_U =  EEUART_Write;
		Uart_SendStringPooling("consol  : Write Operation");
		Uart_SendPooling('\r');
	}
	else if(0 == strcmp(arr, "READ"))
	{
		EPR_U = EEUART_Read;
		Uart_SendStringPooling("consol  : Read Operation");
		Uart_SendPooling('\r');
	}
	else
	{
		EPR_U = EEUART_init;
	}
}
_S uint64_t dtoi(uint8_t* arr)
{
	uint64_t return_value = 0;
	uint8_t index = 0;
	uint64_t base = 1;
	uint8_t  Multi = 0;
	uint8_t  Start = 0;
	uint8_t size = strlen(arr);
	switch(arr[0])
	{
		case '0':
		{
			if(arr[1] == 'x' || arr[1] == 'X')
			{
				Multi = 16;
				Start = 2;
			}
			else if(arr[1] == 'b' || arr[1] == 'B')
			{
				Multi = 2;
				Start = 2;
			}
			else
			{
				Multi = 8;
				Start = 1;
			}
		}break;
		default:
		{
			Multi = 10;
			Start = 0;
		}break;
	}
	
	for(index = Start; ((index < size) && (return_value <= 0xFFFFFFFF)); index++)
	{
		return_value += base*(arr[index]-'0');
		base *= Multi;
	}
	
	return return_value;
}
_S void ConsoleReplay(void)
{
	Uart_SendStringPooling("consol  : OK");
	Uart_SendPooling('\r');
	Uart_SendStringPooling("Data    : ");
}