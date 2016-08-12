#pragma once

//This  header file is used in every other file in this project

#include<stdbool.h>
#include<stdlib.h>
#include<limits.h>

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
}* ElemType,PreElemType;

#define ElemTypeEmpty NULL

//For easy,you can also use this element type. 
//typedef int ElemType;
//#define ElemTypeEmpty 0

//Operations
#define CreateElem(p) p=(ElemType)malloc(sizeof(PreElemType));p->i=0
//Elemtype is pointer,point PredefinedElemType.
//Use ElemType like this: p->i=15;

#define DeleteElem(p)  free(p);p=NULL
//p is ElemType variate.
//I intentionally omitted a semicolon.
//So,they just like real functions when using them.

