#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "../MCAL/DIO/Dio.h"
#include "../Library/Registers.h"

typedef enum
{
	LCD_EN_COL_1,
	LCD_EN_COL_2,
	LCD_EN_COL_3,
	LCD_EN_COL_4,
	LCD_EN_COL_5,
	LCD_EN_COL_6,
	LCD_EN_COL_7,
	LCD_EN_COL_8,
	LCD_EN_COL_9,
	LCD_EN_COL_10,
	LCD_EN_COL_11,
	LCD_EN_COL_12,
	LCD_EN_COL_13,
	LCD_EN_COL_14,
	LCD_EN_COL_15,
	LCD_EN_COL_16
}LCD_Col_t;

typedef enum
{
	LCD_EN_ROW_1 = 1,
	LCD_EN_ROW_2,
	LCD_EN_ROW_3,
	LCD_EN_ROW_4
}LCD_Row_t;



#define LCD_DATA_PORT			DIO_EN_Port_A
#define LCD_DATA_MSK			0xF0

#define LCD_EN_PIN				DIO_EN_Channel_A_3
#define LCD_RW_PIN				DIO_EN_Channel_A_2
#define LCD_RS_PIN				DIO_EN_Channel_A_1


typedef struct
{
	uint8_t   :4;
	uint8_t HN:4;
}LCD_DATA_Struct_t;

#define LCD_DATA_REG		(*((volatile LCD_DATA_Struct_t*)(&PORTA)))


#endif /* LCD_CFG_H_ */