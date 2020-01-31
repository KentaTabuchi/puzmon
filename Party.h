#ifndef __PARTY_H__
#define __PARTY_H__

#include "Monster.h"

typedef struct{
	char* playerName;
	int monster_num;
	Monster** monsterList;
}Party;

Party* createParty(char* pPlayerName,Monster* monsterList[4]);
void showParty(Party* party);
int getPartyHp(Party* pParty);
int getPartyMaxHp(Party* pParty);

#endif
