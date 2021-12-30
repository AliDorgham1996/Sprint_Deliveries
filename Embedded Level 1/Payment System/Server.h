#ifndef SERVER_H
#define SERVER_H

#include "structure.h"

#define DATABASE_SIZE   10

//server
typedef struct
{
    Pan_t       pan_number;
    Amount_t    balance;
}DataBase_t;

Approvance_t  CheckUserData(DataBase_t * UserData);

typedef uint8_t  DataBaseMax_t;

#endif // SERVER_H
