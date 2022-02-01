#include "../MCAL/ADC/ADC.h"
#include "../MCAL/ADC/ADC_Private.h"

void      	ADC_Init	(ADC_Presc_t Prescaler, ADC_Vref_t V_Ref)
{
	ADC.Selections.ADC_Vref   = V_Ref;
	ADC.Control.prescalar     = Prescaler;
	ADC.Control.ADC_enable    = 1;
}
ADC_Error_t  	ADC_Read    (ADC_Channel_t Channel, uint16_t* Data)
{
	ADC_Error_t return_value = ADC_EN_valid;
	if(Data != NULL)
	{
		uint32_t timeout = 0;
		ADC.Selections.channel = Channel;
		ADC.Control.start_conv = ENABLE;
		while((ADC.Control.flag == 0) && (timeout <= ADC_TIMEOUT))
		{
			timeout++;
		}
		
		if(ADC.Control.flag == 0)
		{
			*Data = ADC.Data;
		}
		else
		{
			return_value = ADC_EN_InvalidTimeOut;
		}
	}
	else
	{
		return_value = ADC_EN_InvalidPointer;
	}
	return return_value;
}
