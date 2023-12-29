#include "LinkedListStack.h"

void LLS_CreateStack(LLS** Stack)
{
	*Stack = (LLS*)malloc(sizeof(LLS));
	(*Stack)->Head = NULL;
	(*Stack)->Top = NULL;
	(*Stack)->Size = 0;
}

void LLS_DeleteStack(LLS** Stack)
{
	Node* pTmp = (*Stack)->Head;

	while (pTmp != NULL)
	{
		Node* DelNode = pTmp;
		pTmp = pTmp->next;
		free(pTmp->Data);
		free(pTmp);
	}

	free(*Stack);
}

Node* LLS_CreateNode(char* pszData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = (char*)malloc(sizeof(char) * (strlen(pszData) + 1));
	memset(NewNode->Data, 0, _msize(NewNode->Data));
	strcpy_s(NewNode->Data, _msize(NewNode->Data), pszData);

	NewNode->next = NULL;

	return NewNode;
}

void LLS_PushStack(LLS** Stack, Node* NewNode)
{
	if ((*Stack)->Head == NULL)
	{
		(*Stack)->Head = NewNode;
		(*Stack)->Top = NewNode;
	}
	else
	{
		(*Stack)->Top->next = NewNode;
		(*Stack)->Top = NewNode;
	}

	(*Stack)->Size++;
}

char* LLS_PopStack(LLS** Stack)
{
	Node* pTmp = (*Stack)->Head;
	Node* PopNode = (*Stack)->Top;

	if ((*Stack)->Size == 1)
	{
		(*Stack)->Head = NULL;
		(*Stack)->Top = NULL;
	}
	else if ((*Stack)->Size == 1)
	{
		return NULL;
	}
	else
	{
		while (pTmp->next != (*Stack)->Top)
		{
			pTmp = pTmp->next;
		}

		pTmp->next = NULL;
		(*Stack)->Top = pTmp;
	}

	(*Stack)->Size--;
	return PopNode->Data;
}


char* LLS_GetTop(LLS** Stack)
{
	if ((*Stack)->Size == 0)
		return NULL;

	return (*Stack)->Top->Data;
}

int LLS_GetSize(LLS** Stack)
{
	return (*Stack)->Size;
}