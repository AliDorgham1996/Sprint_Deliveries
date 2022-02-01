#ifndef UART_CFG_H_
#define UART_CFG_H_

#include "../Library/Types_Defs.h"
#include "../Services/Circular_Buffer/Circular_Buffer.h"

#define UART_R_Buffer_Size   10U
#define UART_T_Buffer_Size   10U
#define UART_TIME_OUT        5000UL

typedef union
{
	enum
	{
		UART_BR_2400=416,
		UART_BR_4800=207,
		UART_BR_9600=103,
		UART_BR_14_4K=68,
		UART_BR_19_2K=51,
		UART_BR_28_8K=34,
		UART_BR_38_4K=25,
		UART_BR_57_6K=16,
		UART_BR_76_8K=12,
		UART_BR_115_2K=8,
		UART_BR_230_4K=3,
		UART_BR_250K=3,
		UART_BR_500K=1,
		UART_BR_1M=0
	}UART_BaudRate_UX2_F_CPU_8MHz_t;
}UART_BaudRate_t;

typedef enum
{
	UART_EN_SPEED_UX1,
	UART_EN_SPEED_UX2
}UART_UxSpeed_t;
#define  UART_SPEED             UART_EN_SPEED_UX1

typedef enum
{
	UART_EN_5_Bit,
	UART_EN_6_Bit,
	UART_EN_7_Bit,
	UART_EN_8_Bit//,
	//UART_EN_9_Bit=7
}UART_Size_t;
#define  UART_SIZE            UART_EN_8_Bit

typedef enum
{
	UART_EN_Parity_Disable,
	UART_EN_Parity_Even=2,
	UART_EN_Parity_Odd
}UART_Parity_t;
#define  UART_PARITY           UART_EN_Parity_Disable

typedef enum
{
	UART_EN_Stop_1_Bit,
	UART_EN_Stop_2_Bit
}UART_Stop_t;
#define  UART_STOP             UART_EN_Stop_1_Bit

typedef enum
{
	UART_EN_Asynchronous,
	UART_EN_Synchronous
}UART_Mode_t;
#define  UART_SYNCHRONOUS      UART_EN_Asynchronous


typedef enum
{
	UART_EN_T_Rise_R_Fail,
	UART_EN_R_Rise_T_Fail
}UART_Polarity_t;
#define  UART_POLARITY         UART_EN_T_Rise_R_Fail

typedef struct
{
	UART_BaudRate_t   Baud;
	UART_Size_t       Size;
	UART_Parity_t     Parity;
	UART_Stop_t       Stop;
}UART_CFG_t;

#endif /* UART_CFG_H_ */