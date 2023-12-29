#include "SSLQueue.h"


void SLLQ_CreateQueue(SLLQueue** Queue)
{
	*Queue = (SLLQueue*)malloc(sizeof(SLLQueue));

	(*Queue)->Front = NULL;
	(*Queue)->Rear = NULL;
	(*Queue)->Size = 0;
}

void SLLQ_DeleteQueue(SLLQueue* Queue)
{
	
	Node* pTmp = Queue->Front;

	while (pTmp != NULL)
	{
		Node* DelNode = pTmp;
		pTmp = pTmp->next;
		free(DelNode);
	}
	Queue->Size = 0;

	free(Queue);
}

Node* SLLQ_CreateNode(int Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = Data;
	NewNode->next = NULL;

	return NewNode;
}

void SLLQ_DeleteNode(Node* DelNode)
{
	free(DelNode);
}

void SLLQ_Enqueue(SLLQueue* Queue, Node* NewNode)
{
	if (Queue->Front == NULL)
	{
		Queue->Front = NewNode;
		Queue->Rear = NewNode;
	}
	else
	{
		Queue->Rear->next = NewNode;
		Queue->Rear = NewNode;
	}

	Queue->Size++;
}

int SLLQ_Dequeue(SLLQueue* Queue) 
{
	if (SLLQ_IsEmpty(Queue))
		return 0;

	int Data = Queue->Front->Data;
	Node* DelNode = Queue->Front;

	Queue->Front = Queue->Front->next;

	SLLQ_DeleteNode(DelNode);
	
	Queue->Size--;

	return Data;
}

int SLLQ_IsEmpty(SLLQueue* Queue)
{
	if (Queue->Size == 0)
	{
		puts("Empty!!!!");
		return 1;
	}
		
	return 0;
}