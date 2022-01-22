#ifndef X_O_ENUMS_H
#define X_O_ENUMS_H

#include <stdint.h>

#define NameMaxSize         26
#define X_TABLE_BASE        27
#define Y_TABLE_BASE        9
#define X_TABLE_MASK        0x0F
#define Y_TABLE_MASK        0xF0
#define X_SHIFT_TAPS        13
#define Y_SHIFT_LINES       6
#define Y_PLAYER_DIFS       2
#define COL_3X3_ARR         3
#define ROW_3X3_ARR         3
#define K_OF_3x3            3


typedef unsigned char        u8;
typedef uint16_t             u16;
typedef u8  Arr_4_C_t        [4];
typedef u8  Arr_6_C_t        [6];
typedef u8  Arr_9_C_t        [9];
typedef u8  Name_t           [NameMaxSize];
typedef u8  XO_Table_t       [ROW_3X3_ARR][COL_3X3_ARR];

typedef enum
{
    XO_Start,
    XO_Play,
    XO_Choose,
    XO_End
}GameState_t;

typedef enum
{
    False,
    True
}Bool_t;

typedef enum //used
{
    X_shape = 'X',
    O_shape = 'o',
    Epmty   = ' '
}Shapes_t;

typedef enum //wait
{
    OnePlayer,
    TwoPlayers
}Mode_t;

typedef enum
{
    DRAW ,
    WIN  ,
    LOSE
}MatchStatus_t;

typedef MatchStatus_t  PlayerStatus_t;

typedef enum
{
    BackGround_Color = 7,
    Text_Color       = 8
}ConsoleColor_t;

typedef enum//wait
{
    Black       = 0 ,
    Blue        = 1 ,
    Green       = 2 ,
    Aqua        = 3 ,
    Red         = 4 ,
    Purple      = 5 ,
    Yellow      = 6 ,
    White       = 15
}Console_Color_t;

typedef Console_Color_t TextBackgroung_t;
typedef Console_Color_t TextColor_t;

typedef enum
{
    START_MENU  ,
    NAME_MENU   ,
    TEAM_MENU   ,
    COLOR_Menu  ,
    CHOOSE_MENU
}XO_Menu_t;

typedef enum//used
{
    Welcome_XO  ,
    WinPtrn     ,
    DrwPtrn     ,
    Bye_XO
}Welcome_t;

typedef enum //used
{
    PLAYER_1    ,
    PLAYER_2
}Player_Num_t;

typedef enum //used
{
    ONE    = 0x12 ,
    TWO    = 0x18 ,
    THREE  = 0x1E ,
    FOUR   = 0x32 ,
    FIVE   = 0x38 ,
    SIX    = 0x3E ,
    SEVEN  = 0x52 ,
    EIGHT  = 0x58 ,
    NINE   = 0x5E
}Position_t;

typedef enum //used
{
    Num_ONE    = 0 ,
    Num_TWO    = 1 ,
    Num_THREE  = 2 ,
    Num_FOUR   = 3 ,
    Num_FIVE   = 4 ,
    Num_SIX    = 5 ,
    Num_SEVEN  = 6 ,
    Num_EIGHT  = 7 ,
    Num_NINE   = 8
}Numbers_t;

//extern variables
extern void (*greeting_arr[])           (void);
extern void (*menu_arr[])               (void);
//extern functions
extern void Greeting    (void(*Fun_Ptr)(void));
extern void Main_Menu   (void(*Fun_Ptr)(void));


#endif /* X_O_ENUMS_H */
