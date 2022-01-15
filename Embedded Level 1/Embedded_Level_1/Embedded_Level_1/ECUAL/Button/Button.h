#ifndef BUTTON_H
#define BUTTON_H


#include "../ECUAL/Button/Button_Cfg.h"


typedef enum 
{
	BTN_EN_valid_init,
	BTN_EN_invalidNum,
	BTN_EN_invalidPointer
}ButtonError_t;


ButtonError_t            BUTTON_init       (Button_t BTN_Num);
ButtonError_t            BUTTON_IsPressed  (Button_t BTN_Num, BTN_State_t * State);


#endif /* BUTTON_H */