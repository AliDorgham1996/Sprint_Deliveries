#ifndef _STACK_H_
#define _STACK_H_

#include <stdint.h>

#include "stack.h"

#define STACKSIZE  255


typedef enum
{
    False,
    True
}Bool_t;

typedef struct Stack
{
    uint8_t top ;
    uint8_t arr[STACKSIZE];
}stack_t;

void push(const uint8_t data);
uint8_t pull(void);
void printStack(void);

#endif // _STACK_H_

