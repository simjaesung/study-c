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
		printf("현재 노드 값 및 주소: [ %s / %p ] / 다음 노드 주소 : [ %p ]\n ", ptmp->Data, ptmp,ptmp->next);
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

	//pPrev 노드가 존재하지 않는 경우
	//pPrev가 NULL일 경우는 Head일 경우와 존재하지않는 경우 2가지임

	if (pPrev == NULL && pPrev != &Dum_Node)
	{
		puts("해당 노드를 찾을 수 없습니다.");
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
	//&Dum_Node.next라는 말이 애초에 안되는 것

	//Node* ptmp = &Dum_Node; -> 더미노드 사용은 되도록 지양
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


//Stack 구현
int push(char* data)
{
	Push_Head(data);
}

int pop()
{
	if (Dum_Node.next == NULL)
	{
		puts("빈 Stack입니다.");
		return NULL;
	}

	Del_Node(Dum_Node.next->Data);

	return 1;
}

//queue 구현
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
	//Stack 테스트
	puts("TEST1 푸시");
	push("TEST1");
	PrintList();
	
	puts("TEST2 푸시");
	push("TEST2");
	PrintList();
	
	puts("TEST3 푸시");
	push("TEST3");
	PrintList();
	

	puts("TEST3 삭제");
	Del_Node("TEST3");
	PrintList();

	puts("pop 진행");
	pop();
	PrintList();

	puts("pop 진행");
	pop();
	PrintList();

	puts("pop 진행");
	pop();
	PrintList();
	

	//queue 테스트
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