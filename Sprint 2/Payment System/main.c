#include "PaymentSystem.h"
#include "Transaction.h"

int main()
{
    u8      return_value ;
    HANDLE  hConsole  = GetStdHandle(STD_OUTPUT_HANDLE);
    do
    {
        ATM_Bank_XXX();

        printf("Do you want to continue (y/n)?: ");
        SetConsoleTextAttribute(hConsole, Blue);
        fflush(stdin);
        scanf("%c",&return_value);
        SetConsoleTextAttribute(hConsole, White);

    }while((return_value == 'y') || (return_value == 'Y'));

    PrintSucsflTransactions();

    return 0;
}
