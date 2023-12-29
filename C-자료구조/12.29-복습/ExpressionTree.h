#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Node
{
	char* Data;
	struct Node* left;
	struct Node* right;
}Node;

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

Node* BT_CreateNode(char* Data);
void BT_MakeExpressionTree(char* Postfix, Node** Node);
double ET_Evaluate(Node* ExTreeRoot);

void BT_Preorder(Node* Root);
void BT_Inorder(Node* Root);
void BT_Postorder(Node* Root);  