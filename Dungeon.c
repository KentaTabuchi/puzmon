#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "Dungeon.h"
#include "Monster.h"
#include "Element.h"
#include "GemsSlot.h"


void goDungeon(Party* pParty,Monster* monsterList[5],size_t length,Element* gemsSlot[14])
{

	printf("%sのパーティー(HP=%d)はダンジョンに到着した\n",pParty->playerName,getPartyHp(pParty));
	showParty(pParty);
	for(int i=0;i < length ;i++){
		bool isBattleWin = doBattle(pParty,monsterList[i],gemsSlot);
		Monster* pMonster = monsterList[i];
		if(isBattleWin){
			printf("%sはさらに奥へと進んだ\n",pParty->playerName );
			printf("\n\n============================================\n\n");

		}
		else{
			printf("%sはダンジョンから逃げ出した・・・\n",pParty->playerName );
			break;
		}

	}
}

bool doBattle(Party* pParty,Monster* pMonster,Element* gemsSlot[14])
{
	printf("%s%c%s%c\x1b[0mが現れた！！\n\n\n",pMonster->element->color,
										pMonster->element->simbol,
									  	pMonster->name,
								      	pMonster->element->simbol);
	do{
		onPlayerTurn(pParty,pMonster,gemsSlot);
		if(pMonster->hp <= 0)
			break;
		onEnemyTurn(pParty,pMonster);
	}while(pMonster->hp > 0);

	printf("%s%c%s%c\x1b[0mを倒した！！\n\n",pMonster->element->color,
										pMonster->element->simbol,
										pMonster->name,
										pMonster->element->simbol);


	bool isBattleWin = getPartyHp(pParty) >= 0 ? true : false;
	return isBattleWin;
}

void onPlayerTurn(Party* pParty,Monster* pMonster,Element* gemsSlot[14]){
	printf("【%sのターン】\n\n",pParty->playerName);
	printf("---------------------------------------\n\n");
	printf("            %s%c%s%c\x1b[0m\n\n",pMonster->element->color,
										pMonster->element->simbol,
										pMonster->name,
										pMonster->element->simbol);
	printf("           HP= %d / %d\n\n",pMonster->hp,pMonster->maxHp);
	printf("\n\n\n");
	for(int i = 0; i < 4 ;i++){
		printf(" %s%c%s%c\x1b[0m",
			pParty->monsterList[i]->element->color,
			pParty->monsterList[i]->element->simbol,
			pParty->monsterList[i]->name,
			pParty->monsterList[i]->element->simbol
		);
	}
	printf("\n\n");
	printf("           HP= %d / %d\n\n",getPartyHp(pParty),getPartyMaxHp(pParty));
	printf("---------------------------------------\n\n");
	printf("A B C D E F G H I J K L M N\n");
	printGems(gemsSlot);
	printf("---------------------------------------\n\n");
	printf("コマンド？>");
	char inputStr[50];
	scan:
	scanf("%s",inputStr);

	if(checkValidCommand(inputStr)){
		printf("%s\n",inputStr);
	}
	else{
		printf("もう一度入力してください。");
		goto scan;
	}
	doAttack(pParty,pMonster);
}
void onEnemyTurn(Party* pParty,Monster* pMonster){
	printf("【%sのターン】\n\n",pMonster->name);
	doEnemyAttack(pParty,pMonster);
}
void doAttack(Party* pParty,Monster* pMonster){
	int damage = 80;
	pMonster->hp -= damage;
	printf("ダミー攻撃で%dのダメージを与えた\n\n",damage);
}
void doEnemyAttack(Party* pParty,Monster* pMonster){
	int damage = 20;
	pParty->monsterList[0]->hp -= 20;
	printf("%dのダメージを受けた\n\n",damage);
}
bool checkValidCommand(char* inputStr){
	int i;
	for(i = 0;inputStr[i] != '\0';i++);
	return i == 2 ? true : false;
}
