/*
 * Library.h
 *
 * Created: 1/12/2022 2:18:22 PM
 *  Author: Ali Hassan Dorgham
 */ 


#ifndef LIBRARY_H_
#define LIBRARY_H_


#define F_CPU 8000000
#ifndef  F_CPU
#warning "you will use default F_CPU ";
#endif

/* AVR */
#include "util/delay.h"
#include "avr/interrupt.h"
#include "atmega32.h"

/* Standard Libraries */
#include "stdlib.h"
#include "stdbool.h"
#include "string.h"
#include "math.h"
#include "stdint.h"

#endif /* LIBRARY_H_ */