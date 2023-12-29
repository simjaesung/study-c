#include "CircularDoubleLinkedList.h"


Node* CDLL_CreatNode(int Data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));

	newNode->Data = Data;
	newNode->next = NULL;
	newNode->prev = NULL;

	return newNode;
}

void CDLL_PrintList(Node** Head)
{
	Node* pTmp = *Head;
	printf("현재 주소 [%p] / 현재 Node의 Data [%d]\n", pTmp, pTmp->Data);
	pTmp = pTmp->next;

	while (pTmp != *Head)
	{
		printf("현재 주소 [%p] / 현재 Node의 Data [%d]\n", pTmp, pTmp->Data);
		pTmp = pTmp->next;
	}
}

void CDLL_ReversePrintList(Node** Head)
{
	Node* pTmp = *Head;
	pTmp = pTmp->prev;

	while (pTmp != *Head)
	{
		printf("현재 주소 [%p] / 현재 Node의 Data [%d]\n", pTmp, pTmp->Data);
		pTmp = pTmp->prev;
	}
	printf("현재 주소 [%p] / 현재 Node의 Data [%d]\n", pTmp, pTmp->Data);
}

void CDLL_ReleaseList(Node** Head)
{
	Node* pTmp = *Head;
	
	pTmp = pTmp->next;

	while (pTmp != *Head)
	{
		Node* DelNode = pTmp;
		pTmp = pTmp->next;

		free(DelNode);
	}

	free(pTmp);
}

void CDLL_PushTail(Node** Head, Node* NewNode)
{
	if (*Head == NULL)
	{
		*Head = NewNode;
		(*Head)->next = *Head;
		(*Head)->prev = *Head;
	}
	else
	{
		Node* Tail = (*Head)->prev;

		NewNode->prev = Tail;
		NewNode->next = *Head;

		Tail->next = NewNode;
		(*Head)->prev = NewNode;
	}
}

void CDLL_DeleteNode(Node** Head, int Data)
{
	Node* pTmp = *Head;

	while (pTmp->next != *Head)
	{
		if (pTmp->Data == Data)
			break;
		pTmp = pTmp->next;
	}

	if (pTmp == *Head)
		*Head = pTmp->next;

	pTmp->prev->next = pTmp->next;
	pTmp->next->prev = pTmp->prev;
	pTmp->prev = NULL;
	pTmp->next = NULL;
}

void CDLL_InsertAt(Node* prevNode, Node* NewNode)
{
	NewNode->next = prevNode->next;
	NewNode->prev = prevNode;

	prevNode->next->prev = NewNode;
	prevNode->next = NewNode;
	
}

Node* GetNodeByData(Node** Head, int Data)
{
	Node* pTmp = *Head;

	while (pTmp->next != *Head)
	{
		if (pTmp->Data == Data)
			return pTmp;
		pTmp = pTmp->next;
	}

	if (pTmp->Data == Data)
		return pTmp;

	return NULL;
}