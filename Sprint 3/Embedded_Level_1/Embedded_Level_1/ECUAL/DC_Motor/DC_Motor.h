#ifndef DC_MOTOR_H_
#define DC_MOTOR_H_


#include "../ECUAL/DC_Motor/DC_Motor_Cfg.h"


typedef enum 
{
	Valid_MTR_init      = 0x00,
	Invalid_MTR_Num     = 0x01,
	Invalid_Direct      = 0x02,
	MOTOR_WAS_ON        = 0x04,
	MOTOR_WAS_OFF       = 0x08,
	MOTOR_Dir_CW        = 0x10,
	MOTOR_Dir_ACW       = 0x20
}MOTOR_ERROR_state;



MOTOR_ERROR_state  		Motor_Init		   (Motor_t   num);
MOTOR_ERROR_state 		Motor_RunDirection (Motor_t   num, MTR_Direction_t Direction, uint8_t Duty);
MOTOR_ERROR_state 		Motor_Stop         (Motor_t   num);


#endif /* DC_MOTOR_H_ */