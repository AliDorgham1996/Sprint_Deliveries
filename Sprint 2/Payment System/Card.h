#ifndef CARD_H
#define CARD_H

#include "structure.h"

typedef struct
{
    Pan_t       Pan_number;
    ExpDate_t   DateOfExp;
    Name_t      UserName;
}ST_CardData_t;

void GetCardData(ST_CardData_t * CardData);

#endif // CARD_H
