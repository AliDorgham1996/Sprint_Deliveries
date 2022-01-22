#include "Button.h"
#include "LED.h"
#include "Timer.h"
#include "avr/interrupt.h"

void Task_1(void)
{
	BTN_State_t BTNState = BTN_NotPressed;
	BUTTON_init(Button1);
	LED_init(LED_2);
	sei();
	while(1)
	{
		BUTTON_IsPressed(Button1, &BTNState);
		if(BTNState == BTN_IS_Pressed)
		{
			do
			{
				BUTTON_IsPressed(Button1, &BTNState);
			} while(BTNState == BTN_IS_Pressed);
			LED_Toggle(LED_2);
		}
		else{/*MISRA C*/}
	}
}