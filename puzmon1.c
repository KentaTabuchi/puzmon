/*=== puzmon0: ソースコードひな形 ===*/
/*** インクルード宣言 ***/

#include <stdio.h>
#include <stdbool.h>
#include "Dungeon.h"
#include "Party.h"
#include "GemsSlot.h"

void initElements(Element* elementList[6]);
void initMonsters(Monster* monsterList[5],Element* elementList[6]);
void initPartyMonsters(Monster* monsterList[4],Element* elementList[6]);

int main(int argc, char** argv)
{
  printf("*** Puzzle & Monsters ***\n");
  char* playerName = argv[1];
  if(playerName == NULL){
	  printf("プレイヤー名を入力してください。\n");
  }else{
	  printf("ようこそ%s\n",playerName);
	  Element* elementList[6];
	  initElements(elementList);
	  Monster* monsterList[5];
	  initMonsters(monsterList,elementList);
	  Monster* partyMonsterList[4];
	  initPartyMonsters(partyMonsterList,elementList);
	  Element* gemsSlot[14]; //宝石の並びを格納するスロット
	  fillGems(gemsSlot,elementList);

	  Party* pParty = createParty(playerName,partyMonsterList);

	  int length = sizeof(monsterList) / sizeof(Monster*);
	  goDungeon(pParty,monsterList,length,gemsSlot);
	  printf("%sはダンジョンを制覇した!!\n",playerName);
	  printf("***GAME CLEARED!!***\n");
	  printf("倒したモンスター数=%d\n",5);
}
  return 0;
}
void initElements(Element* elementList[6]){

	elementList[0] = createElement("FIRE","火",'$',"\x1b[31m","\x1b[41m");
	elementList[1] = createElement("WATER","水",'~',"\x1b[36m","\x1b[46m");
	elementList[2] = createElement("WIND","風",'@',"\x1b[32m","\x1b[42m");
	elementList[3] = createElement("EARTH","土",'#',"\x1b[33m","\x1b[43m");
	elementList[4] = createElement("LIFE","命",'&',"\x1b[35m","\x1b[45m");
	elementList[5] = createElement("EMPTY","無",' ',"\x1b[30m","\x1b[40m");

}
void initMonsters(Monster* monsterList[5],Element* elementList[6]){
	monsterList[0] = createMonster("スライム",100,100,elementList[1],10,5);
	monsterList[1] = createMonster("ゴブリン",200,200,elementList[3],20,10);
	monsterList[2] = createMonster("オオコウモリ",300,300,elementList[2],30,25);
	monsterList[3] = createMonster("ウェアウルフ",400,400,elementList[2],40,30);
	monsterList[4] = createMonster("ドラゴン",800,800,elementList[0],50,40);
}

void initPartyMonsters(Monster* monsterList[4],Element* elementList[6]){
	monsterList[0] = createMonster("朱雀",150,150,elementList[0],25,10);
	monsterList[1] = createMonster("青龍",150,150,elementList[2],15,10);
	monsterList[2] = createMonster("白虎",150,150,elementList[3],20,5);
	monsterList[3] = createMonster("玄武",150,150,elementList[1],20,15);
}
