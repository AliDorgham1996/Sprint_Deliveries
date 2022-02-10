#include "LCD.h"
#include "Keypad.h"
#include "Registers.h"
#include <avr/interrupt.h>



int main(void)
{
	uint8_t key = KEYPAD_INVALID_KEY;
	uint8_t Flag_String = 0;
	Keypad_Init();
	sei();
	while(1)
	{
		if(Flag_String == 0)
		{
			if(LCD_DISPLAY_OK == LCD_init())
			{
				if(LCD_DISPLAY_OK == LCD_Display_StringXY(LCD_EN_ROW_1, LCD_EN_COL_1, (uint8_t*)"Sprint 7"))
				{
					Flag_String = 1;
				}
			}
		}
		
		Keypad_GetKey(&key);
		if(KEYPAD_INVALID_KEY != key)
		{
			LCD_Display_CharXY(LCD_EN_ROW_2, LCD_EN_COL_1, key);
		}
	}
}