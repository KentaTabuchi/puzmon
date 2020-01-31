#ifndef __ELEMENT_H__
#define __ELEMENT_H__

typedef struct{
	char* name;
	char* attribute;
	char simbol;
	char* color;
	char* bgColor;
}Element;

Element* createElement(char* name,char* attribute,char simbol,char* color,char* bgColor);

#endif
