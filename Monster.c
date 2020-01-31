#include <stdio.h>
#include <stdlib.h>
#include "Monster.h"
/*
*	モンスターの構造体を定義
*/


//コンストラクタ
Monster* createMonster(char* name,int hp,int maxHp,Element* element,int attack,int gurde)
{
	Monster monster = {
		.name = name,
		.hp = hp,
		.element = element,
		.maxHp = maxHp,
		.attack = attack,
		.gurde = gurde
	};
	Monster* p_monster = (Monster*)malloc(sizeof(Monster));//ヒープにメモリ領域を確保
	*p_monster = monster;//確保したメモリ領域に実態を代入。
	return p_monster;
}
