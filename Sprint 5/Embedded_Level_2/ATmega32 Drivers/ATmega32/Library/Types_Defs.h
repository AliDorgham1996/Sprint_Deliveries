#ifndef TYPES_DEFS_H
#define TYPES_DEFS_H

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "../Library/PrivateMacros.h"
#include "../Library/Constants.h"



typedef void(*V_CallBack_V_t)(void);

/***************************
* DIO
***************************/
typedef struct
{
	union
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
	};
}_V PORT_t;

typedef PORT_t*   PORT_ptr_t;

#ifndef dio
#define dio(address)         (MMIO_(PORT_ptr_t,address))
#endif
/***************************/


#endif /* TYPES_DEFS_H */