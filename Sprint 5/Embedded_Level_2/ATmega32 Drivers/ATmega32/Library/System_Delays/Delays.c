#include "../Library/System_Delays/Delays.h"
#include "../Library/Configurations.h"
#include <util/delay.h>


void Delay_Ms(uint64_t Delay)
{
	while (0 < Delay)
	{
		_delay_ms(1);
		--Delay;
	}
}

void Delay_Us(uint64_t Delay)
{
	while (0 < Delay)
	{
		_delay_us(1);
		--Delay;
	}
}