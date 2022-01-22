#include "../ECUAL/Keypad/Keypad_Cfg.h"

extern uint8_t Keypad_keys[KEYPAD_ROW][KEYPAD_COL];

void	   Keypad_Init       (void)
{
	/* Rows Out */
	SetMaskBits(KEY_ROWS_DDR, KEY_ROWS_MSK);
	/* Default deactivated */
	SetMaskBits(KEY_ROWS_PORT, KEY_ROWS_MSK);
	/* Cols Input */
	ClearMaskBits(KEY_COLS_DDR, KEY_COLS_MSK);
	/* Cols Pull-up */
	SetMaskBits(KEY_COLS_PORT, KEY_COLS_MSK);
}

uint8_t		Keypad_GetKey    (void)
{
	uint8_t row = 0;
	uint8_t col = 0;
	for (row = 0; row < KEYPAD_ROW; row++)
	{
		ClearBit(KEY_ROWS_PORT, (row+KEY_ROWS_START));
		for (col = 0; col < KEYPAD_COL; col++)
		{
			if(GetBit(KEY_COLS_PINR, (col+KEY_COLS_START)) == 0)
			{
				while(GetBit(KEY_COLS_PINR, (col+KEY_COLS_START)) == 0);
				return Keypad_keys[row][col];
			}
			else{/* MISRA C */}
		}
		SetBit(KEY_ROWS_PORT, (row+KEY_ROWS_START));
	}
	return KEYPAD_INVALID_KEY;
}