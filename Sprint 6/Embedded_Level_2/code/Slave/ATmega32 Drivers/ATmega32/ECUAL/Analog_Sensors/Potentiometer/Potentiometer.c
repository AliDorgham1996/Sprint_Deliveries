#include "../ECUAL/Analog_Sensors/Potentiometer/Potentiometer.h"


void       Potentiometer_Init   (void)
{
	ADC_Init(ADC_PRESC_128, ADC_VREF_External);
}
POT_Error_t    Potentiometer_Read   (uint8_t* Data)
{
	POT_Error_t return_value = POT_EN_valid;
	if(Data != NULL)
	{
		float Percentage = 0;
		if(ADC_EN_valid == ADC_Read(POT_CHANNEL, &Percentage))
		{
			Percentage *= 100;
			Percentage /= 1024;
			*Data = (uint8_t)Percentage;
		}
		else
		{
			return_value = POT_EN_InvalidValue;
		}
	}
	else
	{
		return_value = POT_EN_InvalidPointer;
	}
	return return_value;
}