#include "SingleLinkedList.h"


void SLL_PrintList(Node** Head)
{
	Node* pTmp = *Head;
	
	while (pTmp != NULL)
	{
		printf("현재 주소 : [%p], 값: [%d]\n", pTmp, pTmp->Data);
		pTmp = pTmp->next;
	}
}

void SLL_ReleaseList(Node** Head)
{
	Node* pTmp = *Head;

	while (pTmp != NULL)
	{
		Node* DelNode = pTmp;
		pTmp = pTmp->next;
		free(DelNode);
	}
}

Node* SLL_CreateNode(int Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	memset(NewNode, 0, sizeof(Node));

	NewNode->Data = Data;
	NewNode->next = NULL;

	return NewNode;
}

void SLL_AppendNode(Node** Head, Node* NewNode)
{
	Node* pTmp = *Head;

	while (pTmp->next != NULL)
		pTmp = pTmp->next;

	pTmp->next = NewNode;
}


Node* SLL_GetNodeAt(Node** Head, int Data)
{
	Node* pTmp = *Head;

	while (pTmp != NULL)
	{
		if (pTmp->Data == Data)
			return pTmp;
		pTmp = pTmp->next;
	}

	puts("해당 노드를 찾지 못했습니다.");
	return NULL;
}


void SLL_DeleteNode(Node** Head, int Data)
{
	Node* pTmp = *Head;
	Node* pPrev = NULL;

	while (pTmp != NULL)
	{
		if (pTmp->Data == Data)
		{
			if (pTmp == *Head)
			{
				*Head = pTmp->next;
			}
			else
			{
				pPrev->next = pTmp->next;
			}
			free(pTmp);
			break;
		}
		pPrev = pTmp;
		pTmp = pTmp->next;
	}
}


void SLL_InsertAfter(Node* BeforeNode, Node* NewNode)
{
	NewNode->next = BeforeNode->next;
	BeforeNode->next = NewNode;
}


void SLL_InsertNewHead(Node** Head, Node* NewNode)
{
	NewNode->next = *Head;
	*Head = NewNode;
}

void SLL_InsertBefore(Node** Head, Node* CurrentNode, Node* NewNode)
{

	if (CurrentNode == *Head)
	{
		SLL_InsertNewHead(Head, NewNode);
	}

	else
	{
		Node* pTmp = *Head;
		while (pTmp->next != CurrentNode)
		{
			pTmp = pTmp->next;
		}

		pTmp->next = NewNode;
		NewNode->next = CurrentNode;
	}
}