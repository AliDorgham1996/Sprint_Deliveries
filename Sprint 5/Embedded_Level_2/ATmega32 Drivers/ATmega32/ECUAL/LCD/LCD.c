#include "LCD.h"
#include "LCD_Private.h"
#include "../Library/System_Delays/Delays.h"

static void LCD_GoToXY(LCD_Row_t row, LCD_Col_t col);
static void LCD_sendData(uint8_t byData);
static void LCD_sendInst(uint8_t byInst);
static void LCD_Latch(void);

static void LCD_Latch(void)
{
	Dio_ChannelWrite(LCD_EN_PIN, DIO_EN_W_High);
	Dio_ChannelWrite(LCD_EN_PIN, DIO_EN_W_Low);
}

static void LCD_sendInst(uint8_t Inst)
{
	Dio_ChannelWrite(LCD_RS_PIN, DIO_EN_W_Low);
	Dio_ChannelWrite(LCD_RW_PIN, DIO_EN_W_Low);
	/* upload most 4 bits and then latch */
	LCD_DATA_REG.HN = (Inst>>4);
	LCD_Latch();
	/* upload least 4 bits and then latch */
	LCD_DATA_REG.HN = Inst;
	LCD_Latch();
	/* delay 40 us */
	Delay_Us(40);
}

void LCD_init(void)
{
	Dio_GroupMode(LCD_DATA_PORT, LCD_DATA_MSK, DIO_EN_M_Output);
	Dio_ChannelMode(LCD_RW_PIN, DIO_EN_M_Output);
	Dio_ChannelMode(LCD_RS_PIN, DIO_EN_M_Output);
	Dio_ChannelMode(LCD_EN_PIN, DIO_EN_M_Output);
	
	Delay_Ms(100);
	LCD_sendInst(LCD_CMD_FUN_SET_4BIT);	/* Required: to set 4Bit operation */
	LCD_sendInst(LCD_CMD_CFG);			/* Full CFG */
	LCD_sendInst(LCD_CMD_DISP_ON);
	LCD_Clear();
}

void LCD_Clear(void)
{
	LCD_sendInst(LCD_CMD_CLEAR);
	Delay_Ms(5);
}

static void LCD_sendData(uint8_t Data)
{
	Dio_ChannelWrite(LCD_RS_PIN, DIO_EN_W_High);
	Dio_ChannelWrite(LCD_RW_PIN, DIO_EN_W_Low);
	/* upload most 4 bits and then latch */
	LCD_DATA_REG.HN = (Data>>4);
	LCD_Latch();
	/* upload least 4 bits and then latch */
	LCD_DATA_REG.HN = Data;
	LCD_Latch();
	/* delay 40 us */
	Delay_Us(40);
}

void LCD_Display_Char(uint8_t uint8_tChar)
{
	LCD_sendData(uint8_tChar);
}

void LCD_Display_String(uint8_t* puint8_tString)
{
	uint8_t S_index = 0;
	while(puint8_tString[S_index])
	{
		LCD_Display_Char(puint8_tString[S_index]);
		S_index++;
	}
}

void LCD_Display_Num(int32_t int32_tNum)
{
	uint8_t buffer [20] = {0};
	ltoa(int32_tNum, buffer, 10);
	LCD_Display_String(buffer);
}


static void      LCD_GoToXY      (LCD_Row_t row, LCD_Col_t col)
{
	if (row == 1)
	{
		LCD_sendInst((0x80) + col);
	}
	else if (row == 2)
	{
		LCD_sendInst((0xc0) + col);
	}
	else if (row == 3)
	{
		LCD_sendInst((0x90) + col);
	}
	else if (row == 4)
	{
		LCD_sendInst((0xd0) + col);
	}
}

void        LCD_Display_CharXY       (LCD_Row_t row, LCD_Col_t col, uint8_t uint8_tChar)
{
	LCD_GoToXY(row,col);
	LCD_sendData(uint8_tChar);
}

void        LCD_Display_StringXY      (LCD_Row_t row, LCD_Col_t col, uint8_t* puint8_tString)
{
	LCD_GoToXY(row,col);
	LCD_Display_String(puint8_tString);
}

void        LCD_Display_NumXY          (LCD_Row_t row, LCD_Col_t col, int32_t int32_tNum)
{
	LCD_GoToXY(row,col);
	LCD_Display_Num(int32_tNum);
}