#include "LinkedQueue.h"

int main()
{
	LinkedQueue* queue = NULL;
	LQ_CreateQueue(&queue);

	
	puts("\nTEST 1~3 enqueue");
	LQ_Enqueue(queue, LQ_CreateNode("TEST1"));
	LQ_Enqueue(queue, LQ_CreateNode("TEST2"));
	LQ_Enqueue(queue, LQ_CreateNode("TEST3"));

	printf("Size: %d\n", LQ_SizeQueue(queue));

	puts("\nDequeue 3¹ø");
	printf("Dequeue: %s\n", LQ_Dequeue(queue));
	printf("Dequeue: %s\n", LQ_Dequeue(queue));
	printf("Dequeue: %s\n", LQ_Dequeue(queue));
	printf("Size: %d\n", LQ_SizeQueue(queue));


	puts("\nTEST 4~6 enqueue");
	LQ_Enqueue(queue, LQ_CreateNode("TEST6TEST6TEST6TEST6TEST4"));
	LQ_Enqueue(queue, LQ_CreateNode("TEST7TEST7TEST7TEST7TEST5"));
	LQ_Enqueue(queue, LQ_CreateNode("TEST8TEST8TEST8TEST8TEST6"));
	printf("Size: %d\n", LQ_SizeQueue(queue));

	puts("\nDequeue 2¹ø");
	printf("Dequeue: %s\n", LQ_Dequeue(queue));
	printf("Dequeue: %s\n", LQ_Dequeue(queue));

	printf("Size: %d\n", LQ_SizeQueue(queue));



	
	
	LQ_RemoveQueue(queue);
	
	return 0;
}