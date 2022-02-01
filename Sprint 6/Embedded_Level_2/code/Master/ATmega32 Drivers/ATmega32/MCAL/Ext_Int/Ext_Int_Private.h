#ifndef EXT_INT_PRIVATE_H_
#define EXT_INT_PRIVATE_H_

#include <stdint.h>
#include "../Library/PrivateMacros.h"

typedef struct
{
	uint16_t         :6;
	uint16_t Sense   :1;
}ExtI_MCSR_2_t;

typedef struct
{
	uint16_t         :10;
	uint16_t Sense   :2;
}ExtI_MCSR_1_t;

typedef struct
{
	uint16_t         :8;
	uint16_t Sense   :2;
}ExtI_MCSR_0_t;

typedef union
{
	ExtI_MCSR_2_t  INT_2;
	ExtI_MCSR_1_t  INT_1;
	ExtI_MCSR_0_t  INT_0;
}ExtI_MCSR_t;

typedef struct
{
	uint8_t         :5;
	uint8_t INT_2   :1;
	uint8_t INT_0   :1;
	uint8_t INT_1   :1;
}ExtI_GIR_t;

typedef struct
{
	ExtI_MCSR_t Control;
	uint8_t         :8;
	uint8_t         :8;
	uint8_t         :8;
	uint8_t         :8;
	ExtI_GIR_t    Flag;
	ExtI_GIR_t  Enable;
}ExtInt_CFG_t;

typedef ExtInt_CFG_t*  ExtI_CFG_t;

#define EXTI     exti_(ExtI_CFG_t)

#endif /* EXT_INT_PRIVATE_H_ */