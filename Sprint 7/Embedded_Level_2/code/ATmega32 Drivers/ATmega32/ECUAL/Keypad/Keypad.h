#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "Keypad_Cfg.h"

void    	Keypad_Init     (void);
Flag_t		Keypad_GetKey   (uint8_t* Key);

#endif /* KEYPAD_H_ */