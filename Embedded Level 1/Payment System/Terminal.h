#ifndef TERMINAL_H
#define TERMINAL_H

#include "structure.h"
#include "Card.h"

typedef struct
{
    Amount_t    WantedAmount;
    Date_t      DateOfTransaction;
}ST_TerminalData_t;

//(M1)(M2)('/')(Y1)(Y2)
typedef enum
{
    EXP_M1  = 0,
    EXP_M2  = 1,
    EXP_Y1  = 3,
    EXP_Y2  = 4,
    Date_M1 = 3,
    Date_M2 = 4,
    Date_Y1 = 8,
    Date_Y2 = 9,
}DateCheck_t;

void     TerminalCheck (ST_CardData_t * CardData);
void     Diagnosis (Approvance_t diagnostic);


#endif // TERMINAL_H
