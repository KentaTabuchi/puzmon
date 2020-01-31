#include <stdlib.h>
#include <stdio.h>
#include "Party.h"

//コンストラクタ
Party* createParty(char* pPlayerName,Monster* monsterList[4])
{
	Party party = {
		.playerName = pPlayerName,
		.monster_num = 4,
		.monsterList = monsterList
	};
	Party* p_party = (Party*)malloc(sizeof(Party));//ヒープにメモリ領域を確保
	*p_party = party;//確保したメモリ領域に実態を代入。
	return p_party;
}

void showParty(Party* pParty){
	printf("<パーティ編成>-------------------\n");
	for(int i = 0; i < 4 ;i++){
		printf("%s%c%s%c\x1b[0m HP= %3d 攻撃= %2d 防御 = %2d\n",
			pParty->monsterList[i]->element->color,
			pParty->monsterList[i]->element->simbol,
			pParty->monsterList[i]->name,
			pParty->monsterList[i]->element->simbol,
			pParty->monsterList[i]->hp,
			pParty->monsterList[i]->attack,
			pParty->monsterList[i]->gurde
		);
	}
	printf("---------------------------------\n\n");
}

int getPartyHp(Party* pParty){
	int length = pParty->monster_num;
	int partyHp = 0;
	for (int i = 0; i < length; i++){
		partyHp += pParty->monsterList[i]->hp;
	}
	return partyHp;
}
int getPartyMaxHp(Party* pParty){
	int length = pParty->monster_num;
	int partyHp = 0;
	for (int i = 0; i < length; i++){
		partyHp += pParty->monsterList[i]->maxHp;
	}
	return partyHp;
}
