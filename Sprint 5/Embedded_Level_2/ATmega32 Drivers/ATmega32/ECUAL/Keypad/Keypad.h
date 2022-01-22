#ifndef KEYPAD_H_
#define KEYPAD_H_

#include <stdint.h>
#include "../ECUAL/Keypad/Keypad_Cfg.h"

void    	Keypad_Init     (void);
uint8_t		Keypad_GetKey   (void);


#endif /* KEYPAD_H_ */