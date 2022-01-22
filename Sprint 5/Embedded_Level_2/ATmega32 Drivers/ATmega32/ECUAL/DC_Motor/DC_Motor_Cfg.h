#ifndef DC_MOTOR_CFG_H_
#define DC_MOTOR_CFG_H_


#include "../MCAL/DIO/Dio.h"
#include "../MCAL/PWM/PWM.h" 

/* Control Pins */
#define MOTOR_H1            0
#define MOTOR_H2            1
#define MOTOR_H1H2          2

/* Delay between stop and restart */
#define MTR_RESTART_TIME_MS 1000U


typedef enum
{
	Motor_CWACW_init,
	Motor_CW,        /* H1 is on , H2 is off */
	Motor_ACW        /* H2 is on , H1 is off */
}MTR_Dircetion_t;

typedef enum
{
	Mtr_Start,
	Motor1 = Mtr_Start,
	Motor2,
	Mtr_End
}Motor_t;

typedef enum
{
	MTR_DIR_CW,
	MTR_DIR_ACW
}MTR_Direction_t;

typedef DioChannel_t  MTR_CFG_t [Mtr_End][MOTOR_H1H2];

#endif /* DC_MOTOR_CFG_H_ */