#ifndef TRANSACTION_H
#define TRANSACTION_H

#include "structure.h"


typedef struct TRANSACTION_Node
{
    Amount_t      balance;
    Date_t        date;
    Pan_t         pan_number;
    struct TRANSACTION_Node* Next;
    struct TRANSACTION_Node* Prev;
}TransactNode_t;

typedef struct
{
    struct TRANSACTION_Node* Head;
    struct TRANSACTION_Node* Tail;
    u8 ListSize;
}List_Trans_t;


typedef enum
{
    Diag_F0_Approved     = 0,
    Diag_FD_Declined     = 1,
    Diag_FB_Balance      = 2,
    Diag_FE_Expired      = 3,
    Diag_FL_Limit        = 4,
    Diag_FX_Exist        = 5
}DiagMessege_t;


void AddToSucsflList(TransactNode_t* node);
void PrintSucsflTransactions(void);

#endif // TRANSACTION_H
