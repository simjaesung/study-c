#include "CircularQueue.h"


int main()
{
	CircularQueue* Queue;
	CQ_CreateQueue(&Queue,5);

	CQ_IsEmpty(Queue);
	CQ_Enqueue(Queue, 1);
	CQ_Enqueue(Queue, 2);
	CQ_Enqueue(Queue, 3);
	CQ_Enqueue(Queue, 4);
	CQ_Enqueue(Queue, 5);
	CQ_PrintNodes(Queue);

	CQ_Enqueue(Queue, 6);

	printf("Dequeue: %d\n", CQ_Dequeue(Queue));
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));

	CQ_Enqueue(Queue, 7);
	CQ_Enqueue(Queue, 8);
	CQ_PrintNodes(Queue);
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));
	printf("Dequeue: %d\n", CQ_Dequeue(Queue));

	
	
	return 0;
}