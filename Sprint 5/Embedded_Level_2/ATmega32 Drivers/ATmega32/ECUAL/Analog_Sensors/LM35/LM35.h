#ifndef LM35_H_
#define LM35_H_

#include "../MCAL/ADC/ADC.h"

#define  LM35_CHANNEL  ADC_CH0
#define  LM35_V_Ref    5U

void       LM35_Init   (void);
uint16_t    LM35_Read   (void);


#endif /* LM35_H_ */