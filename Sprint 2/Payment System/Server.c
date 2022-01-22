#include "Server.h"
#include "Transaction.h"

extern const Date_t TodayDate;

static DataBase_t SERVER_DATABASE [DATABASE_SIZE] =
{
    [0].pan_number = "123456789" , [0].balance = 100.00 ,
    [1].pan_number = "234567891" , [1].balance = 6000.00 ,
    [2].pan_number = "567891234" , [2].balance = 3250.25 ,
    [3].pan_number = "456789123" , [3].balance = 1500.12 ,
    [4].pan_number = "258649173" , [4].balance = 500.00 ,
    [5].pan_number = "654823719" , [5].balance = 2100.00 ,
    [6].pan_number = "971362485" , [6].balance = 0.00 ,
    [7].pan_number = "793148625" , [7].balance = 1.00 ,
    [8].pan_number = "123123456" , [8].balance = 10.12 ,
    [9].pan_number = "456789321" , [9].balance = 0.55
};

static Bool_t  check_Is_sorted (DataBase_t arr[], uint8_t arr_size);
static void    SortDataBase    (DataBase_t arr[], uint8_t arr_size);
static int16_t B_Search        (DataBase_t arr[], uint8_t arr_size , Pan_t pan_number);
static void    SwapDataBase    (DataBase_t * Node1 , DataBase_t * Node2);

Approvance_t  CheckUserData(DataBase_t * UserData)
{
    Approvance_t result_value = Approved ;
    int16_t  user_index;
    if (check_Is_sorted (SERVER_DATABASE, DATABASE_SIZE) == False )
    {
        SortDataBase(SERVER_DATABASE, DATABASE_SIZE);
    }
    user_index = B_Search(SERVER_DATABASE,DATABASE_SIZE, UserData->pan_number);
    if(user_index == -1)
    {
       result_value = PanNotFound;
    }
    else
    {
        if(SERVER_DATABASE[user_index].balance >= UserData->balance)
        {
            TransactNode_t * Successful_Transactions = (TransactNode_t*)malloc(sizeof(TransactNode_t));
            if(Successful_Transactions != NULL)
            {
                Successful_Transactions->balance   = UserData->balance;
                strcpy((char*)Successful_Transactions->pan_number,(const char*)SERVER_DATABASE[user_index].pan_number);
                strcpy((char*)Successful_Transactions->date,(const char*)TodayDate);
                AddToSucsflList(Successful_Transactions);
            }
            else
            {
                printf("HEAP is Full !!\n");
            }
            SERVER_DATABASE[user_index].balance -= UserData->balance;//withdraw the balance from server
            UserData->balance = SERVER_DATABASE[user_index].balance ;//as a return value
        }
        else
        {
           result_value = NotEnoughBalnce;
        }
    }
    return result_value;
}

static Bool_t check_Is_sorted (DataBase_t arr[], uint8_t arr_size)
{
    Bool_t result_value = True;
    uint8_t arr_index ;
    for(arr_index = 0; arr_index < arr_size - 1 ;arr_index ++ )
    {
        if(strcmp((const char*)arr[arr_index+1].pan_number , (const char*)arr[arr_index].pan_number) <= 0)
        {
            result_value = False;
            break;
        }
    }
    return result_value;
}

static int16_t B_Search (DataBase_t arr[], uint8_t arr_size , Pan_t pan_number)
{
    uint8_t  left      = 0            ;
    uint8_t  right     = arr_size - 1 ;
    uint8_t  middle                   ;
    int8_t   temp                     ;

    while(left <= right)
    {
        middle = left + (right - left )/2;
        temp   = strcmp((const char*)arr[middle].pan_number , (const char*)pan_number);
        if( temp == 0 )
        {
            return middle;
        }
        else if(temp < 0)
        {
            left = middle + 1;
        }
        else
        {
            right = middle - 1;
        }
    }
    return -1;
}

static void  SortDataBase (DataBase_t arr[], uint8_t arr_size)
{
    int8_t arr_index, temp ,check_temp;
    DataBase_t minimum;
    for (arr_index = 1; arr_index < arr_size; arr_index++)
    {
        strcpy((char*) minimum.pan_number ,(const char*) arr[arr_index].pan_number );
        minimum.balance = arr[arr_index].balance;
        temp = arr_index - 1;
        check_temp = strcmp((const char*)arr[temp].pan_number , (const char*)minimum.pan_number);
        while((temp >= 0) && (check_temp > 0))
        {
            SwapDataBase( &arr[temp + 1] , &arr[temp]);
            temp -= 1;
            check_temp = strcmp((const char*)arr[temp].pan_number , (const char*)minimum.pan_number);
        }
        strcpy((char*)arr[temp+1].pan_number , (const char*)minimum.pan_number);
        arr[temp+1].balance = minimum.balance;
    }
}

static void SwapDataBase (DataBase_t * Node1 , DataBase_t * Node2)
{
    DataBase_t temp;
    temp.balance   = Node1->balance;
    Node1->balance = Node2->balance;
    Node2->balance = temp.balance  ;

    strcpy((char*) temp.pan_number   , (const char*) Node1->pan_number );
    strcpy((char*) Node1->pan_number , (const char*) Node2->pan_number );
    strcpy((char*) Node2->pan_number , (const char*) temp.pan_number   );
}
