#include "Keypad.h"
#include "Types_Defs.h"
#include "Constants.h"
#include "Dio.h"
#include "Timer.h"
#include "Registers.h"

/* Extern Global Variables */
_E	  uint8_t Keypad_keys[KEYPAD_ROW][KEYPAD_COL];

/* Static Global Variables */
_V _S uint8_t Key_Flag    = Flag_Available; 

/* Static Functions */
_S void		Update_Flag		(void);
_S void		GetKey			(uint8_t* Key);

/**************************************************
* KeyPad APIs 
***************************************************/
void		Keypad_Init     (void)
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
Flag_t		Keypad_GetKey   (uint8_t* Key)
{
	_S uint8_t PreviousKey = KEYPAD_INVALID_KEY;
	_S uint8_t Local_Key   = KEYPAD_INVALID_KEY;
	switch(Key_Flag)
	{
		case Flag_Init:
		{
			//wait until flag become pending
		}break;
		case Flag_Available:
		{
			if(TMR_EN_valid_inti == Timer_SetTrigger(Timer_0, Update_Flag, KEYPAD_DEBOUNCING_MS))
			{
				GetKey(&PreviousKey);
				if(PreviousKey != KEYPAD_INVALID_KEY)
				{
					Key_Flag = Flag_Init;
				}
				else
				{
					Key_Flag = Flag_Busy;
				}
			}
			else
			{
				Key_Flag = Flag_Busy;
			}	
		}break;
		case Flag_Pending:
		{
			GetKey(&Local_Key);
			if(Local_Key == PreviousKey)
			{
				if(PreviousKey != KEYPAD_INVALID_KEY)
				{
					*Key = Local_Key;
					Local_Key = PreviousKey = KEYPAD_INVALID_KEY;
					Key_Flag = Flag_Available;
				}
				else
				{
					Key_Flag = Flag_Busy;
				}
			}
			else
			{
				Key_Flag = Flag_Busy;
			}		
		}break;
		case Flag_Busy:
		{
			if(Flag_Available == Timer_Status(Timer_0))
			{
				Key_Flag = Flag_Available;
			}
			else{/*MISRA C*/}	
		}break;
	}
	return Key_Flag;
}

/*********************************************************
* Static Functions
*********************************************************/

_S void		Update_Flag		(void)
{
	Key_Flag = Flag_Pending;
}
_S void		GetKey			(uint8_t* Key)
{
	uint8_t row = 0;
	uint8_t col = 0;
	uint8_t pin = 0;
	uint8_t Local_Flag = 0;
	*Key = KEYPAD_INVALID_KEY;
	for (row = 0; row < KEYPAD_ROW; row++)
	{
		Dio_GroupWrite(KEY_ROWS_PORT, (KEY_ROWS_MSK)&(1<<(row+KEY_ROWS_START)), DIO_EN_W_Low);
		for (col = 0; col < KEYPAD_COL; col++)
		{
			Dio_GroupRead(KEY_COLS_PORT, (KEY_COLS_MSK)&(1<<(col+KEY_COLS_START)), &pin);
			if(pin == 0)
			{
				*Key = Keypad_keys[row][col];
				Local_Flag = 1;
				break;
			}
			else{/* MISRA C */}
		}
		Dio_GroupWrite(KEY_ROWS_PORT, (KEY_ROWS_MSK)&(1<<(row+KEY_ROWS_START)), DIO_EN_W_High);
		if(Local_Flag == 1)
		{
			break;
		}
		else{/*MISRA C*/}
	}
}