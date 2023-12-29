#pragma once

#include "LinkedListStack.h"
#define _CRT_SECURE_NO_WARNINGS 
#pragma warning(disable:4996)

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

int IsNum(char token);
int GetNextToken(char* Infix, char* Token, int* Type);
void InfixToPostfix(char* Infix, char* Postfix);
int GetPirioirty(char token);
double Calculator(char* Postfix);