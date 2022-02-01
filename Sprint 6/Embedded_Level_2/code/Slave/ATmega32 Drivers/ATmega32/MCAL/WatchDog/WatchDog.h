#ifndef WATCHDOG_H_
#define WATCHDOG_H_

#include "../Library/Types_Defs.h"

typedef enum
{
	WD_EN_14ms, 
	WD_EN_28ms, 
	WD_EN_56ms, 
	WD_EN_110ms,
	WD_EN_220ms, 
	WD_EN_450ms, 
	WD_EN_900ms, 
	WD_EN_1800ms
}WD_Priodies;

Bool_t		 WatchDog_start		(WD_Priodies timeout);
void		 WatchDog_stop		(void);

#endif /* WATCHDOG_H_ */