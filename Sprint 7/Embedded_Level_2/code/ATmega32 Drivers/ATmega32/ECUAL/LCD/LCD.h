#ifndef LCD_H_
#define LCD_H_


#include "LCD_Cfg.h"


Flag_t    LCD_init                (void);
Flag_t    LCD_Clear               (void);
	      					      
uint8_t   LCD_Display_Char        (uint8_t uint8_tChar);
uint8_t   LCD_Display_String      (uint8_t* puint8_tString);
uint8_t   LCD_Display_Num         (int32_t s32Num);
					      
uint8_t   LCD_Display_CharXY      (LCD_Row_t row, LCD_Col_t col, uint8_t uint8_tChar);
uint8_t   LCD_Display_StringXY    (LCD_Row_t row, LCD_Col_t col, uint8_t* puint8_tString);
uint8_t   LCD_Display_NumXY       (LCD_Row_t row, LCD_Col_t col, int32_t s32Num);




#endif /* LCD_H_ */