#ifndef ADC_PRIVATE_H_
#define ADC_PRIVATE_H_

#include <stdint.h>
#include "../Library/PrivateMacros.h"

typedef struct{
	uint8_t prescalar	:3;
	uint8_t interrupt   :1;
	uint8_t flag    	:1;
	uint8_t auto_trig	:1;
	uint8_t start_conv	:1;
	uint8_t ADC_enable	:1;
}ADCSRA_t;

typedef struct{
	uint8_t channel		:5;
	uint8_t adjust_left	:1;
	uint8_t ADC_Vref	:2;
}ADMUX_t;

typedef struct
{
	uint16_t   Data;
	ADCSRA_t   Control;
	ADMUX_t    Selections;
}ADC_t;

typedef ADC_t*  ADC_CFG_t;

#define ADC   adc_(ADC_CFG_t)

#endif /* ADC_PRIVATE_H_ */