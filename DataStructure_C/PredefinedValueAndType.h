#pragma once

//This  header file is used in every other file in this project

//Reason of exit.be used in exit().
#define INFEASIBLE -1
#define OVERFLOW -2
#define NULLPOINTER -3

//Element Type.In order to expand the scope of application,you can using "void *" instead of "int".  
typedef int ElemType;
#define ElemTypeEmpty 0
//You can also use this
//typedef struct ElementType {
//	int info;//length or other informatin of Element
//	void *p;//address of Element
//}* Elemtype;
//#define ElemTypeEmpty NULL