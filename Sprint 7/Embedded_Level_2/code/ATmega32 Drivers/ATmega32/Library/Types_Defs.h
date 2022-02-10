#ifndef TYPES_DEFS_H
#define TYPES_DEFS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include "../Library/PrivateMacros.h"
#include "../Library/Constants.h"

typedef enum
{
	Flag_Available,
	Flag_Pending,
	Flag_Busy,
	Flag_Init
}Flag_t;

typedef enum
{
	False,
	True
}Bool_t;

typedef void(*V_CallBack_V_t)(void);

/***************************
* DIO
***************************/
typedef struct
{
	uint8_t Carry_Flag;//1
	uint8_t Zero_Flag;//2
	uint8_t Negative_Flag;//3
	uint8_t OverFlow;//4
	uint8_t Sign_Bit;//5
	uint8_t Half_Carry_Flag;//6
	uint8_t Copy_Storage;//7
	uint8_t Interrupt_Enable;//8
}SREG_t;

typedef SREG_t* SREGPRT_t;

/***************************
* DIO
***************************/
typedef union
{
	struct
	{
		uint8_t pin0 :1;
		uint8_t pin1 :1;
		uint8_t pin2 :1;
		uint8_t pin3 :1;
		uint8_t pin4 :1;
		uint8_t pin5 :1;
		uint8_t pin6 :1;
		uint8_t pin7 :1;
	};
	uint8_t Register;
}_V PORT_t;

typedef PORT_t*   PORT_ptr_t;

#ifndef io_
#define io_(address)            IO_(PORT_ptr_t,address)
#endif
/***************************/


#endif /* TYPES_DEFS_H */