#include "ArrayStack.h"

void AS_CreateStack(ArrayStack** Stack, int size)
{
	(*Stack) = (ArrayStack*)malloc(sizeof(ArrayStack));
	(*Stack)->Nodes = (Node*)malloc(sizeof(Node) * size);

	(*Stack)->Capacity = size;
	(*Stack)->Top = -1;
}

void AS_DeleteStack(ArrayStack** Stack)
{
	free((*Stack)->Nodes);
	free(*Stack);
}

void AS_Push(ArrayStack** Stack, int Data)
{
	int Top = ++((*Stack)->Top);
	(*Stack)->Nodes[Top].Data = Data;
}

int AS_Pop(ArrayStack** Stack)
{
	int Top = ((*Stack)->Top)--;
	return (*Stack)->Nodes[Top].Data;
}

int AS_GetSize(ArrayStack** Stack)
{
	int Size = (*Stack)->Capacity - (*Stack)->Top - 1;
	return Size;
}

int AS_IsEmpty(ArrayStack** Stack)
{
	if ((*Stack)->Top == -1)
		return 1;
	return 0;
}