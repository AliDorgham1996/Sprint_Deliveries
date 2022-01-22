#include "LED.h"
#include "Timer.h"
#include "avr/interrupt.h"

void Task_2(void)
{
	LED_init(LED_1);
	sei();
	while(1)
	{
		LED_Toggle(LED_1);
		Timer_Delay_MS(Timer0, 500);
		LED_Toggle(LED_1);
		Timer_Delay_MS(Timer0, 300);
	}
}