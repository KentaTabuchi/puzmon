#include <stdio.h>
#include <stdlib.h>
#include "Element.h"
Element* createElement(char* name,char* attribute,char simbol,char* color,char* bgColor){

	Element element = {
		.name = name,
		.attribute = attribute,
		.simbol = simbol,
		.color = color,
		.bgColor = bgColor
	};
	Element* p_element = (Element*)malloc(sizeof(Element));//ヒープにメモリ領域を確保
	*p_element = element;//確保したメモリ領域に実態を代入。
	return p_element;
}
