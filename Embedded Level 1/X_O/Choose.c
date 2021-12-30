#include <stdio.h>
#include <windows.h>

extern COORD           coord;

extern void gotoxy(int x,int y);

static void Start_menu  (void);
static void Name_menu   (void);
static void Team_menu   (void);
static void Color_menu  (void);
static void Choose_menu (void);


void (*menu_arr[])(void) =
{
    Start_menu ,
    Name_menu  ,
    Team_menu  ,
    Color_menu ,
    Choose_menu
};

void Main_Menu (void(*Fun_Ptr)(void))
{
    Fun_Ptr();
}

static void Start_menu(void)//done
{
    //gotoxy(0,0);
    printf("===================================\n");
    printf("\n\tWelcome To Our New Series !\n");
    printf("\n\t1-  New Game\n\t2-  Exit\n");
    printf("\n---------------------------------\n");
    printf("\t>   ");
    printf("\n===================================\n");
    //gotoxy(10,4);
}

static void Name_menu(void)
{
    gotoxy(0,2);
    printf("===================================\n");
    printf("\tEnter Your Name\n");
    printf("\t>   ");
    printf("\n===================================\n");
    gotoxy(10,4);
}

static void Team_menu(void)
{
    gotoxy(0,2);
    printf("===================================\n");
    printf("\n\tJoin Team\n");
    printf("\n\t1-  X Team\n\t2-  O Team\n");
    printf("\n---------------------------------\n");
    printf("\t>   ");
    printf("\n===================================\n");
    gotoxy(10,10);

}

static void Color_menu(void)
{
    gotoxy(0,2);
    printf("===================================\n");
    printf("\n\tYour Team's Color\n\n");
    printf("\t1-  Black  \n");
    printf("\t2-  Blue   \n");
    printf("\t3-  Green  \n");
    printf("\t4-  Aqua   \n");
    printf("\t5-  Red    \n");
    printf("\t6-  Purple \n");
    printf("\t7-  Yellow \n");
    printf("\n---------------------------------\n");
    printf("\t>   ");
    printf("\n===================================\n");
    gotoxy(10,15);
}

static void Choose_menu(void)//done
{
    //gotoxy(0,0);
    printf("===================================\n");
    printf("\n\tPlease Enter your choice\n");
    printf("\n\t1-  Play Again\n\t2-  New Game\n\t3-  Exit\n");
    printf("\n---------------------------------\n");
    printf("\t>   ");
    printf("\n===================================\n");
    //gotoxy(10,20);
}
