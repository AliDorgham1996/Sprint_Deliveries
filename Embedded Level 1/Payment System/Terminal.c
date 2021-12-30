#include "Terminal.h"
#include "Server.h"

extern const DIAG_MSG  DiagNosis_Messeges ;
extern void  Diagnosis (Approvance_t diagnostic);

const static Amount_t MAX_AMOUNT  = 5000.00;
const Date_t TodayDate = "27/12/2021";

static void DateUpdate (Date_t * UpdatedDate);
static Approvance_t  CheckAmount(Amount_t * WantedAmount);
static Approvance_t  CheckExpData(ExpDate_t DateOfExp);
static Approvance_t  DataToServer(ST_CardData_t * CardData , Amount_t * WantedAmount);

void TerminalCheck (ST_CardData_t * CardData)
{
    Approvance_t  Transaction    =  Approved;
    Amount_t      WantedAmount ;
    HANDLE        hConsole       = GetStdHandle(STD_OUTPUT_HANDLE);

    GetCardData(CardData);

    Transaction |= CheckExpData(CardData->DateOfExp);
    if(Approved == Transaction)
    {
        Transaction |= CheckAmount(&WantedAmount);
    }
    if(Approved == Transaction)
    {
        Transaction |= DataToServer((ST_CardData_t *)(CardData) ,(Amount_t *)(&WantedAmount));
        if(Approved == Transaction)
        {
            printf("Now your balance is  ");
            SetConsoleTextAttribute(hConsole, Red);
            printf("%.2f  E.P\n",WantedAmount);
            SetConsoleTextAttribute(hConsole, White);
        }
    }

    Diagnosis (Transaction);
}


static Approvance_t  CheckAmount(Amount_t * WantedAmount)
{
    Approvance_t Transaction      = Declined;
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    printf("Please Enter Terminal Data:\n");

    printf("Please Enter the Transaction Amount:\n");
    SetConsoleTextAttribute(hConsole, Green);
    fflush(stdin);
    scanf("%f",WantedAmount);
    SetConsoleTextAttribute(hConsole, White);

    if(*WantedAmount <= MAX_AMOUNT)
    {
        Transaction = Approved;
    }
    else
    {
        Transaction = ExecceMaxAmount;
    }

    return Transaction;
}

static void DateUpdate (Date_t * UpdatedDate)
{
    strcpy((char*)(*UpdatedDate) , (const char*)TodayDate);
}


static Approvance_t  CheckExpData(ExpDate_t DateOfExp)
{
    Approvance_t Transaction      = Declined;
    ExpDate_t    CheckTodayDate   = {0};
    ExpDate_t    CheckCardExp     = {0};
    Date_t       UpdatedDate      = {0};

    DateUpdate(&UpdatedDate);

    CheckTodayDate[0] = UpdatedDate[Date_Y1];
    CheckTodayDate[1] = UpdatedDate[Date_Y2];
    CheckTodayDate[2] = UpdatedDate[Date_M1];
    CheckTodayDate[3] = UpdatedDate[Date_M2];
    CheckTodayDate[4] = '\0';

    CheckCardExp  [0] = DateOfExp[EXP_Y1];
    CheckCardExp  [1] = DateOfExp[EXP_Y2];
    CheckCardExp  [2] = DateOfExp[EXP_M1];
    CheckCardExp  [3] = DateOfExp[EXP_M2];
    CheckCardExp  [4] = '\0';

    if(strcmp((const char*)CheckCardExp  ,(const char*) CheckTodayDate) >= 0)
    {
        Transaction = Approved;
    }
    else
    {
        Transaction = CardIsExpired;
    }

    return Transaction;
}


static Approvance_t  DataToServer(ST_CardData_t * CardData , Amount_t * WantedAmount)
{
    Approvance_t  return_value ;
    static DataBase_t  UserData;
    strcpy((char*)(UserData.pan_number),(const char*)(CardData->Pan_number));
    UserData.balance = ((Amount_t)*WantedAmount);
    return_value  = CheckUserData(&UserData);
    *WantedAmount = UserData.balance ;
    return return_value;
}
