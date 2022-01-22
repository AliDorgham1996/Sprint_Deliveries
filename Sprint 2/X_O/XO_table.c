#include <stdio.h>
#include <windows.h>
#include "XO_Config.h"

//extern variables
extern XO_Players_t     XO_Game         ;
extern const Arr_4_C_t  CLEAR_CONSOLE   ;
extern XO_Table_t       XO_GameTable    ;
extern Arr_9_C_t        Arr_ConsoleColor;

//local functions
u8 ConvertPositionToNum(Position_t pos);

//Global variables
const Position_t Arr_Positions [] = {ONE,TWO,THREE,FOUR,FIVE,SIX,SEVEN,EIGHT,NINE};

void Table_XO (void)
{
    gotoxy(0,0);
    system(CLEAR_CONSOLE);
    ConsoleBackGround(White);
    ConsoleTextColor(XO_Game[PLAYER_1].color);
    printf("\n\n\t\t\t\t\t player 1 : %s",XO_Game[PLAYER_1].name);
    ConsoleTextColor(XO_Game[PLAYER_2].color);
    printf("\n\n\t\t\t\t\t player 2 : %s",XO_Game[PLAYER_2].name);
    ConsoleTextColor(Green);
    gotoxy(X_TABLE_BASE , Y_TABLE_BASE);
    printf("\n\t\t\t\t\t     |     |     ");
    printf("\n\t\t\t\t\t=====*=====*=====");
    printf("\n\t\t\t\t\t     |     |     ");
    printf("\n\t\t\t\t\t=====*=====*=====");
    printf("\n\t\t\t\t\t     |     |     ");

    printf("\n\n\n\n");
    printf("\t\t\t\t\t------------------\n");
    ConsoleTextColor(Black);
    printf("\n\t\t\t\t\t Player 1 : >   \n");
    printf("\n\t\t\t\t\t Player 2 : >   \n");
}

void Table_Input(Shapes_t shape , Position_t pos , Player_Num_t  player)
{
    u8 X_Pos = (pos & X_TABLE_MASK)    ;
    u8 Y_Pos = (pos & Y_TABLE_MASK)>>4 ;
    u8 input = ConvertPositionToNum(pos);
    if(player == PLAYER_1)
    {
        XO_GameTable [input/ROW_3X3_ARR][input%COL_3X3_ARR] = XO_Game[PLAYER_1].shape;
    }
    else
    {
        XO_GameTable [input/ROW_3X3_ARR][input%COL_3X3_ARR] = XO_Game[PLAYER_2].shape;
    }

    gotoxy((X_TABLE_BASE + X_Pos + X_SHIFT_TAPS) , (Y_TABLE_BASE + Y_Pos));
    ConsoleTextColor(XO_Game[player].color);
    printf("%c",shape);
    gotoxy(0,25);
}

Position_t Player_Input(Player_Num_t player)
{
    u8 input ;
    u8 X_Pos = (NINE & X_TABLE_MASK)    ;
    u8 Y_Pos = (NINE & Y_TABLE_MASK)>>4 ;
    Y_Pos   +=  Y_SHIFT_LINES           ;
    if(player == PLAYER_2)
    {
        Y_Pos += Y_PLAYER_DIFS;
    }
    gotoxy((X_TABLE_BASE + X_Pos + X_SHIFT_TAPS) , (Y_TABLE_BASE + Y_Pos));
    ConsoleTextColor(XO_Game[player].color);
    scanf("%c",&input);
    fflush(stdin);
    gotoxy((X_TABLE_BASE + X_Pos + X_SHIFT_TAPS) , (Y_TABLE_BASE + Y_Pos));
    printf("%s","      ");
    gotoxy(0,25);
    input -= '0';
    input -= 1;
    return Arr_Positions [ input ];
}

u8 ConvertPositionToNum(Position_t pos)
{
    u8 input ;
    switch(pos)
    {
        case ONE    : input = Num_ONE   ; break;
        case TWO    : input = Num_TWO   ; break;
        case THREE  : input = Num_THREE ; break;
        case FOUR   : input = Num_FOUR  ; break;
        case FIVE   : input = Num_FIVE  ; break;
        case SIX    : input = Num_SIX   ; break;
        case SEVEN  : input = Num_SEVEN ; break;
        case EIGHT  : input = Num_EIGHT ; break;
        case NINE   : input = Num_NINE  ; break;
        default     :   /* MISRA C */     break;
    }
    return input;
}

