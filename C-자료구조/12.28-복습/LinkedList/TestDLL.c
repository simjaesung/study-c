#include "DoubleLinkedList.h"


int main()
{
	Node* Head = CreateNode(10);

	PushHead(&Head, CreateNode(20));
	PushHead(&Head, CreateNode(30));
	PushTail(&Head, CreateNode(40));
	PushTail(&Head, CreateNode(50));

	PrintList(&Head);

	puts("\nInsert �õ�");
	InsertAfter(GetNodeAt(&Head, 30), CreateNode(60));
	PrintList(&Head);
	puts("\nInsert �õ�");
	InsertAfter(GetNodeAt(&Head, 50), CreateNode(70));
	InsertAfter(GetNodeAt(&Head, 40), CreateNode(80));
	PrintList(&Head);

	puts("\nDelete �õ�");
	DeleteNode(&Head, 30);
	DeleteNode(&Head, 70);
	DeleteNode(&Head, 80);

	PrintList(&Head);

	printf("���� �� ��� ���� : %d \n", GetNodeCount(&Head));
	

	puts("\n���� ���");
	ReversePrintList(&Head);
	ReleaseList(&Head);
	return 0;
}