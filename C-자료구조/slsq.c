#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef struct Node
{
	char Data[32];
	struct Node* next;

} Node;

Node Dum_Node = { 0 };
Node* pTail = &Dum_Node;


void PrintList(void)
{
	Node* ptmp = &Dum_Node;

	while (ptmp != NULL)
	{
		printf("���� ��� �� �� �ּ�: [ %s / %p ] / ���� ��� �ּ� : [ %p ]\n ", ptmp->Data, ptmp,ptmp->next);
		ptmp = ptmp->next;
	}
	putchar('\n');
}


int Push_Head(char* data)
{
	Node* tmp = (Node*)calloc(1,sizeof(Node));

	strcpy_s(tmp->Data, sizeof(data), data);

	
	tmp->next = Dum_Node.next;
	Dum_Node.next = tmp;

	if(tmp->next == NULL)
		pTail = tmp;

	return 1;
}

int Push_Tail(char* data)
{
	Node* tmp = (Node*)calloc(1, sizeof(Node));

	strcpy_s(tmp->Data, sizeof(data), data);

	if (Dum_Node.next == NULL)
		Push_Head(data);
	else
	{
		pTail->next = tmp;
		pTail = tmp;
	}

	return 1;
}

//Node* find_before_Node(char* data)
//{
//	Node* ptmp = Dum_Node.next;
//	Node* prev_ptmp = &Dum_Node;
//
//	while (ptmp != NULL)
//	{
//		if (strcmp(ptmp->Data,data)==0) {
//			return prev_ptmp;
//		}
//		prev_ptmp = ptmp;
//		ptmp = ptmp->next;
//	}
//	return NULL;
//}

Node* find_before_Node(char* data)
{
	Node* ptmp = &Dum_Node;

	while (ptmp->next != NULL)
	{
		if (strcmp(ptmp->next->Data, data) == 0) {
			return ptmp;
		}
		ptmp = ptmp->next;
	}
	return NULL;
}

int Del_Node(char* data)
{
	Node* pPrev = find_before_Node(data);

	//pPrev ��尡 �������� �ʴ� ���
	//pPrev�� NULL�� ���� Head�� ���� ���������ʴ� ��� 2������

	if (pPrev == NULL && pPrev != &Dum_Node)
	{
		puts("�ش� ��带 ã�� �� �����ϴ�.");
		return -1;
	}

	Node* Del_Node = pPrev->next;

	if (Del_Node == pTail)
		pTail = pPrev;

	if (pPrev)
		pPrev->next = Del_Node->next;  	
	else
		Dum_Node.next = Del_Node->next;

	free(Del_Node);
	return 1;
}

void ReleseList()
{
	//Node* ptmp = &Dum_Node.next; XXXXX
	//&Dum_Node.next��� ���� ���ʿ� �ȵǴ� ��

	//Node* ptmp = &Dum_Node; -> ���̳�� ����� �ǵ��� ����
	Node* ptmp = Dum_Node.next;
	
	while (ptmp != NULL)
	{
		Node* Del_Node = ptmp;

		printf("Delete : %p\n", ptmp);
		ptmp = ptmp->next;
		
		free(Del_Node);
	}

	Dum_Node.next = NULL;
}


//Stack ����
int push(char* data)
{
	Push_Head(data);
}

int pop()
{
	if (Dum_Node.next == NULL)
	{
		puts("�� Stack�Դϴ�.");
		return NULL;
	}

	Del_Node(Dum_Node.next->Data);

	return 1;
}

//queue ����
int enqueue(char* data)
{
	Push_Tail(data);
}

int Dequeue()
{
	pop();
}


int main()
{
	//Stack �׽�Ʈ
	puts("TEST1 Ǫ��");
	push("TEST1");
	PrintList();
	
	puts("TEST2 Ǫ��");
	push("TEST2");
	PrintList();
	
	puts("TEST3 Ǫ��");
	push("TEST3");
	PrintList();
	

	puts("TEST3 ����");
	Del_Node("TEST3");
	PrintList();

	puts("pop ����");
	pop();
	PrintList();

	puts("pop ����");
	pop();
	PrintList();

	puts("pop ����");
	pop();
	PrintList();
	

	//queue �׽�Ʈ
	/*puts("TEST1 enqueue");
	enqueue("TEST1");
	PrintList();

	puts("TEST2 enqueue");
	enqueue("TEST2");
	PrintList();

	puts("TEST3 enqueue");
	enqueue("TEST3");
	PrintList();

	puts("dequeue");
	Dequeue();
	PrintList();
	
	puts("dequeue");
	Dequeue();
	PrintList();
	puts("dequeue");
	Dequeue();
	PrintList();
	puts("dequeue");
	Dequeue();
	PrintList();*/
	//ReleseList();

	return 0;
}