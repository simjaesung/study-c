#pragma once

#include<stdio.h>
#include<malloc.h>

typedef struct ArrayStack
{
	int Top;
	int Capacity;
	struct Node* Nodes;
} ArrayStack;


typedef struct Node
{
	int Data;
} Node;


void AS_CreateStack(ArrayStack** stack, int size);
void AS_PushStack(ArrayStack* stack, int data);
int AS_PopStack(ArrayStack* stack);
int AS_GetSize(ArrayStack* stack);
int AS_GetTop(ArrayStack* stack);