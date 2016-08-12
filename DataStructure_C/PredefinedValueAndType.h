#pragma once

//This  header file is used in every other file in this project

#include<stdbool.h>
#include<stdlib.h>

//Broad-spectrum element.
typedef enum PredefinedTypesOfElem { 
	ElemBool, 
	ElemChar, 
	ElemInt, 
	ElemUInt, 
	ElemFloat, 
	ElemPointer 
}TypesOfElem;

typedef union PredefinedElemType {
	bool b;
	char c;
	int i;
	unsigned int u;
	float f;
	void *p;
}*ElemType;

#define ElemTypeEmpty NULL



//For easy,you can also use this element type. 
//typedef int ElemType;
//#define ElemTypeEmpty 0
