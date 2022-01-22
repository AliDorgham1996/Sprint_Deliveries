#ifndef LED_H
#define LED_H

#include "../ECUAL/LED/LED_Cfg.h"

typedef enum 
{
	LED_EN_valid_init,
	LED_EN_invalidNum,
	LED_EN_invalidState
}LEDError_t;



LEDError_t            LED_init       (LED_t LED_Num);
LEDError_t            LED_State      (LED_t LED_Num, LED_State_t State);


#endif /* LED_H */

/*********************************************************************************************************
* End of file
**********************************************************************************************************/