/*
 * Button.h
 *
 * Created: 1/4/2022 1:11:44 PM
 *  Author: Ali Dorgham
 */ 

#ifndef BUTTON_H___
#define BUTTON_H___

/**************************************************************************************************
* Local data types
***************************************************************************************************/
#include "Button_cfg.h"



typedef enum 
{
	Valid_BTN_init  = 0x00,
	Invalid_Num     = 0x01,
	Invalid_Pointer = 0x02
}BUTTON_ERROR_state_t;

/**************************************************************************************************
* Extern Functions
***************************************************************************************************/

void                            BUTTON_init       (void);
BUTTON_ERROR_state_t            BUTTON_READ       (EN_Button_t num, BTN_State_t * ptr_return_value);


#endif /* BUTTON_H */