#include<stdio.h>
#include<malloc.h>
#include<string.h>


typedef struct UserData {
	char pszData[32];
} UserData;


typedef struct Node
{
	UserData* pData;
	
	struct Node* next;
	struct Node* prev;
} Node;

Node* g_pHead;
Node* g_pTail;

int g_nSize;


//UserData구조체를 만드는 함수
UserData* MakeUserData(char* pszData)
{
	UserData* userData = (UserData*)malloc(sizeof(UserData));
	memset(userData, 0, sizeof(userData));

	strcpy_s(userData->pszData, sizeof(pszData), pszData);

	return userData;

}

void InitList(void)
{
	g_pHead = (Node*)malloc(sizeof(Node));
	g_pTail = (Node*)malloc(sizeof(Node));

	g_pHead->next = g_pTail;
	g_pHead->prev = NULL;

	g_pTail->prev = g_pHead;
	g_pTail->next = NULL;


	g_pHead->pData = MakeUserData("Head");
	g_pTail->pData = MakeUserData("Tail");

	g_nSize = 0;
}

void ReleaseList(void)
{
	Node* pNode = g_pHead;

	while (pNode != NULL)
	{
		Node* Del_Node = pNode;

		pNode = pNode->next;

		free(Del_Node->pData);
		free(Del_Node);
	}

	g_nSize = 0;
}

int IsEmpty(void)
{
	if (g_nSize == 0)
		return 1;
	else
		return 0;
}

void PrintList(void)
{
	printf("PrintList(): g_nSize: %d, g_pHead [%p], g_Tail[%p]\n", g_nSize, g_pHead, g_pTail);
	Node* pNode = g_pHead->next;
	while (pNode != g_pTail)
	{
		printf("현재 노드의 주소와 값: %p / %s, 다음 노드의 주소와 값: %p / %s\n",
			pNode, pNode->pData->pszData, pNode->next, pNode->next->pData->pszData);

		pNode = pNode->next;
	}
}

//찾는 인자값의 수정을 사전에 방지
Node* FindNode(const char* pszFindData)
{
	Node* pNode = g_pHead->next;

	while (pNode != g_pTail)
	{
		if (strcmp(pNode->pData->pszData, pszFindData) == 0)
			return pNode;

		pNode = pNode->next;
	}

	return NULL;
}

int DeleteNode(const char* pszData)
{
	Node* pNode = FindNode(pszData);

	if (pNode == NULL)
		return 0;

	pNode->prev->next = pNode->next;
	pNode->next->prev = pNode->prev;

	free(pNode->pData);
	free(pNode);

	g_nSize -= 1;

	return 1;
}

int InsertAtHead(UserData* pData)
//읽기만 할 변수이기에 상수형 변수로 설정해두면 좋다
//int 반환 시, 성공 실패여부 + 인덱스 반환 가능
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));

	newNode->pData = pData;


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

int InsertAtTail(UserData* pData)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));

	newNode->pData = pData;

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
		printf("index 범위가 초과했습니다. 현재 사이즈: %d\n", g_nSize);
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

int InsertAt(int idx, UserData* pData)
//해당 인덱스로 노드를 할당하는 함수
{
	Node* pNode = GetAt(idx);

	if (pNode) {
		Node* newNode = (Node*)malloc(sizeof(Node));
		memset(newNode, 0, sizeof(Node));

		newNode->pData = pData;

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

	//PrintList();

	puts("\nTEST 1,2 헤드삽입");
	
	InsertAtHead(MakeUserData("TEST1"));
	InsertAtHead(MakeUserData("TEST2"));
	PrintList();

	puts("\nTEST 3,4 꼬리삽입");
	InsertAtHead(MakeUserData("TEST3"));
	InsertAtHead(MakeUserData("TEST4"));
	PrintList();

	puts("\nTEST 3,4 노드 찾기");
	printf("TEST3 노드 찾기:%p\n", FindNode("TEST3"));
	printf("TEST4 노드 찾기:%p\n", FindNode("TEST4"));
	PrintList();

	puts("\nidx 1번 찾기");
	printf("1번 인덱스 노드의 주소:%p\n", GetAt(1));

	puts("\nidx 2번 찾기");
	printf("2번 노드의 주소:%p\n", GetAt(2));

	puts("\nidx 6번 찾기");
	printf("6번 인덱스 노드의 주소:%p\n", GetAt(6));


	puts("\nidx 2번에 TEST7 추가");
	InsertAt(2, MakeUserData("TEST7"));
	PrintList();

	puts("\nidx 4번에 TEST9 추가");
	
	InsertAt(4, MakeUserData("TEST9"));
	PrintList();

	puts("\nidx 10번 뒤에 TEST8 추가");
	InsertAt(10, MakeUserData("TEST8"));
	PrintList();

	puts("\nTEST 1삭제");
	DeleteNode("TEST1");
	PrintList();

	puts("\nTEST 4삭제");
	DeleteNode("TEST4");
	PrintList();

	puts("\nTEST 2삭제");
	DeleteNode("TEST2");
	PrintList();

	puts("\n전체리스트 초기화");
	ReleaseList();
	PrintList();

	printf("\n남은 노드 개수: %d\n", g_nSize);

	return 0;
}