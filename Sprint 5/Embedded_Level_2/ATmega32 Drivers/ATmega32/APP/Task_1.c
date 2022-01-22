#include "../ECUAL/LCD/LCD.h"

void Task_1(void)
{
	LCD_init();
	LCD_Display_StringXY(LCD_EN_ROW_1, LCD_EN_COL_1, (uint8_t*)"Welcome Sprints");
	while(1);
}