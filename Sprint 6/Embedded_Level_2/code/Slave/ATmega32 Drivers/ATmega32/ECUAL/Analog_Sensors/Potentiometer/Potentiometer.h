#ifndef POTENTIOMETER_H_
#define POTENTIOMETER_H_


#include "../MCAL/ADC/ADC.h"

#define  POT_CHANNEL   ADC_CH0

typedef enum
{
	POT_EN_valid,
	POT_EN_InvalidValue,
	POT_EN_InvalidPointer
}POT_Error_t;

void		   Potentiometer_Init   (void);
POT_Error_t    Potentiometer_Read   (uint8_t* Data);




#endif /* POTENTIOMETER_H_ */