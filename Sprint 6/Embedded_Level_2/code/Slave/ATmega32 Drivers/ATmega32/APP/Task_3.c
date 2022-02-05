#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/Keypad/keypad.h"
#include "../Library/System_Delays/Delays.h"

void Task_3(void)
{
	uint8_t key = 0;
	
	LCD_init();
	Keypad_Init();
	LCD_Display_StringXY(LCD_EN_ROW_1, LCD_EN_COL_1, (uint8_t*)"Keypad Test");
	
	while(1)
	{
		key = Keypad_GetKey();
		if(key != KEYPAD_INVALID_KEY)
		{
			LCD_Display_CharXY(LCD_EN_ROW_2, LCD_EN_COL_1, key);
		}
		//Delay_Ms(100);
	}
}
