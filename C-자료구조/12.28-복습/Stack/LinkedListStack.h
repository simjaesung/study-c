#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node
{
	char* Data;
	struct Node* next;

}Node;


typedef struct LLS
{
	Node* Head;
	Node* Top;
	int Size;
}LLS;


void LLS_CreateStack(LLS** Stack);
void LLS_DeleteStack(LLS** Stack);
Node* LLS_CreateNode(char* pszData);
void LLS_PushStack(LLS** Stack, Node* NewNode);
char* LLS_PopStack(LLS** Stack);
char* LLS_GetTop(LLS** Stack);
int LLS_GetSize(LLS** Stack);