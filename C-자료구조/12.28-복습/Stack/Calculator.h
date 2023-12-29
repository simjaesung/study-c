#pragma once


#include "LinkedListStack.h"
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)
#include <math.h>

typedef enum
{
	LEFT = '(',
	RIGHT = ')',
	PLUS = '+',
	MINUS = '-',
	MULTIPLT = '*',
	DIVIDE = '/',
	SPACE = ' ',
	OPERAND
}SYMBOL;

int IsNumber(char Token);
int GetNextToken(char* Expression, char* Token, int* Type);
int GetPriority(char Operator);
//int IsPrior(char Operator1, char Operator2);
void GetPostfix(char* Infix, char* Postfix);
double Calculate(char* Postfix);