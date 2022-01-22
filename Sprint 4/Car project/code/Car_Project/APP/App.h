#ifndef APP_H_
#define APP_H_

#include <stdint.h>
#include "DC_Motor.h"
#include "Button.h"


#define  BUTTON_MOVE		Button2
#define  BUTTON_LEFT		Button1
#define  BUTTON_RIGHT		Button3
#define  BUTTON_GEAR		Button4


typedef enum
{
	CAR_EN_F_30,
	CAR_EN_F_60,
	CAR_EN_F_90,
	
	CAR_EN_BACK,
	CAR_EN_B_30,
	CAR_EN_B_R_30,
	CAR_EN_B_L_30,
	
	CAR_EN_Move,
	CAR_EN_Right,
	CAR_EN_Left,
	
	CAR_EN_Stop,
	CAR_EN_Init
}Car_StateMachine_t;

	
void App_Init(void);

void App_Update(void);

#endif /* APP_H_ */