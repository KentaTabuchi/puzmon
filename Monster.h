#ifndef __MONSTER_H__
#define __MONSTER_H__
#include "Element.h"

typedef struct{
	char* name;
	int hp;
	int maxHp;
	Element* element;
	int attack;
	int gurde;

}Monster;
Monster* createMonster(char* name,int hp,int maxHp,Element* element,int attack,int gurde);

#endif
