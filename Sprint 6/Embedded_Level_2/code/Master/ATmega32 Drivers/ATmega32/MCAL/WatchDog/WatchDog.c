#include "../MCAL/WatchDog/WatchDog.h"
#include "../Library/PrivateMacros.h"
#include "../Library/Registers.h"
#include "../Library/Constants.h"

#define WDTCR    (*(volatile uint8_t*)(0x41))
#define WDTOE   4
#define WDE     3
#define WDP     0

Bool_t		WatchDog_start		(WD_Priodies timeout)
{
	Bool_t result = False;
	if((timeout <= WD_EN_1800ms) && (timeout >= WD_EN_14ms))
	{
		WDTCR |= (1<<WDTOE)|(1<<WDE);
		WDTCR = (timeout<<WDP)|(1<<WDE);
		result = True;
	}
	else{/*MISRA C*/}
	return result;
}
void		WatchDog_stop		(void)
{
	uint8_t flag = STATUS.Interrupt_Enable; 
	STATUS.Interrupt_Enable = DISABLE;
	WDTCR |= (1<<WDTOE) | (1<<WDE);
	WDTCR = 0x00;
	if(flag == ENABLE)
	{
		STATUS.Interrupt_Enable = ENABLE;
	}
	else{/*MISRA C*/}
}