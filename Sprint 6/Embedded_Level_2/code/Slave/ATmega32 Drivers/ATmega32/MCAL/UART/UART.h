#ifndef UART_H_
#define UART_H_

#include "../MCAL/UART/UART_Cfg.h"

typedef enum
{
	UART_EN_valid        = Queue_EN_valid,
	UART_EN_Buffer_Full  = Queue_EN_Full,
	UART_EN_Buffer_Empty = Queue_EN_Empty,
	UART_EN_InvalidQueue = Queue_EN_InvalidPointer,
	UART_EN_InvalidPointer,
	UART_EN_InvalidBaudRate,
	UART_EN_BUSY_Recieve,
	UART_EN_BUSY_Transmit,
	UART_EN_BUSY_TimeOut,
	UART_EN_END_BY_SIZE,
	UART_EN_END_BY_TERM	
}UART_Error_t;

/*
 *initialize
 */
UART_Error_t		Uart_init					(uint32_t BaudRate);//tested
/*
 *sending
 */
UART_Error_t		Uart_SendPooling			(uint8_t  Data);//tested
UART_Error_t		Uart_SendStringPooling		(uint8_t* Data);//tested
UART_Error_t		Uart_SendStringAsynch		(uint8_t* Data);//tested
/*
 *receiving
 */
UART_Error_t		Uart_ReceivePooling			(uint8_t* Data);//tested
UART_Error_t		Uart_ReceiveAsynch			(uint8_t* Data);//tested
UART_Error_t		Uart_ReceiveStringAsynch	(uint8_t* Data, uint8_t size);//tested
UART_Error_t        Uart_ReceiveStringPooling	(uint8_t* Data, uint8_t size, uint8_t term);//tested



#endif /* UART_H_ */