#include "DC_Motor_cfg.h"


DioChannel_t  MTR_H1H2_CFG [Mtr_End][MOTOR_H1H2] = 
{    
	{DIO_EN_Channel_D_2, DIO_EN_Channel_D_6}, 
	{DIO_EN_Channel_D_3, DIO_EN_Channel_D_7}
}; 

PWM_CH_t   MTR_PWM_CFG    [Mtr_End] = 
{
	PWM_Channel_0 , PWM_Channel_2
};

/**************************************************************************************************
* End of file
***************************************************************************************************/