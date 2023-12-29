#include "CircularQueue.h"

void CQ_CreateQueue(CircularQueue** Queue, int Size)
{
	*Queue = (CircularQueue*)malloc(sizeof(CircularQueue));

	(*Queue)->Capacity = Size;
	(*Queue)->Front = 0;
	(*Queue)->Rear = 0;
	(*Queue)->Nodes = (Node*)malloc(sizeof(Node) * (Size + 1));
}

void CQ_DeleteQueue(CircularQueue* Queue)
{
	free(Queue->Nodes);
	free(Queue);
}

void CQ_Enqueue(CircularQueue* Queue, int Data)
{
	if (!CQ_IsFull(Queue))
	{
		Queue->Nodes[Queue->Rear++].Data = Data;
		Queue->Rear %= Queue->Capacity + 1;
	}
}

int CQ_Dequeue(CircularQueue* Queue)
{
	if (!CQ_IsEmpty(Queue))
	{
		int Data = Queue->Nodes[Queue->Front].Data;
		Queue->Nodes[Queue->Front++].Data = NULL;
		Queue->Front %= Queue->Capacity + 1;
		return Data;
	}

	return NULL;
}

int CQ_IsEmpty(CircularQueue* Queue)
{
	if (Queue->Front == Queue->Rear)
	{
		puts("Empty!!");
		return 1;
	}
		
	return 0;
}

int CQ_IsFull(CircularQueue* Queue)
{
	int Rear = Queue->Rear;
	int Front = Queue->Front;
	
	if (Rear > Front)
	{
		if (Rear % (Queue->Capacity) == Front)
		{
			puts("Full!!");
			return 1;
		}
	}
	else
	{
		if (Rear + 1 == Front)
		{
			puts("Full!!");
			return 1;
		}
			
	}

	return 0;
}

void CQ_PrintNodes(CircularQueue* Queue)
{
	for (int i = 0; i < Queue->Capacity + 1; i++)
	{
		printf("[%d]\n", Queue->Nodes[i].Data);
	}
}