#include "structure.h"
#include "Transaction.h"

const DIAG_MSG  DiagNosis_Messeges =
{
    (string_t)"APPROVED.",
    (string_t)"DECLINED.",
    (string_t)"NO Enough Balance.",
    (string_t)"Your Card is expired.",
    (string_t)"You exceeded the limited amount.",
    (string_t)"Your PAN does not exist."
};

List_Trans_t SucsflTrnsList = {0};


void  Diagnosis (Approvance_t diagnostic)
{
    HANDLE  hConsole  = GetStdHandle(STD_OUTPUT_HANDLE);
    if(Approved == diagnostic)
    {
        SetConsoleTextAttribute(hConsole, Blue);
        printf("%s\n",DiagNosis_Messeges[Diag_F0_Approved]);
    }
    else
    {
        SetConsoleTextAttribute(hConsole, Red);
        printf("%s\n",DiagNosis_Messeges[Diag_FD_Declined]);

        if((diagnostic & PanNotFound) == PanNotFound)
        {
            printf("%s\n",DiagNosis_Messeges[Diag_FX_Exist]);
        }
        else if((diagnostic & NotEnoughBalnce) == NotEnoughBalnce)
        {
            printf("%s\n",DiagNosis_Messeges[Diag_FB_Balance]);
        }
        else if((diagnostic & ExecceMaxAmount) == ExecceMaxAmount)
        {
            printf("%s\n",DiagNosis_Messeges[Diag_FL_Limit]);
        }
        else if((diagnostic & CardIsExpired) == CardIsExpired)
        {
            printf("%s\n",DiagNosis_Messeges[Diag_FE_Expired]);
        }
    }
    SetConsoleTextAttribute(hConsole, White);
}


void AddToSucsflList(TransactNode_t* node)
{
    SucsflTrnsList.ListSize++;
    node->Next = NULL;
    node->Prev = NULL;
	if(SucsflTrnsList.Head == NULL)//if empty
    {
        SucsflTrnsList.Head = node;
        SucsflTrnsList.Tail = node;
    }
    else//not empty
    {
       TransactNode_t *temp = SucsflTrnsList.Head ;
       while( (temp != NULL) && (strcmp((const char*)temp->pan_number , (const char*)node->pan_number) < 0 ))
       {
           temp = temp->Next;
       }
       if(temp == SucsflTrnsList.Head)//insert at head
       {
           SucsflTrnsList.Head->Prev = node;                  //1- assign new node to be (old head prev)
           node->Next                = SucsflTrnsList.Head;   //2- assign new node next to be old head
           SucsflTrnsList.Head       = node;                  //3- assign new head
       }
       else if(temp == NULL)//insert at Tail
       {
           SucsflTrnsList.Tail->Next = node;
           node->Prev                = SucsflTrnsList.Tail;
           SucsflTrnsList.Tail       = node;
       }
       else //insert in mid
       {
           node->Prev       = temp->Prev;
           node->Next       = temp;
           temp->Prev->Next = node;
           temp->Prev       = node;
       }
    }
}

void PrintSucsflTransactions(void)
{
    system("cls");
    system("COLOR F0");
    u8 i;
    TransactNode_t *temp = SucsflTrnsList.Head;
    printf("%*s%*s%*s\n\n",15,"PAN",15,"Data",10,"Amount");
    for(i=0 ; i<SucsflTrnsList.ListSize ; i++)
    {
        printf("%*s%*s%*.2f\n\n",15,temp->pan_number,15,temp->date,10,temp->balance);
        temp = temp->Next;
    }
    system("pause");
}
