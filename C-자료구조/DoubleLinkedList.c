#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct Node
{
	char pszData[32];
	struct Node* next;
	struct Node* prev;
} Node;

Node* g_pHead;
Node* g_pTail;

int g_nSize;

void InitList(void)
{
	g_pHead = (Node*)malloc(sizeof(Node));
	g_pTail = (Node*)malloc(sizeof(Node));

	memset(g_pHead, 0, sizeof(Node));
	memset(g_pTail, 0, sizeof(Node));

	g_pHead->next = g_pTail;
	g_pHead->prev = NULL;

	g_pTail->next = NULL;
	g_pTail->prev = g_pHead;

	strcpy_s(g_pHead->pszData, sizeof(g_pHead->pszData), "DUMMY");
	strcpy_s(g_pTail->pszData, sizeof(g_pTail->pszData), "DUMMY");

	g_nSize = 0;
}

void ReleaseList(void)
{
	Node* pNode = g_pHead;

	while (pNode != NULL)
	{
		Node* Del_Node = pNode;

		pNode = pNode->next;
		free(Del_Node);
	}

	g_nSize = 0;
}

int IsEmpty(void)
{
	if (g_nSize==0)
		return 1;
	else
		return 0;
}

void PrintList(void)
{
	printf("\nPrintList(): g_nSize: %d, g_pHead [%p], g_Tail[%p]\n", g_nSize, g_pHead, g_pTail);
	Node* pNode = g_pHead;
	int index = -1;
	while (pNode != g_pTail)
	{
		printf("Index: %d, 현재 노드의 주소와 값: %p / %s, 다음 노드의 주소와 값: %p / %s\n", index,pNode, pNode->pszData, pNode->next, pNode->next->pszData);

		pNode = pNode->next;
		index += 1;
	}
}

Node* FindNode(const char* pszData)
{
	Node* pNode = g_pHead->next;

	while (pNode != g_pTail)
	{
		if (strcmp(pNode->pszData, pszData) == 0)
			return pNode;

		pNode = pNode->next;
	}
	
	return NULL;
}

int DeleteNode(const char* pszData)
{
	Node* pNode = FindNode(pszData);

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	free(pNode);

	g_nSize -= 1;

	return 0;
}

int InsertAtHead(const char* pszData)
//읽기만 할 변수이기에 상수형 변수로 설정해두면 좋다
//int 반환 시, 성공 실패여부 + 인덱스 반환 가능
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));

	strcpy_s(newNode->pszData, sizeof(pszData), pszData);

	if (IsEmpty()) {
		newNode->prev = g_pHead;
		newNode->next = g_pTail;

		g_pHead->next = newNode;
		g_pTail->prev = newNode;

		g_nSize += 1;
		return 1;
	}

	else {
		newNode->prev = g_pHead;
		newNode->next = g_pHead->next;

		g_pHead->next->prev = newNode;
		g_pHead->next = newNode;

		g_nSize += 1;
		return 1;
	}


	return 0;
}

int InsertAtTail(const char* pszData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));

	strcpy_s(newNode->pszData,sizeof(pszData), pszData);

	if (IsEmpty()) {
		newNode->prev = g_pHead;
		newNode->next = g_pTail;

		g_pHead->next = newNode;
		g_pTail->prev = newNode;

		g_nSize += 1;
		return 1;
	}

	else {
		newNode->prev = g_pTail->prev;
		newNode->next = g_pTail;

		g_pTail->prev->next = newNode;
		g_pTail->prev = newNode;

		g_nSize += 1;
		return 1;
	}

	return 0;
}


Node* GetAt(int idx)
{
	if (idx > g_nSize - 1 || idx < 0)
	{
		printf("index 범위가 초과했습니다. 현재 사이즈: %d\n",g_nSize);
		return NULL;
	}

	int tmp = 0;
	Node* pNode = g_pHead->next;

	while (pNode != g_pTail)
	{
		if (tmp == idx)
			return pNode;

		pNode = pNode->next;
		tmp += 1;
	}
	

	return NULL;
}

int InsertAt(int idx, const char* pszData)
//해당 인덱스로 노드를 할당하는 함수
{
	Node* pNode = GetAt(idx);

	if (pNode) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		memset(newNode, 0, sizeof(Node));

		strcpy_s(newNode->pszData, sizeof(pszData), pszData);

		newNode->prev = pNode->prev;
		newNode->next = pNode;

		pNode->prev->next = newNode;
		pNode->prev = newNode;
		

		g_nSize += 1;

		return 1;
	}

	return 0;
}


int GetSize(void)
{
	return g_nSize;
}


int main()
{
	InitList();

	puts("TEST 1,2 헤드삽입");
	InsertAtHead("TEST1");
	InsertAtHead("TEST2");
	PrintList();

	puts("TEST 3,4 꼬리삽입");
	InsertAtTail("TEST3");
	InsertAtTail("TEST4");
	PrintList();

	puts("TEST 3,4 노드 찾기");
	printf("TEST3 노드 찾기:%s\n", FindNode("TEST3"));
	printf("TEST4 노드 찾기:%s\n", FindNode("TEST4"));

	puts("idx 1번 찾기");
	printf("1번 인덱스 노드:%s\n", GetAt(1)->pszData);
	
	puts("idx 2번 찾기");
	printf("1번 인덱스 노드:%s\n", GetAt(2)->pszData);

	puts("idx 6번 찾기");
	printf("6번 인덱스 노드:%s\n", GetAt(6)->pszData);


	puts("idx 2번에 TEST7 추가");
	printf("2번 인덱스 노드:%s\n", GetAt(2)->pszData);
	InsertAt(2, "TEST7");
	PrintList();

	puts("idx 4번에 TEST9 추가");
	printf("4번 인덱스 노드:%s\n", GetAt(4)->pszData);
	InsertAt(4, "TEST9");
	PrintList();

	puts("idx 10번 뒤에 TEST8 추가");
	InsertAt(10, "TEST8");
	PrintList();

	puts("TEST 1삭제");
	DeleteNode("TEST1");
	PrintList();

	puts("TEST 4삭제");
	DeleteNode("TEST4");
	PrintList();

	puts("TEST 2삭제");
	DeleteNode("TEST2");
	PrintList();

	puts("전체리스트 초기화");
	ReleaseList();

	printf("\n남은 노드 개수: %d\n", g_nSize);

	return 0;
}