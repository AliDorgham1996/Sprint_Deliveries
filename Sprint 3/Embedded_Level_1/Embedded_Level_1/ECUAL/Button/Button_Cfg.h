#ifndef BUTTON_CFG_H
#define BUTTON_CFG_H


#include "../MCAL/DIO/Dio.h"

#define BUTTON_DEBOUNCING_MS      50U

typedef enum
{
	Btn_Start ,
	Button0 = Btn_Start ,
	Button1,
	Btn_End
}Button_t;

typedef enum
{
	BTN_NotPressed,
	BTN_IS_Pressed
}BTN_State_t;

typedef enum
{
	BTN_LOW = DIO_EN_W_Low,
	BTN_HIGH = DIO_EN_W_High
}BTN_PhysicalState_t;

typedef enum
{
	BTN_EN_Pull_Down,
	BTN_EN_Pull_Up
}BTN_Pull_State_t;

typedef struct
{
	DioChannel_t         Channel;
	BTN_Pull_State_t     Resistor;	
}BTN_Configuration_t;


#endif /* BUTTON_CFG_H */