#include "../MCAL/PWM/PWM.h"
#include "../MCAL/Timer/Timer.h"


_E PWM_CFG_t   PWM_CFG  [PWM_End];

_S void  TOGGLE_0 (void);
_S void  TOGGLE_2 (void);
_V _S V_CallBack_V_t  PWM_CallBacks[PWM_End]  = {TOGGLE_0, TOGGLE_2};

PWMError_t PWM_Init(PWM_CH_t pwm_ch)
{
	PWMError_t return_value = PWM_EN_valid_inti;
	DioError_t DioReturn_value = DIO_EN_valid_inti;
	TMR_Configuration_t  TMRConfiguration;
	if((pwm_ch >= PWM_Start) && (pwm_ch < PWM_End))
	{
		DioReturn_value = Dio_ChannelMode(PWM_CFG[pwm_ch].Channel, DIO_EN_M_Output);
		if(DioReturn_value == DIO_EN_valid_inti)
		{
			Timer_PWMCallBack(PWM_CFG[pwm_ch].Timer, PWM_CallBacks[pwm_ch]);
			TMRConfiguration.Clock = PWM_CFG[pwm_ch].Clock;
			Timer_Init(&TMRConfiguration);
		}
		else{return_value = PWM_EN_InvalidDioChannel;}
	}
	else{return_value = PWM_EN_InvalidChannel;}
	
	return return_value;
}

PWMError_t PWM_Stop(PWM_CH_t pwm_ch)
{
	PWMError_t return_value = PWM_EN_valid_inti;
	if((pwm_ch >= PWM_Start) && (pwm_ch < PWM_End))
	{
		Timer_Stop(PWM_CFG[pwm_ch].Timer);
		Dio_ChannelWrite(PWM_CFG[pwm_ch].Channel, DIO_EN_W_Low);
	}
	else
	{
		return_value = PWM_EN_InvalidChannel;
	}
	return return_value;
}

PWMError_t PWM_DutyCycle(PWM_CH_t pwm_ch, uint8_t Duty)
{
	PWMError_t return_value = PWM_EN_valid_inti;
	if((pwm_ch >= PWM_Start) && (pwm_ch < PWM_End))
	{
		Timer_SoftWarePWM(PWM_CFG[pwm_ch].Timer, Duty, PWM_CFG[pwm_ch].Clock);
		Timer_Start(PWM_CFG[pwm_ch].Timer);
	}
	else
	{
		return_value = PWM_EN_InvalidChannel;
	}
	return return_value;
}

_S void   TOGGLE_0 (void)
{
	Dio_ChannelWrite(PWM_CFG[PWM_Channel_0].Channel, DIO_EN_W_Toggle);
}
_S void   TOGGLE_2 (void)
{
	Dio_ChannelWrite(PWM_CFG[PWM_Channel_2].Channel, DIO_EN_W_Toggle);
}