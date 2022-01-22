/*
 * PWM.c
 *
 * Created: 1/13/2022 10:15:37 PM
 *  Author: Ali Hassan Dorgham
 */ 

#include "PWM.h"
#include "timer.h"

typedef struct
{
	uint8_t  port;
	uint8_t  pin;	
}PWM_PORT_PIN_t;

PWM_PORT_PIN_t   PWM_CFG  [2] = {{PORTd, PIN4},{PORTd, PIN5}};
TIMER_ID_t       PWM_TIMERS [2] = {Timer_0, Timer_2};

static void     TOGGLE_1 (void);
static void     TOGGLE_2 (void);
static void PWM_setCallBack(void(*a_ptr)(void), const PWM_ID a_pwmID);

static void (*PWM_CALLBACKS[])(void) = {TOGGLE_1,TOGGLE_2};

void PWM_Init(PWM_ID pwm_ch)
{
	DIO_setPinDirection(PWM_CFG[pwm_ch].port, PWM_CFG[pwm_ch].pin, DIO_u8_OUTPUT);
	PWM_setCallBack(PWM_CALLBACKS[pwm_ch], pwm_ch);
}

void PWM_Stop(PWM_ID pwm_ch)
{
	DIO_writePinValue(PWM_CFG[pwm_ch].port, PWM_CFG[pwm_ch].pin, DIO_u8_LOW);
	TIMER_stop(pwm_ch);
}

void SET_PWM_DutyCycle(PWM_ID pwm_ch, uint8_t Duty)
{	
	TIMER_start(pwm_ch, Duty);
}

/***************************************************************************************************************/

static void PWM_setCallBack(void(*a_ptr)(void), const PWM_ID a_pwmID)
{
	TIMER_setCallBack(a_ptr, a_pwmID);
}

static void     TOGGLE_1 (void)
{
	DIO_TogglePin(PWM_CFG[0].port, PWM_CFG[0].pin);
}

static void     TOGGLE_2 (void)
{
	DIO_TogglePin(PWM_CFG[1].port, PWM_CFG[1].pin);
}