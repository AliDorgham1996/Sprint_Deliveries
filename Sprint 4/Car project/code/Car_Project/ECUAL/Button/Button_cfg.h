/*
 * Button_cfg.h
 *
 * Created: 1/4/2022 1:11:44 PM
 *  Author: Ali Dorgham
 */ 

#ifndef BUTTON_CFG_H___
#define BUTTON_CFG_H___

/**************************************************************************************************
* User defined Libraries
***************************************************************************************************/
#include "Library.h"
#include "DIO.h"


/**************************************************************************************************
* File Configurations
***************************************************************************************************/

#define BTN_1_PORT    PORTc
#define BTN_1         PIN5

#define BTN_2_PORT    PORTc
#define BTN_2         PIN6

#define BTN_3_PORT    PORTc
#define BTN_3         PIN7

#define BTN_4_PORT    PORTb
#define BTN_4         PIN2

typedef enum
{
	Btn_Start ,
	Button1 = Btn_Start ,
	Button2,
	Button3,
	Button4,
	Btn_End
}EN_Button_t;

typedef enum
{
	BTN_LOW,
	BTN_HIGH
}BTN_State_t;


/**************************************************************************************************
* User data type
***************************************************************************************************/

typedef struct
{
	uint8_t PORT;
	uint8_t num_pin;
}volatile BTN_CFG_t;

#endif /* BUTTON_CFG_H */