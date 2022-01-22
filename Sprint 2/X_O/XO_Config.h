#ifndef XO_CONFIG_H
#define XO_CONFIG_H


#include "X_O_Enums.h"

typedef struct
{
   Shapes_t            shape ;
   TextColor_t          color;
   Name_t               name ;
}Player_t;

typedef Player_t XO_Players_t [2];

void gotoxy(int x,int y);
void ConsoleBackGround(Console_Color_t Color);
void ConsoleTextColor(TextColor_t color);


#endif /* XO_CONFIG_H */
