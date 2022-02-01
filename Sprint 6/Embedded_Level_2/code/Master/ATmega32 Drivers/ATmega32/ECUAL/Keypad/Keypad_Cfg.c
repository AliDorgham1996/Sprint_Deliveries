#include "../ECUAL/Keypad/Keypad_Cfg.h"

uint8_t Keypad_keys[KEYPAD_ROW][KEYPAD_COL] = 
{
#if ((KEYPAD_ROW==3)&&(KEYPAD_COL==3))
	{'1','2','3'},
	{'4','5','6'},
	{'7','8','9'}
#elif ((KEYPAD_ROW==4)&&(KEYPAD_COL==4))
	{'7','8','9','/'},
	{'4','5','6','*'},
	{'1','2','3','-'},
	{'C','0','=','+'}
#endif
};