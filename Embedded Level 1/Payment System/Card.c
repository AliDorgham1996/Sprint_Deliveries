#include "Card.h"


void GetCardData(ST_CardData_t * CardData)
{
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    system("cls");
    printf("Please Enter Card Data:\n");

    printf("Please Enter the Card Holder Name:\n");
    SetConsoleTextAttribute(hConsole, Yellow);
    fflush(stdin);
    scanf("%[^\n]%*c",CardData->UserName);
    SetConsoleTextAttribute(hConsole, White);

    printf("Please Enter Primary Account Number:\n");
    SetConsoleTextAttribute(hConsole, Yellow);
    fflush(stdin);
    scanf("%s",CardData->Pan_number);
    SetConsoleTextAttribute(hConsole, White);

    printf("Please Enter Card Expiry Date:\n");
    SetConsoleTextAttribute(hConsole, Yellow);
    fflush(stdin);
    scanf("%[^\n]%*c",CardData->DateOfExp);
    SetConsoleTextAttribute(hConsole, White);
}
