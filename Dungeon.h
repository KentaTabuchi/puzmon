#ifndef __DUNGEON_H__
#define __DUNGEON_H__

#include <stdbool.h>
#include "Monster.h"
#include "Party.h"
void goDungeon(Party* pParty,Monster* monsterList[5],size_t length,Element* gemsSlot[14]);
bool doBattle(Party* pParty,Monster* monster,Element* gemsSlot[14]);
void onPlayerTurn(Party* pParty,Monster* pMonster,Element* gemsSlot[14]);
void onEnemyTurn(Party* pParty,Monster* pMonster);
void doAttack(Party* pParty,Monster* pMonster);
void doEnemyAttack(Party* pParty,Monster* pMonster);
bool checkValidCommand(char* inputStr);

typedef struct{
	int monster_num;
	Monster* monsterList;

}Dungeon;

#endif
