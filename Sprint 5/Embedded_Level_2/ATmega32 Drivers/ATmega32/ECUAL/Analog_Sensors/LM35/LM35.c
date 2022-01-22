#include "../ECUAL/Analog_Sensors/LM35/LM35.h"

void       LM35_Init   (void)
{
	ADC_Init(ADC_PRESC_128, ADC_VREF_VCC_INT);
}

uint16_t   LM35_Read   (void)
{
	uint16_t Temperature = ADC_Read(LM35_CHANNEL);                  
	Temperature *= 0.488;
	return Temperature;
}