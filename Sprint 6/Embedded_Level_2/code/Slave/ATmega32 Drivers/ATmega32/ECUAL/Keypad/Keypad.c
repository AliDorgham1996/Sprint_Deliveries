#include "../ECUAL/Keypad/Keypad_Cfg.h"
#include "../Library/Constants.h"
#include "../MCAL/DIO/Dio.h"

_E uint8_t Keypad_keys[KEYPAD_ROW][KEYPAD_COL];

void	   Keypad_Init       (void)
{
	/* Rows Out */
	Dio_GroupMode(KEY_ROWS_PORT, KEY_ROWS_MSK, DIO_EN_M_Output);
	/* Default deactivated */
	Dio_GroupWrite(KEY_ROWS_PORT, KEY_ROWS_MSK, DIO_EN_W_High);
	/* Cols Input */
	Dio_GroupMode(KEY_COLS_PORT, KEY_COLS_MSK, DIO_EN_M_Input);
	/* Cols Pull-up */
	Dio_GroupWrite(KEY_COLS_PORT, KEY_COLS_MSK, DIO_EN_W_High);
}

uint8_t		Keypad_GetKey    (void)
{
	uint8_t row = 0;
	uint8_t col = 0;
	uint8_t pin = 0;
	for (row = 0; row < KEYPAD_ROW; row++)
	{
		Dio_GroupWrite(KEY_ROWS_PORT, (KEY_ROWS_MSK)&(1<<(row+KEY_ROWS_START)), DIO_EN_W_Low);
		for (col = 0; col < KEYPAD_COL; col++)
		{
			Dio_GroupRead(KEY_COLS_PORT, (KEY_COLS_MSK)&(1<<(col+KEY_COLS_START)), &pin);
			if(pin == 0)
			{
				do //neglect long press 
				{
					Dio_GroupRead(KEY_COLS_PORT, (KEY_COLS_MSK)&(1<<(col+KEY_COLS_START)), &pin);
				} while (pin == 0);
				return Keypad_keys[row][col];
			}
			else{/* MISRA C */}
		}
		Dio_GroupWrite(KEY_ROWS_PORT, (KEY_ROWS_MSK)&(1<<(row+KEY_ROWS_START)), DIO_EN_W_High);
	}
	return KEYPAD_INVALID_KEY;
}