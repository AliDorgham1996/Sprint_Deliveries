#ifndef COMPILER_H
#define COMPILER_H

#include <stdint.h>

#include "stack.h"

typedef uint8_t*  string_t;
typedef string_t  answers_t [3];


typedef enum
{
    NotBalanced,
    Balanced,
    NoParentheses
}Balance_t;

string_t balancedParentheses(uint8_t * expression);


#endif // COMPILER_H
