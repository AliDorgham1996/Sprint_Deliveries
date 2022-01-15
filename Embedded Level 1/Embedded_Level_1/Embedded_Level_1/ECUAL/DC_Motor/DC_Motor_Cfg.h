#ifndef DC_MOTOR_CFG_H_
#define DC_MOTOR_CFG_H_


#include "../MCAL/DIO/Dio.h"
#include "../MCAL/PWM/PWM.h" 


typedef enum
{
	Motor_CW,  /* H1 is on , H2 is off */
	Motor_ACW  /* H2 is on , H1 is off */
}MTR_Dircetion_t;


/* Control Pins */
#define MOTOR_H1            0
#define MOTOR_H2            1
#define MOTOR_H1H2          2


/* Motor 1 */
#define MTR_1_PWM           PWM_0
#define MTR_1_H1         	DIO_EN_Channel_D_2
#define MTR_1_H2         	DIO_EN_Channel_D_6

/* Motor 2 */
#define MTR_2_PWM           PWM_2
#define MTR_2_H1         	DIO_EN_Channel_D_3
#define MTR_2_H2         	DIO_EN_Channel_D_7


/**************************************************************************************************
* User data type
***************************************************************************************************/

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