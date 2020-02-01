#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GemsSlot.h"

/*
*	宝石スロット
*/

/**
*	ランダムに生成した宝石を格納する
* 	@param gemsSlot 宝石スロット
*	@param elementList 属性情報のリスト
*/
void fillGems(Element* gemsSlot[14],Element* elementList[6]){

	srand((unsigned)time(0UL));
	for (int i = 0; i < 14; i++ ){
		int randam = rand() % 5;
		gemsSlot[i] = elementList[randam];
	}
	printf("\n");
}
//宝石の列を表示
void printGems(Element* gemsSlot[14]){
	for (int i= 0; i < 14; i++){
		printf("\x1b[30m%s%c\x1b[40m\x1b[37m ",gemsSlot[i]->bgColor,gemsSlot[i]->simbol);
	}
	printf("\n\n");
}

/**
* 宝石の場所を変更する
* @param gemslot 宝石スロット
* @param targetGem 動かす宝石
* @param place 動かす場所
*/
void moveGem(Element* gemSlot[14],char targetGem,int place){
	printGems(gemSlot); 
	int subtract = place -targetGem;
	int direction = subtract >= 0 ? 1 : -1;
	int absSubtract = abs(subtract);
	//printf("差 = %d , 絶対値 = %d,方向 = %d\n",subtract,absSubtract,direction);

	for(int i = 0; i < absSubtract; i++){
		switch (direction)
		{
		case 1:
			swapGem(gemSlot,targetGem + i,direction);	
			break;
		case -1:
			swapGem(gemSlot,targetGem - i,direction);	
			break;
		default:
			break;
		}
		
		printGems(gemSlot); 
	}
}

/**
 * 宝石を隣接する宝石と入れ替える
* @param gemslot 宝石スロット
* @param targetGem 動かす宝石
* @param direction 動かす方向 (1:右 ,-1:左)
*/
void swapGem(Element* gemSlot[14],char targetGem,int direction){
	const char CODE_A = 65;
	Element* tempSlot;
	int new = targetGem - CODE_A;
	int old = targetGem - CODE_A + direction;
	// printf("targetGem = %d ,new = %d ,old = %d\n",targetGem,new,old);
	tempSlot = gemSlot[old];
	gemSlot[old] = gemSlot[new];
	gemSlot[new] = tempSlot;
	 
}