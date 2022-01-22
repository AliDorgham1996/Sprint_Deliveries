#include <stdio.h>
#include <windows.h>
#include "X_O_Enums.h"
#include "XO_Config.h"

extern const  Arr_4_C_t      CLEAR_CONSOLE;
extern const  Arr_6_C_t      WAIT_CONSOLE;
extern        Player_Num_t   currentPlayer;
extern        XO_Table_t     XO_GameTable ;
extern        XO_Players_t   XO_Game;
extern        COORD          coord;
extern        Position_t     Arr_Positions [];

extern Bool_t     Check_Winner(void);
extern Bool_t     Check_Draw  (void);
extern void       Table_XO    (void);
extern void       Table_Input (Shapes_t shape , Position_t pos , Player_Num_t  player);
extern Position_t Player_Input(Player_Num_t player);

static void play(Player_Num_t player);
static Bool_t CheckValidity(Position_t pos);
static Bool_t InCorrectRenge(Position_t pos);
extern u8 ConvertPositionToNum(Position_t pos);

void XO_init(void)
{
    u8 ScannedShape;
    system("COLOR F2");
    Greeting(greeting_arr[Welcome_XO]);
    system(WAIT_CONSOLE);
    ConsoleBackGround(Black);
    ConsoleTextColor(Yellow);

    system(CLEAR_CONSOLE);
    printf("\tPlayer 1\n");
    Main_Menu(menu_arr[NAME_MENU]);
    fflush(stdin);
    scanf("%[^\n]%*c",XO_Game[PLAYER_1].name);

    system(CLEAR_CONSOLE);
    printf("\tPlayer 1\n");
    Main_Menu(menu_arr[TEAM_MENU]);
    fflush(stdin);
    scanf("%d",&ScannedShape);
    if(O_shape == (ScannedShape-1))
    {
        XO_Game[PLAYER_1].shape = O_shape;
    }
    else
    {
        XO_Game[PLAYER_1].shape = X_shape;
    }

    system(CLEAR_CONSOLE);
    printf("\tPlayer 1\n");
    Main_Menu(menu_arr[COLOR_Menu]);
    fflush(stdin);
    scanf("%c",&XO_Game[PLAYER_1].color);
    XO_Game[PLAYER_1].color -= '0';
    XO_Game[PLAYER_1].color -= 1;

    system(CLEAR_CONSOLE);
    printf("\tPlayer 2\n");
    Main_Menu(menu_arr[NAME_MENU]);
    fflush(stdin);
    scanf("%[^\n]%*c",XO_Game[PLAYER_2].name);

    system(CLEAR_CONSOLE);
    printf("\tPlayer 2\n");
    Main_Menu(menu_arr[COLOR_Menu]);
    fflush(stdin);
    scanf("%c",&XO_Game[PLAYER_2].color);
    fflush(stdin);
    XO_Game[PLAYER_2].color -= '0';
    XO_Game[PLAYER_2].color -= 1;
    if(O_shape == XO_Game[PLAYER_1].shape)
    {
        XO_Game[PLAYER_2].shape = X_shape;
    }
    else
    {
        XO_Game[PLAYER_2].shape = O_shape;
    }
}

void XO_GoodBye(void)
{
    system(CLEAR_CONSOLE);
    system("COLOR 2F");
    Greeting(greeting_arr[Bye_XO]);
    gotoxy(0,25);
    system(WAIT_CONSOLE);
}

void XO (void)
{
    u8  counter ;
    system("COLOR F0");
    Table_XO();
    for(counter = 0 ; counter < 9 ; counter ++)
    {
        if(counter % 2 == 0)
        {
            currentPlayer = PLAYER_1;
        }
        else
        {
            currentPlayer = PLAYER_2;
        }
        play(currentPlayer);
        if(counter >= 4)
        {
            if(True == Check_Winner())
            {
                system(CLEAR_CONSOLE);
                system("COLOR F5");
                Greeting(greeting_arr[WinPtrn]);
                system(WAIT_CONSOLE);
                break;
            }
        }
        if(counter == 8)
        {
            system(CLEAR_CONSOLE);
            system("COLOR F6");
            Greeting(greeting_arr[DrwPtrn]);
            system(WAIT_CONSOLE);
        }
    }
}

static void play(Player_Num_t player)
{
    Position_t pos;
    Bool_t     valid_1 = False;
    Bool_t     valid_2 = False;
    do
    {
        pos     = Player_Input(player);
        valid_1 = CheckValidity (pos);
        valid_2 = InCorrectRenge(pos);
    }while((False == valid_1) || (False == valid_2));
    Table_Input(XO_Game[player].shape , pos , player);
}

static Bool_t CheckValidity(Position_t pos)
{
    Bool_t valid = False;
    u8 input = ConvertPositionToNum(pos);
    if(XO_GameTable [input/ROW_3X3_ARR][input%COL_3X3_ARR] == 0)
    {
        valid = True;
    }
    else
    {
        /* MISRA C */
    }
    return valid;
}

static Bool_t InCorrectRenge(Position_t pos)
{
    Bool_t valid = False;
    for(char i = 0 ; i < 9 ;i++)
    {
        if(pos == Arr_Positions[i])
        {
            valid = True;
            break;
        }
    }
    return valid;
}
