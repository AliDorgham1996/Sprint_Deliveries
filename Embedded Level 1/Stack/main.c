#include "main.h"

int main()
{
    uint8_t expression [MAXSIZE];
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    string_t theAnswer = {0};
    uint8_t value;
    do
    {
        system("cls");

        printf("Enter your Parentheses...   >   ");
        SetConsoleTextAttribute(hConsole, 1);
        fflush(stdin);
        scanf("%[^\n]%*c",expression);

        theAnswer = balancedParentheses(expression);

        SetConsoleTextAttribute(hConsole, 2);
        printf("\nThe Parentheses is ");

        SetConsoleTextAttribute(hConsole, 4);
        printf("%s\n\n\n\n\n",theAnswer);

        SetConsoleTextAttribute(hConsole, 6);
        printf("Again.................(y/n)?\n");
        fflush(stdin);

        scanf("%c",&value);
    }while((value == 'Y') || (value == 'y'));

    system("pause");

    return 0;
}
