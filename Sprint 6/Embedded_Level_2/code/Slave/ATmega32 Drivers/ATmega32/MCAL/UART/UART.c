#include "../MCAL/UART/UART.h"
#include "../MCAL/UART/UART_Private.h"
#include "../Library/Configurations.h"
#include "../Library/Constants.h"
#include "../Library/Bit_Math.h"
#include <avr/interrupt.h>
#include <string.h>


typedef enum{Available, Busy, Asynch}Flag_t;

_S _V BQueue_t R_Buffer = {.size = UART_R_Buffer_Size};
_S _V BQueue_t T_Buffer = {.size = UART_T_Buffer_Size};
_S _V Flag_t   R_Flag   = Available;
_S _V Flag_t   T_Flag   = Available;

/* Standard : 8N1  */
UART_Error_t		Uart_init		        (uint32_t BaudRate)
{
	UART_Error_t return_value = UART_EN_valid;
	
	return_value |= Queue_Init(&R_Buffer);
	return_value |= Queue_Init(&T_Buffer);
	
	if(return_value == UART_EN_valid)
	{
		if(BaudRate > 0)
		{
			uint8_t UCSRC_MASK = DISABLE;
			uint32_t BRValue   = ((F_CPU*(UART_SPEED+1))/(16UL*BaudRate)) - 1;
			
			/* Set baud rate */
			//UART.Control_BaudH.BaudRate.control_select = DISABLE;
			UART.Control_BaudH           = (BRValue>>8);
			UART.BaudL                   = (uint8_t)BRValue;
			
			/* Enable receiver and transmitter */
			UART.Enables.recieve         = ENABLE;
			UART.Enables.transmit        = ENABLE;
			
			/* Start filling the receiving buffer */
			UART.Enables.rcivCompIntrrpt = ENABLE;
			
			/* UART settings */
			UCSRC_MASK |= (ENABLE<<URSEL)|(UART_SIZE<<UCSZ);
			UCSRC_MASK |= (UART_STOP<<USBS)|(UART_PARITY<<UPM);
			UCSRC_MASK |= (UART_SYNCHRONOUS<<UMSEL)|(UART_POLARITY<<UCPOL);
			SetMaskBits(UART.Control_BaudH, UCSRC_MASK);
		}
		else
		{
			return_value = UART_EN_InvalidBaudRate;
		}
	}
	else
	{
		return_value = UART_EN_InvalidQueue;
	}
	return return_value;
}
UART_Error_t		Uart_SendPooling	    (uint8_t Data)
{
	UART_Error_t return_value = UART_EN_valid;
	uint32_t timeout = 0;
	if(T_Flag == Available)
	{
		T_Flag = Busy;
		while((UART.Flags.udr_isEmpty == 0) && (timeout <= UART_TIME_OUT))
		{
			timeout++;
		}
		
		if(UART.Flags.udr_isEmpty == 1)
		{
			UART.Data = Data;
		}
		else
		{
			return_value = UART_EN_BUSY_TimeOut;
		}
		T_Flag = Available;
	}
	else
	{
		return_value = UART_EN_BUSY_Transmit;
	}
	return return_value;
}
UART_Error_t		Uart_SendStringPooling	(uint8_t* Data)
{
	UART_Error_t return_value = UART_EN_valid;
	uint32_t timeout = 0;
	uint32_t index = 0;
	uint32_t size = strlen(Data);
	if(Data != NULL)
	{
		if(T_Flag == Available)
		{
			T_Flag = Busy;
			for(index = 0; index < size; index++)
			{
				while((UART.Flags.udr_isEmpty == 0) && (timeout <= UART_TIME_OUT))
				{
					timeout++;
				}
				
				if(UART.Flags.udr_isEmpty == 1)
				{
					timeout = 0;
					UART.Data = Data[index];
				}
				else
				{
					return_value = UART_EN_BUSY_TimeOut;
					break;
				}
			}
			T_Flag = Available;
		}
		else
		{
			return_value = UART_EN_BUSY_Transmit;
		}
	}
	else
	{
		return_value = UART_EN_InvalidPointer;
	}
	return return_value;
}
UART_Error_t		Uart_SendStringAsynch	(uint8_t* Data)
{
	UART_Error_t return_value = UART_EN_valid;
	uint8_t index = 0;
	uint8_t size = strlen(Data);
	if(Data != NULL)
	{
		if(T_Flag == Available)
		{
			T_Flag = Busy;
			while((UART_EN_valid == return_value) && (index < size))
			{
				return_value = (UART_Error_t)EnQueue(&T_Buffer, Data[index]);
				index++;
			}
			T_Flag = Asynch;
			UART.Enables.udrEmptyIntrrpt = ENABLE;
		}
		else
		{
			return_value = UART_EN_BUSY_Transmit;
		}
	}
	else
	{
		return_value = UART_EN_InvalidPointer;
	}
	return return_value;
}
ISR(USART_UDRE_vect)
{
	UART.Flags.udr_isEmpty = ENABLE;
	if(T_Flag == Asynch)
	{
		uint8_t Data = '\0';
		UART_Error_t result = (UART_Error_t)DeQueue(&T_Buffer, &Data);
		if(UART_EN_Buffer_Empty == result)
		{
			UART.Enables.udrEmptyIntrrpt = DISABLE;
			T_Flag = Available;
		}
		else{/*MISRA C*/}
		UART.Data = Data; //terminate with '\0'
	}
	else{/*MISRA C*/}
}
UART_Error_t		Uart_ReceivePooling		(uint8_t* Data)
{
	UART_Error_t return_value = UART_EN_valid;
	uint32_t timeout = 0;
	if(R_Flag == Available)
	{
		if(Data != NULL)
		{
			R_Flag = Busy;
			while((UART.Flags.rciv_cmplt == 0) && (timeout <= UART_TIME_OUT))
			{
				timeout++;
			}
			
			if(UART.Flags.rciv_cmplt == 1)
			{
				*Data = UART.Data;
			}
			else
			{
				return_value = UART_EN_BUSY_TimeOut;
			}
			R_Flag = Available;
		}
		else
		{
			return_value = UART_EN_InvalidPointer;
		}
	}
	else
	{
		return_value = UART_EN_BUSY_Recieve;
	}
	return return_value;
}
UART_Error_t		Uart_ReceiveAsynch		(uint8_t* Data)
{
	UART_Error_t return_value = UART_EN_valid;
	if(UART_EN_Buffer_Empty == DeQueue(&R_Buffer, Data))
	{
		UART.Enables.rcivCompIntrrpt = ENABLE;
		return_value = UART_EN_Buffer_Empty;
	}
	else{/*MISRA C*/}
	return return_value;
}
UART_Error_t      Uart_ReceiveStringPooling	(uint8_t* Data, uint8_t size, uint8_t term)
{
	UART_Error_t return_value = UART_EN_END_BY_SIZE;
	uint8_t index = 0;
	if(Data != NULL)
	{
		while(index < size)
		{
			while(UART_EN_BUSY_TimeOut == Uart_ReceivePooling(&Data[index]));
			if(Data[index] == term)
			{
				Data[index] = '\0';
				return_value = UART_EN_END_BY_TERM;
				break;
			}
			else
			{
				index++;
			}
		}
	}
	else
	{
		return_value = UART_EN_InvalidPointer;
	}
	return return_value;
}
UART_Error_t		Uart_ReceiveStringAsynch(uint8_t* Data, uint8_t size)
{
	UART_Error_t return_value = UART_EN_valid;
	uint8_t index = 0;
	for(index = 0; (index < size) && (Data[index] != '\r'); index++)
	{
		if(UART_EN_Buffer_Empty == DeQueue(&R_Buffer, &Data[index]))
		{
			UART.Enables.rcivCompIntrrpt = ENABLE;
			return_value = UART_EN_Buffer_Empty;
			break;
		}
		else{/*MISRA C*/}
	}
	return return_value;
}
ISR(USART_RXC_vect)
{
	UART.Flags.rciv_cmplt = ENABLE;
	if(R_Flag == Available)
	{
		uint8_t Data = UART.Data;
		if(UART_EN_Buffer_Full == EnQueue(&R_Buffer, Data))
		{
			UART.Enables.rcivCompIntrrpt = DISABLE;
		}
		else{/*MISRA C*/}
	}
	else{/*MISRA C*/}
}