#include "LCD.h"
#include "LCD_Private.h"
#include "Constants.h"
#include "Timer.h"
#include "Registers.h"
#include "Delays.h"
#include <util/delay.h>


/* Static Global Variables */
_V _S uint8_t LCD_Flag         = Flag_Busy;
_V _S uint8_t LCD_Local_Flag   = Flag_Available;
_V _S uint8_t LCD_Event_Group  = LCD_EG_Init;

/* Static Functions */
_S uint8_t	LCD_GoToXY				(LCD_Row_t row, LCD_Col_t col);
_S uint8_t	LCD_sendData			(uint8_t byData);
_S uint8_t	LCD_sendInst			(uint8_t byInst);
_S void		LCD_Latch				(void);
_S void		Update_LocalFlag		(void);
_S void     Release_Flag            (void);
_S void     LCD_init_State          (void);

/**************************************************
* LCD APIs
***************************************************/

Flag_t		LCD_init				(void)
{
	if(LCD_Local_Flag != LCD_END_INIT)
	{
		switch(LCD_Local_Flag)
		{
			case Flag_Available:
			{
				LCD_init_State();
			}break;
			case Flag_Pending:
			{
				//wait until flag become available
			}break;
			default:{/*MISRA C*/}break;
		}
	}
	else
	{
		return LCD_DISPLAY_OK;	
	}
	return LCD_DISPLAY_NOK;
}
Flag_t		LCD_Clear				(void)
{
	if(LCD_Flag == Flag_Available)
	{
		if(TMR_EN_valid_inti == Timer_SetTrigger(Timer_2, Release_Flag, LCD_TIME_CLEAR_MS))
		{
			LCD_sendInst(LCD_CMD_CLEAR);
			LCD_Flag = Flag_Busy;
		}
	}
	else{/*MISRA C*/}
	return LCD_Flag;
}
uint8_t		LCD_Display_Char		(uint8_t uint8_tChar)
{
	return LCD_sendData(uint8_tChar);
}
uint8_t		LCD_Display_String		(uint8_t* puint8_tString)
{
	uint8_t S_index = 0;
	while(puint8_tString[S_index])
	{
		if(LCD_DISPLAY_OK == LCD_Display_Char(puint8_tString[S_index]))
		{
			S_index++;	
		}
		else
		{
			return LCD_DISPLAY_NOK;
		}
	}
	return LCD_DISPLAY_OK;
}
uint8_t		LCD_Display_Num			(int32_t int32_tNum)
{
	uint8_t buffer [20] = {0};
	ltoa(int32_tNum, (char*)buffer, 10);
	return LCD_Display_String(buffer);
}
uint8_t     LCD_Display_CharXY      (LCD_Row_t row, LCD_Col_t col, uint8_t uint8_tChar)
{
	if(LCD_DISPLAY_OK == LCD_GoToXY(row,col))
	{
		return LCD_sendData(uint8_tChar);
	}
	return LCD_DISPLAY_NOK;
}
uint8_t     LCD_Display_StringXY    (LCD_Row_t row, LCD_Col_t col, uint8_t* puint8_tString)
{
	if(LCD_DISPLAY_OK == LCD_GoToXY(row,col))
	{
		return LCD_Display_String(puint8_tString);
	}
	return LCD_DISPLAY_NOK;
}
uint8_t     LCD_Display_NumXY       (LCD_Row_t row, LCD_Col_t col, int32_t int32_tNum)
{
	if(LCD_DISPLAY_OK == LCD_GoToXY(row,col))
	{
		return LCD_Display_Num(int32_tNum);
	}
	return LCD_DISPLAY_NOK;
}

/*********************************************************
* Static Functions
*********************************************************/

_S uint8_t  LCD_GoToXY				(LCD_Row_t row, LCD_Col_t col)
{
	if (row == 1)
	{
		return LCD_sendInst((0x80) + col);
	}
	else if (row == 2)
	{
		return LCD_sendInst((0xc0) + col);
	}
	else if (row == 3)
	{
		return LCD_sendInst((0x90) + col);
	}
	else if (row == 4)
	{
		return LCD_sendInst((0xd0) + col);
	}
	return LCD_DISPLAY_NOK;
}
_S void		LCD_Latch				(void)
{
	Dio_ChannelWrite(LCD_EN_PIN, DIO_EN_W_High);
	Dio_ChannelWrite(LCD_EN_PIN, DIO_EN_W_Low);
}
_S uint8_t	LCD_sendInst			(uint8_t Inst)
{
	if(LCD_Flag == Flag_Available)
	{
		Dio_ChannelWrite(LCD_RS_PIN, DIO_EN_W_Low);
		Dio_ChannelWrite(LCD_RW_PIN, DIO_EN_W_Low);
		/* upload most 4 bits and then latch */
		LCD_DATA_REG.HN = (Inst>>4);
		LCD_Latch();
		/* upload least 4 bits and then latch */
		LCD_DATA_REG.HN = Inst;
		LCD_Latch();
		Delay_Us(40);	
		return LCD_DISPLAY_OK;
	}
	return LCD_DISPLAY_NOK;
}
_S uint8_t	LCD_sendData			(uint8_t Data)
{
	if(LCD_Flag == Flag_Available)
	{
		Dio_ChannelWrite(LCD_RS_PIN, DIO_EN_W_High);
		Dio_ChannelWrite(LCD_RW_PIN, DIO_EN_W_Low);
		/* upload most 4 bits and then latch */
		LCD_DATA_REG.HN = (Data>>4);
		LCD_Latch();
		/* upload least 4 bits and then latch */
		LCD_DATA_REG.HN = Data;
		LCD_Latch();
		Delay_Us(40);	
		return LCD_DISPLAY_OK;
	}
	return LCD_DISPLAY_NOK;
}
_S void     Release_Flag            (void)
{
	LCD_Flag = Flag_Available;
}
_S void		Update_LocalFlag		(void)
{
	LCD_Local_Flag = Flag_Available;
}
_S void     LCD_init_State          (void)
{
	LCD_Local_Flag = Flag_Pending;
	switch(LCD_Event_Group)
	{
		case LCD_EG_Init:
		{
			Dio_GroupMode(LCD_DATA_PORT, LCD_DATA_MSK, DIO_EN_M_Output);
			Dio_ChannelMode(LCD_RW_PIN, DIO_EN_M_Output);
			Dio_ChannelMode(LCD_RS_PIN, DIO_EN_M_Output);
			Dio_ChannelMode(LCD_EN_PIN, DIO_EN_M_Output);
			Timer_SetTrigger(Timer_2, Update_LocalFlag, LCD_TIME_INIT_MS);
			LCD_Event_Group = LCD_EG_Mode;
		}break;
		case LCD_EG_Mode:
		{
			LCD_Flag = Flag_Available;
			LCD_sendInst(LCD_CMD_FUN_SET_4BIT);
			LCD_Flag = Flag_Busy;
			Timer_SetTrigger(Timer_2, Update_LocalFlag, LCD_TIME_Instruction_MS);
			LCD_Event_Group = LCD_EG_CFG;
		}break;
		case LCD_EG_CFG:
		{
			LCD_Flag = Flag_Available;
			LCD_sendInst(LCD_CMD_CFG);
			LCD_Flag = Flag_Busy;
			Timer_SetTrigger(Timer_2, Update_LocalFlag, LCD_TIME_Instruction_MS);
			LCD_Event_Group = LCD_EG_DISP;
		}break;
		case LCD_EG_DISP:
		{
			LCD_Flag = Flag_Available;
			LCD_sendInst(LCD_CMD_DISP_ON);
			LCD_Flag = Flag_Busy;
			Timer_SetTrigger(Timer_2, Update_LocalFlag, LCD_TIME_Instruction_MS);
			LCD_Event_Group = LCD_EG_CLEAR;
		}break;
		case LCD_EG_CLEAR:
		{
			LCD_Flag = Flag_Available;
			LCD_sendInst(LCD_CMD_CLEAR);
			LCD_Flag = Flag_Busy;
			Timer_SetTrigger(Timer_2, Update_LocalFlag, LCD_TIME_CLEAR_MS);
			LCD_Event_Group = LCD_END_INIT;
		}break;
		case LCD_END_INIT:
		{
			// end of initialization
			LCD_Flag        = Flag_Available;
			LCD_Local_Flag  = LCD_END_INIT;
		}break;
	}
}
