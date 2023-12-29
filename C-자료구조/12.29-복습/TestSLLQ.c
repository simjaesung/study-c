#include "SSLQueue.h"



int main()
{
	SLLQueue* Queue;
	SLLQ_CreateQueue(&Queue);

	SLLQ_Enqueue(Queue, SLLQ_CreateNode(1));
	SLLQ_Enqueue(Queue, SLLQ_CreateNode(2));
	SLLQ_Enqueue(Queue, SLLQ_CreateNode(3));

	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));
	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));
	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));
	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));

	SLLQ_IsEmpty(Queue);

	SLLQ_Enqueue(Queue, SLLQ_CreateNode(4));
	SLLQ_Enqueue(Queue, SLLQ_CreateNode(5));
	SLLQ_Enqueue(Queue, SLLQ_CreateNode(6));

	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));
	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));
	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));
	printf("Dequeue: %d\n", SLLQ_Dequeue(Queue));

	SLLQ_DeleteQueue(Queue);

	return 0;
}