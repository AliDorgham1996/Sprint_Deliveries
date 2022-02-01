#include "../MCAL/UART/UART.h"
#include "../MCAL/UART/UART_Private.h"
#include "../Library/Configurations.h"
#include "../Library/Constants.h"
#include "../Library/Bit_Math.h"
#include <avr/interrupt.h>
#include <string.h>

typedef enum{Available, Busy, Asynch}Flag_t;
	
_S _V Queue_t R_Buffer= {.size= UART_R_Buffer_Size};
_S _V Queue_t T_Buffer= {.size= UART_T_Buffer_Size};
_S _V Flag_t  T_Flag = Available;

/* Standard : 8N1  */
UART_Error_t		Uart_init		        (uint32_t BaudRate)
{
	UART_Error_t return_value = UART_EN_valid;
	
	return_value |= Queue_Init(&R_Buffer);
	return_value |= Queue_Init(&T_Buffer);
	
	if(return_value == UART_EN_valid)
	{
		/* BR = (clock/(16*baud)) - 1*/
		if(BaudRate != 0)
		{
			uint8_t UCSRC_MASK = DISABLE;
			uint32_t BRValue   = (F_CPU/(2UL*(4*(UART_SPEED+1))*BaudRate)) - 1;
			
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
	if(Data != NULL)
	{
		if(T_Flag == Available)
		{
			T_Flag = Asynch;
			while((return_value == UART_EN_valid) && (Data[index] != '\0'))
			{
				return_value = (UART_Error_t)EnQueue(&T_Buffer, Data[index++]);
			}
			
			if(return_value == UART_EN_valid)
			{
				UART.Enables.udrEmptyIntrrpt = ENABLE;
			}
			else{/*MISRA C*/}
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
	if(T_Flag == Asynch)
	{
		uint8_t Data = '\0';
		UART_Error_t local_return = UART_EN_valid;
		local_return = DeQueue(&T_Buffer, &Data);
		if(local_return == UART_EN_Buffer_Empty)
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
	if(Data != NULL)
	{
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
	}
	else
	{
		return_value = UART_EN_InvalidPointer;
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
ISR(USART_RXC_vect)
{
	UART.Flags.rciv_cmplt = ENABLE;
	if(UART_EN_Buffer_Full ==EnQueue(&R_Buffer, UART.Data))
	{
		UART.Enables.rcivCompIntrrpt = DISABLE;
	}
	else{/*MISRA C*/}
}