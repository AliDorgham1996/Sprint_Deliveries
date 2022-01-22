/*
 * Indications.h
 *
 * Created: 1/16/2022 2:07:56 AM
 *  Author: Ali Hassan Dorgham
 */ 


#ifndef INDICATIONS_H_
#define INDICATIONS_H_

typedef enum
{
	Led0 = 4,
	Led1 = 5,
	Led2 = 6,
	Led3 = 7
}Led_t;

#include "avr/io.h"

void Basic_io_init(void);
void Led_only_on(Led_t led);


#endif /* INDICATIONS_H_ */