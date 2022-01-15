#ifndef LED_H
#define LED_H

#include "../ECUAL/LED/LED_Cfg.h"

typedef enum 
{
	LED_EN_valid_init,
	LED_EN_invalidNum
}LEDError_t;



LEDError_t            LED_init       (LED_t LED_Num);
LEDError_t            LED_ON         (LED_t LED_Num);
LEDError_t            LED_OFF        (LED_t LED_Num);
LEDError_t            LED_Toggle     (LED_t LED_Num);


#endif /* LED_H */

/*********************************************************************************************************
* End of file
**********************************************************************************************************/