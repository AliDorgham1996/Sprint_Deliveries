#include <stdio.h>
#include <windows.h>
#include "X_O_Enums.h"
#include "XO_Config.h"

const Arr_4_C_t         CLEAR_CONSOLE    = "cls";
const Arr_6_C_t         WAIT_CONSOLE     = "pause";
COORD                   coord            = {0,0};
XO_Players_t            XO_Game          = {0};
XO_Table_t              XO_GameTable     = {0};
static TextColor_t      Cnsl_Txt         = Green;
static Console_Color_t  Cnsl_BckGrnd     = White;

static HANDLE hConsole;


void gotoxy(int x,int y)
{
    coord.X=x;
    coord.Y=y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),coord);
}

void ConsoleBackGround(Console_Color_t Color)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Cnsl_BckGrnd = Color;
    SetConsoleTextAttribute(hConsole, ((Cnsl_BckGrnd<<4)|(Cnsl_Txt)));
}

void ConsoleTextColor(TextColor_t Color)
{
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    Cnsl_Txt = Color;
    SetConsoleTextAttribute(hConsole, ((Cnsl_BckGrnd<<4)|(Cnsl_Txt)));
}

