#include "../ECUAL/Analog_Sensors/LM35/LM35.h"

void       LM35_Init   (void)
{
	ADC_Init(ADC_PRESC_128, ADC_VREF_VCC_INT);
}

LM35_Error_t    LM35_Read   (uint8_t* Data)
{
	LM35_Error_t return_value = LM35_EN_valid;
	if(Data != NULL)
	{
		uint16_t Temperature = 0;
		if(ADC_EN_valid == ADC_Read(LM35_CHANNEL, &Temperature))
		{
			Temperature *= 0.488;
			*Data = (uint8_t)Temperature;
		}
		else
		{
			return_value = LM35_EN_InvalidValue;
		}
	}
	else
	{
		return_value = LM35_EN_InvalidPointer;
	}
	return return_value;
}