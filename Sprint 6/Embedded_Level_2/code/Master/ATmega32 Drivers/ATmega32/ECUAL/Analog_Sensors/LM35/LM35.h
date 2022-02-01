#ifndef LM35_H_
#define LM35_H_

#include "../MCAL/ADC/ADC.h"

#define  LM35_CHANNEL  ADC_CH0
#define  LM35_V_Ref    5U

typedef enum
{
	LM35_EN_valid,
	LM35_EN_InvalidValue,
	LM35_EN_InvalidPointer
}LM35_Error_t;

void            LM35_Init   (void);
LM35_Error_t    LM35_Read   (uint8_t* Data);


#endif /* LM35_H_ */