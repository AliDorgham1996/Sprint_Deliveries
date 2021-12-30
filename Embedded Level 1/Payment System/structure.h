#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <stdint.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>

#define Diag_Num          6

typedef uint8_t u8;
typedef u8 Pan_t    [10];
typedef u8 ExpDate_t [6];
typedef u8 Name_t   [25];

typedef float    Amount_t;
typedef u8  Date_t  [11];


typedef enum
{
    Approved            = 0x00,
    ExecceMaxAmount     = 0x01,
    NotEnoughBalnce     = 0x02,
    CardIsExpired       = 0x04,
    PanNotFound         = 0x08,
    Declined            = 0x10
}Approvance_t;


typedef u8 * string_t;
typedef string_t  DIAG_MSG [Diag_Num];

typedef enum
{
    Blue        = 1 ,
    Green       = 2 ,
    Aqua        = 3 ,
    Red         = 4 ,
    Purple      = 5 ,
    Yellow      = 6 ,
    White       = 15
}Console_Color_t;

typedef enum
{
    False,
    True
}Bool_t;

#endif // STRUCTURE_H
