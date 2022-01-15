#include "LED.h"
#include "Timer.h"
#include "avr/interrupt.h"

void Toggle_Led(void);

void Task_3(void)
{
	LED_init(LED_0);
	Timer_SetTrigger(Timer0, Toggle_Led, 500, 300);
	sei();
	while(1);	
}

void Toggle_Led(void)
{
	LED_Toggle(LED_0);
}