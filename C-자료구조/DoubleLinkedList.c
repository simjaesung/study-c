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
		printf("Index: %d, ���� ����� �ּҿ� ��: %p / %s, ���� ����� �ּҿ� ��: %p / %s\n", index,pNode, pNode->pszData, pNode->next, pNode->next->pszData);

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
//�б⸸ �� �����̱⿡ ����� ������ �����صθ� ����
//int ��ȯ ��, ���� ���п��� + �ε��� ��ȯ ����
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
		printf("index ������ �ʰ��߽��ϴ�. ���� ������: %d\n",g_nSize);
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
//�ش� �ε����� ��带 �Ҵ��ϴ� �Լ�
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

	puts("TEST 1,2 ������");
	InsertAtHead("TEST1");
	InsertAtHead("TEST2");
	PrintList();

	puts("TEST 3,4 ��������");
	InsertAtTail("TEST3");
	InsertAtTail("TEST4");
	PrintList();

	puts("TEST 3,4 ��� ã��");
	printf("TEST3 ��� ã��:%s\n", FindNode("TEST3"));
	printf("TEST4 ��� ã��:%s\n", FindNode("TEST4"));

	puts("idx 1�� ã��");
	printf("1�� �ε��� ���:%s\n", GetAt(1)->pszData);
	
	puts("idx 2�� ã��");
	printf("1�� �ε��� ���:%s\n", GetAt(2)->pszData);

	puts("idx 6�� ã��");
	printf("6�� �ε��� ���:%s\n", GetAt(6)->pszData);


	puts("idx 2���� TEST7 �߰�");
	printf("2�� �ε��� ���:%s\n", GetAt(2)->pszData);
	InsertAt(2, "TEST7");
	PrintList();

	puts("idx 4���� TEST9 �߰�");
	printf("4�� �ε��� ���:%s\n", GetAt(4)->pszData);
	InsertAt(4, "TEST9");
	PrintList();

	puts("idx 10�� �ڿ� TEST8 �߰�");
	InsertAt(10, "TEST8");
	PrintList();

	puts("TEST 1����");
	DeleteNode("TEST1");
	PrintList();

	puts("TEST 4����");
	DeleteNode("TEST4");
	PrintList();

	puts("TEST 2����");
	DeleteNode("TEST2");
	PrintList();

	puts("��ü����Ʈ �ʱ�ȭ");
	ReleaseList();

	printf("\n���� ��� ����: %d\n", g_nSize);

	return 0;
}