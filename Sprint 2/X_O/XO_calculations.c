#include "X_O_Enums.h"
#include <string.h>
#include "XO_Config.h"

extern XO_Table_t     XO_GameTable ;
extern XO_Players_t   XO_Game;

Name_t    TheWinner  = {0};
Player_Num_t    currentPlayer  = PLAYER_1;


static Bool_t ChckWnnr(uint16_t value);

Bool_t Check_Winner(void)
{
    uint8_t i , j;
    uint8_t counter_rows    = 0;
    uint8_t counter_cols    = 0;
    uint8_t counter_diag    = 0;
    uint8_t counter_revdiag = 0;

    Bool_t   result_value   = False;
     for(i=0 ; i < ROW_3X3_ARR ;i++)
    {
        counter_rows = 0;
        counter_cols = 0;
        for(j=0 ; j < COL_3X3_ARR ;j++)
        {
            if(XO_Game[currentPlayer].shape == XO_GameTable[i][j])//[i][j] : count the row
            {
                counter_rows++;
                if(counter_rows == K_OF_3x3)
                {
                    result_value = True;
                    break;
                }else{/* MISRA C */}
            }else{/* MISRA C */}
            if(XO_Game[currentPlayer].shape == XO_GameTable[j][i])//[j][i] : count the col
            {
                counter_cols++;
                if(counter_cols == K_OF_3x3)
                {
                    result_value = True;
                    break;
                }else{/* MISRA C */}
            }else{/* MISRA C */}
            if(i == j)// count diagonal
            {
                if(XO_Game[currentPlayer].shape == XO_GameTable[i][j])
                {
                    counter_diag++;
                    if(counter_diag == K_OF_3x3)
                    {
                        result_value = True;
                        break;
                    }else{/* MISRA C */}
                }else{/* MISRA C */}
            }else{/* MISRA C */}
            if((i+j) == (K_OF_3x3 - 1))// count inversion diagonal
            {
                if(XO_Game[currentPlayer].shape == XO_GameTable[i][j])
                {
                    counter_revdiag++;
                    if(counter_revdiag == K_OF_3x3)
                    {
                        result_value = True;
                        break;
                    }else{/* MISRA C */}
                }else{/* MISRA C */}
            }else{/* MISRA C */}
        }

        if(result_value == True)
        {
            break;
        }else{/* MISRA C */}
    }

    if(result_value == True)
    {
        strcpy(TheWinner , XO_Game[currentPlayer].name);
    }
    else{/* MISRA C */}

    return result_value;
}


Bool_t Check_Draw(void)
{
    return True;
}
