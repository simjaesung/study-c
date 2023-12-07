#include "LinkedQueue.h"

void LQ_CreateQueue(LinkedQueue** queue)
{
	(*queue) = (LinkedQueue*)malloc(sizeof(LinkedQueue));
	memset(*queue, 0, sizeof(LinkedQueue));

	(*queue)->Front = NULL;
	(*queue)->Rear = NULL;
	(*queue)->size = 0;
}

void LQ_RemoveQueue(LinkedQueue* queue)
{
	Node* pTmp = queue->Front;

	while (pTmp != NULL)
	{
		Node* Del_Node = pTmp;
		pTmp = pTmp->next;

		free(Del_Node);
	}

	free(queue);
}

void LQ_Enqueue(LinkedQueue* queue, Node* pData)
{
	if (LQ_SizeQueue(queue) == 0)
	{
		queue->Front = pData;
		queue->Rear = pData;
	}
	else
	{
		queue->Rear->next = pData;
		queue->Rear = pData;
	}

	queue->size++;
}

char* LQ_Dequeue(LinkedQueue* queue)
{
	if (LQ_SizeQueue(queue) == 0)
		return NULL;

	Node* DequeueNode = queue->Front;
	queue->Front = DequeueNode->next;

	queue->size--;

	return DequeueNode->Data;
}

Node* LQ_CreateNode(char* pszData)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	memset(NewNode, 0, sizeof(Node));

	NewNode->Data = (char*)malloc(strlen(pszData) + 1);
	memset(NewNode->Data, 0, _msize(NewNode->Data));
	strcpy_s(NewNode->Data, _msize(NewNode->Data), pszData);

	return NewNode;
}


int LQ_SizeQueue(LinkedQueue* queue)
{
	return queue->size;
}