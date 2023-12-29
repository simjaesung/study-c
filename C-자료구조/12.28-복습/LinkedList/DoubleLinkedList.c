#include "DoubleLinkedList.h"

Node* CreateNode(int Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	memset(NewNode, 0, sizeof(Node));

	NewNode->Data = Data;
	NewNode->next = NULL;
	NewNode->prev = NULL;

	return NewNode;
}


void PrintList(Node** Head)
{
	Node* pTmp = *Head;

	while (pTmp != NULL)
	{
		printf("현재 노드 주소 [%p] / 현재 노드 data [%d] \n", pTmp, pTmp->Data);

		pTmp = pTmp->next;
	}
}


void ReleaseList(Node** Head)
{
	Node* pTmp = *Head;

	while (pTmp != NULL)
	{
		Node* DelNode = pTmp;
		pTmp = pTmp->next;
		free(DelNode);
	}
}

void PushHead(Node** Head, Node* NewNode)
{
	NewNode->next = *Head;
	(*Head)->prev = NewNode;

	*Head = NewNode;
}

void PushTail(Node** Head, Node* NewNode)
{
	Node* pTmp = *Head;
	while (pTmp->next != NULL)
		pTmp = pTmp->next;

	pTmp->next = NewNode;
	NewNode->prev = pTmp;
}


void InsertAfter(Node* PrevNode, Node* NewNode)
{	
	NewNode->prev = PrevNode;
	NewNode->next = PrevNode->next;

	if (PrevNode->next != NULL)
	{
		PrevNode->next->prev = NewNode;
	}

	PrevNode->next = NewNode;
	
}

void DeleteNode(Node** Head, int Data)
{
	Node* pTmp = *Head;
	while (pTmp->next != NULL)
	{
		if (pTmp->Data == Data)
			break;

		pTmp = pTmp->next;
	}

	if (pTmp == *Head)
	{
		*Head = pTmp->next;
		(*Head)->prev = NULL;
		pTmp->next = NULL;
	}
	else if (pTmp->next == NULL)
	{
		pTmp->prev->next = NULL;
		pTmp->prev = NULL;
	}
	else
	{
		pTmp->prev->next = pTmp->next;
		pTmp->next->prev = pTmp->prev;
	}
	free(pTmp);
}


Node* GetNodeAt(Node** Head, int Data)
{
	Node* pTmp = *Head;
	while (pTmp != NULL)
	{
		if (pTmp->Data == Data)
			return pTmp;

		pTmp = pTmp->next;
	}

	return NULL;
}

int GetNodeCount(Node** Head)
{
	int nCount = 0;
	Node* pTmp = *Head;
	while (pTmp != NULL)
	{
		nCount++;
		pTmp = pTmp->next;
	}

	return nCount;
}

void ReversePrintList(Node** Head)
{
	Node* pTmp = *Head;
	while (pTmp->next != NULL)
		pTmp = pTmp->next;

	while (pTmp != NULL)
	{
		printf("현재 노드 주소 [%p] / 현재 노드 data [%d] \n", pTmp, pTmp->Data);
		pTmp = pTmp->prev;
	}
}