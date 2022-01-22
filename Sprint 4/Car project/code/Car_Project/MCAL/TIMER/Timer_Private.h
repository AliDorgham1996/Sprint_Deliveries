#ifndef TIMER_PRIVATE_H
#define TIMER_PRIVATE_H

#include <stdint.h>			

/**********************************************************************************************************
* Timer 2
**********************************************************************************************************/

typedef struct
{
	uint8_t Clock	            :3;
	uint8_t CTC_wave_generation	:1;
	uint8_t Modes_out_on_comp	:2;
	uint8_t PWM_wave_generation	:1;
	uint8_t Force_comp	        :1;
}volatile T2_TCCRR_t;

typedef struct
{
	uint8_t              		:6;
	uint8_t OverFlow     		:1;
	uint8_t Comp_Match   		:1;
}volatile T2_TIFR_t;

typedef struct
{
	uint8_t              		:6;
	uint8_t OverFlow     		:1;
	uint8_t Comp_Match   		:1;
}volatile T2_TIMSK_t;

typedef struct
{
	uint8_t UpdateBusy_Timer    :1;
	uint8_t UpdateBusy_Compare  :1;
	uint8_t UpdateBusy          :1;
	uint8_t Asynchronous        :1;
	uint8_t              		:4;
}volatile T2_ASSR_t;

typedef struct
{
	T2_ASSR_t	   				Asyn_Mode;
	uint8_t		   				CompareValue;
	uint8_t		   				Counter;
	T2_TCCRR_t     				Control;
	//18 empty registers
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	uint8_t						:8;
	T2_TIFR_t      				Flags;
	T2_TIMSK_t					Interrupts;
}volatile Timer2_Configuration_t;


/**********************************************************************************************************
* Timer 0
**********************************************************************************************************/

typedef struct
{
	uint8_t Clock	            :3;
	uint8_t CTC_wave_generation	:1;
	uint8_t Modes_out_on_comp	:2;
	uint8_t PWM_wave_generation	:1;
	uint8_t Force_comp	        :1;
}volatile T0_TCCRR_t;

typedef struct
{
	uint8_t OverFlow     		:1;
	uint8_t Comp_Match   		:1;
	uint8_t              		:6;
}volatile T0_TIFR_t;

typedef struct
{
	uint8_t OverFlow     		:1;
	uint8_t Comp_Match   		:1;
	uint8_t              		:6;
}volatile T0_TIMSK_t;

typedef struct
{
	//16 empty registers
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					Counter;
	T0_TCCRR_t  				Control;
	//4 empty registers
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					:8;
	T0_TIFR_t  					Flags;
	T0_TIMSK_t					Interrupts;
	//2 empty registers
	uint8_t  					:8;
	uint8_t  					:8;
	uint8_t  					CompareValue;
}volatile Timer0_Configuration_t;

/*********************************************************************************************************
* TIMERS
*********************************************************************************************************/

typedef union
{
	Timer0_Configuration_t		T0;
	Timer2_Configuration_t		T2;
}volatile Timer_cfg_t;

#define TIMER     (*((Timer_cfg_t*)(0x42)))


#endif /* TIMER_PRIVATE_H */