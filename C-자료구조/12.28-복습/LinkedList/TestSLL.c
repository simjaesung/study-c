#include "SingleLinkedList.h"


int main()
{
	Node* Head = SLL_CreateNode(222);

	SLL_AppendNode(&Head, SLL_CreateNode(504));
	SLL_AppendNode(&Head, SLL_CreateNode(101));
	SLL_AppendNode(&Head, SLL_CreateNode(202));

	SLL_PrintList(&Head);

	printf("504노드의 주소: [%p]\n", SLL_GetNodeAt(&Head, 504));
	printf("101노드의 주소: [%p]\n", SLL_GetNodeAt(&Head, 101));
	

	SLL_DeleteNode(&Head, 504);
	SLL_DeleteNode(&Head, 222);
	
	SLL_PrintList(&Head);


	SLL_InsertAfter(SLL_GetNodeAt(&Head, 101), SLL_CreateNode(504));
	SLL_InsertAfter(SLL_GetNodeAt(&Head, 202), SLL_CreateNode(222));
	SLL_PrintList(&Head);

	puts("Head 삽입");
	SLL_InsertNewHead(&Head, SLL_CreateNode(5000));

	SLL_PrintList(&Head);

	puts("InsertBefore");
	SLL_InsertBefore(&Head, SLL_GetNodeAt(&Head,222), SLL_CreateNode(2000));
	SLL_PrintList(&Head);

	puts("InsertBeforeHead");
	SLL_InsertBefore(&Head, SLL_GetNodeAt(&Head, 5000), SLL_CreateNode(3000));
	SLL_PrintList(&Head);

	SLL_ReleaseList(&Head);
	return 0;
}