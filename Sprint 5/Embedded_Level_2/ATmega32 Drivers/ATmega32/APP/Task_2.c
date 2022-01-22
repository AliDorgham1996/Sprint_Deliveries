#include "../ECUAL/LCD/LCD.h"
#include "../ECUAL/Analog_Sensors/LM35/LM35.h"
#include "../Library/System_Delays/Delays.h"

void Task_2(void)
{
	uint16_t Temperature = 0;
	
	LCD_init();
	
	LM35_Init();
	LCD_Display_StringXY(LCD_EN_ROW_1, LCD_EN_COL_1, (uint8_t*)"LM35 Values");
	LCD_Display_CharXY(LCD_EN_ROW_2, LCD_EN_COL_5,'C');
	
	while(1)
	{
		Delay_Ms(500);
		Temperature = LM35_Read();
		LCD_Display_StringXY(LCD_EN_ROW_2, LCD_EN_COL_1, (uint8_t*)"   ");
		LCD_Display_NumXY(LCD_EN_ROW_2, LCD_EN_COL_1, Temperature);
	}
}