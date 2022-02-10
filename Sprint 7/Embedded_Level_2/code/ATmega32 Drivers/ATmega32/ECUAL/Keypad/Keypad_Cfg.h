#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "Registers.h"

#define KEYPAD_DEBOUNCING_MS   20

#define KEYPAD_INVALID_KEY  0

#define KEYPAD_COL			3
#define KEYPAD_ROW			3

#define KEY_ROWS_PORT		DIO_EN_Port_C
#define KEY_COLS_PORT		DIO_EN_Port_C

#if ((KEYPAD_COL==3)&&(KEYPAD_ROW==3))

#define KEY_ROWS_START		2
#define KEY_ROWS_MSK		(7<<KEY_ROWS_START)
#define KEY_COLS_START		5
#define KEY_COLS_MSK		(7<<KEY_COLS_START)

#elif ((KEYPAD_COL==4)&&(KEYPAD_ROW==4))

#define KEY_ROWS_START		0
#define KEY_ROWS_MSK		0x0F
#define KEY_COLS_START		4
#define KEY_COLS_MSK		0xF0

#endif /* COLs and ROWs Configuration */

#endif /* KEYPAD_CFG_H_ */