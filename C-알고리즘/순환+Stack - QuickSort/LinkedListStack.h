#pragma once

#include<stdio.h>
#include<string.h>
#include<malloc.h>

typedef struct Node {

	int Data;
	struct Node* next;

} Node;


typedef struct LinkedListStack {

	Node* Top;
	Node* List;

	int StackSize;

} LinkedListStack;



void LLS_CreateStack(LinkedListStack** Stack);
Node* LLS_CreateNode(int Data);

void LLS_ReleseStack(LinkedListStack* Stack);
void LLS_PushStack(LinkedListStack* Stack, Node* PushNode);
Node* LLS_PopStack(LinkedListStack* Stack);

int LLS_GetTop(LinkedListStack* Stack);
int LLS_IsEmpty(LinkedListStack* Stack);

int LLS_GetSize(LinkedListStack* Stack);