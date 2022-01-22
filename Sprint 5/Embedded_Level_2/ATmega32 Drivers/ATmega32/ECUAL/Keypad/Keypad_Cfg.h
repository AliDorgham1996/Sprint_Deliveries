#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "../Library/Registers.h"

#define KEYPAD_INVALID_KEY  0

#define KEYPAD_COL			3
#define KEYPAD_ROW			3

#define KEY_ROWS_PORT		PORTC
#define KEY_ROWS_DDR		DDRC
#define KEY_ROWS_START		2
//#define KEY_ROWS_MSK		0x1C
#define KEY_ROWS_MSK		(7<<KEY_ROWS_START)


#define KEY_COLS_PORT		PORTC
#define KEY_COLS_DDR		DDRC
#define KEY_COLS_PINR		PINC
#define KEY_COLS_START		5
//#define KEY_COLS_MSK		0xE0
#define KEY_COLS_MSK		(7<<KEY_COLS_START)


#endif /* KEYPAD_CFG_H_ */