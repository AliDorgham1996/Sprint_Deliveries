#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


#include "../ECUAL/DC_Motor/DC_Motor_Cfg.h"


typedef enum 
{
	Valid_MTR_init,
	Invalid_MTR_Num,
	Invalid_Direct,
	MOTOR_WAS_ON,
	MOTOR_WAS_OFF,
	MOTOR_Dir_CW,
	MOTOR_Dir_ACW  
}MOTOR_ERROR_state;



MOTOR_ERROR_state  		Motor_Init		   (Motor_t   num);
MOTOR_ERROR_state 		Motor_RunDirection (Motor_t   num, MTR_Direction_t Direction, uint8_t Duty);
MOTOR_ERROR_state 		Motor_Stop         (Motor_t   num);


#endif /* DC_MOTOR_H_ */