#ifndef __GEMSSLOT_H__
#define __GEMSSLOT_H__
#include "Element.h"
void printGems(Element* gemsSlot[14]);
void fillGems(Element* gemsSlot[14],Element* elementList[6]);
void swapGem(Element* gemSlot[14],char targetGem,int direction);
void moveGem(Element* gemSlot[14],char targetGem,int place);
#endif
