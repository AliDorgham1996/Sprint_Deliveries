#include <stdio.h>
#include <string.h>
#include "X_O_Enums.h"

extern Name_t TheWinner ;

static void XO_Welcome      (void);
static void WinnerPattern   (void);
static void DrawPattern     (void);
static void XO_Good_bye     (void);

void (*greeting_arr[])(void) =
{
    XO_Welcome,
    WinnerPattern,
    DrawPattern,
    XO_Good_bye
};

void Greeting(void(*Fun_Ptr)(void))
{
    Fun_Ptr();
}

static void XO_Welcome(void)
{
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t*                          *");
    printf("\n\n\t\t\t\t\t*          Welcome         *");
    printf("\n\n\t\t\t\t\t*                          *");
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n");
}

static void WinnerPattern(void)
{
    u8 s = strlen(TheWinner);
    u8 a = 26 - s;
    a /= 2;
    unsigned char r = 27 - s;
    r -= a;
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t*        The Winner        *");
    printf("\n\n\t\t\t\t\t*            is            *");
    printf("\n\n\t\t\t\t\t*%*s%*c",a+s, TheWinner,r,'*');
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n");
}

static void DrawPattern(void)
{
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t*           Game           *");
    printf("\n\n\t\t\t\t\t*            is            *");
    printf("\n\n\t\t\t\t\t*          Draw !!         *");
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n");
}

static void XO_Good_bye(void)
{
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n\n\t\t\t\t\t*                          *");
    printf("\n\n\t\t\t\t\t*         Good Bye         *");
    printf("\n\n\t\t\t\t\t*                          *");
    printf("\n\n\t\t\t\t\t*  *  *  *  *  *  *  *  *  *");
    printf("\n");
}
