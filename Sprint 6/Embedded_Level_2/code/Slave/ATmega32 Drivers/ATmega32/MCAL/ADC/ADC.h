#ifndef ADC_H_
#define ADC_H_


#include "ADC_Cfg.h"

typedef enum
{
	ADC_EN_valid,
	ADC_EN_InvalidTimeOut,
	ADC_EN_InvalidPointer
}ADC_Error_t;

void      	    ADC_Init	(ADC_Presc_t Prescaler, ADC_Vref_t V_Ref);
ADC_Error_t  	ADC_Read    (ADC_Channel_t Channel, uint16_t* Data);

#endif /* ADC_H_ */