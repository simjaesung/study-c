#pragma once

#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int Data;
}Node;

typedef struct ArrayStack
{
	int Top;
	int Capacity;
	Node* Nodes;
}ArrayStack;


void AS_CreateStack(ArrayStack** Stack,int size);
void AS_DeleteStack(ArrayStack** Stack);
void AS_Push(ArrayStack** Stack, int Data);
int AS_Pop(ArrayStack** Stack);
int AS_GetSize(ArrayStack** Stack);
int AS_IsEmpty(ArrayStack** Stack);