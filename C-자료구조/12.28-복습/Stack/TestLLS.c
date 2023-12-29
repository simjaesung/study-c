#include "LinkedListStack.h"


int main()
{
	LLS* Stack = NULL;
	LLS_CreateStack(&Stack);

	LLS_PushStack(&Stack, LLS_CreateNode("sim"));
	LLS_PushStack(&Stack, LLS_CreateNode("jae"));
	LLS_PushStack(&Stack, LLS_CreateNode("sung"));

	printf("Top: %s\n", LLS_GetTop(&Stack));
	printf("Size: %d\n", LLS_GetSize(&Stack));

	printf("\nPop: %s\n", LLS_PopStack(&Stack));
	printf("Pop: %s\n", LLS_PopStack(&Stack));

	printf("Top: %s\n", LLS_GetTop(&Stack));
	printf("Size: %d\n", LLS_GetSize(&Stack));


	printf("\nPop: %s\n", LLS_PopStack(&Stack));

	printf("Top: %s\n", LLS_GetTop(&Stack));
	printf("Size: %d\n", LLS_GetSize(&Stack));

	LLS_DeleteStack(&Stack);

	return 0;
}