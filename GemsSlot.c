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
