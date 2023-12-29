#include "CircularDoubleLinkedList.h"

int main()
{
	Node* Head = NULL;

	CDLL_PushTail(&Head, CDLL_CreatNode(101));
	CDLL_PushTail(&Head, CDLL_CreatNode(202));
	CDLL_PushTail(&Head, CDLL_CreatNode(303));
	
	puts("\n정출력");
	CDLL_PrintList(&Head);
	puts("\n역출력");
	CDLL_ReversePrintList(&Head);
	
	puts("\n삽입");
	CDLL_InsertAt(GetNodeByData(&Head, 101), CDLL_CreatNode(404));
	CDLL_InsertAt(GetNodeByData(&Head, 303), CDLL_CreatNode(505));
	CDLL_InsertAt(GetNodeByData(&Head, 202), CDLL_CreatNode(606));

	puts("\n정출력");
	CDLL_PrintList(&Head);
	puts("\n역출력");
	CDLL_ReversePrintList(&Head);

	puts("\n삭제");
	CDLL_DeleteNode(&Head, 101);
	CDLL_DeleteNode(&Head, 505);
	CDLL_DeleteNode(&Head, 606);

	puts("\n정출력");
	CDLL_PrintList(&Head);
	puts("\n역출력");
	CDLL_ReversePrintList(&Head);


	puts("\n전체삭제");
	CDLL_ReleaseList(&Head);

	CDLL_PrintList(&Head);
	
	return 0;
}