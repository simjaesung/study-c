#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct UserData
{
	char Name[12]; //key
	char Phone[20];
}UserData;


const char* GetKeyFromUserData(UserData* pUser)
{
	return pUser->Name;
}

void* CreateUserData(const char* pszName, const char* pszPhone)
{
	UserData* pNewData = (UserData*)malloc(sizeof(UserData));
	memset(pNewData, 0, sizeof(UserData));
	strcpy_s(pNewData->Name, sizeof(pNewData->Name), pszName);
	strcpy_s(pNewData->Phone, sizeof(pNewData->Phone), pszPhone);


	return pNewData;
}

typedef struct Node
{
	//관리 대상 자료
	void* user;

	//멤버 함수 포인터
	const char* (*GetKey)(void*);

	//자료구조
	struct Node* prev;
	struct Node* next;
}Node;


Node* g_Head = NULL;
Node* g_Tail = NULL;
int g_cntNode;


void PrintList()
{
	Node* pNode = g_Head->next;

	while (pNode->next != NULL)
	{
		//printf("%s의 전화번호: %s / 메모리 주소: [%p] / 다음 주소: [%p]\n", pNode->user->Name, pNode->user->Phone, pNode, pNode->next);
		printf("%s의 / 메모리 주소: [%p] / 다음 주소: [%p]\n", pNode->GetKey(pNode->user), pNode, pNode->next);
		pNode = pNode->next;
	}
	putchar('\n');
}


void InitList()
{
	g_Head = (Node*)malloc(sizeof(Node));
	g_Tail = (Node*)malloc(sizeof(Node));
	g_cntNode = 0;

	memset(g_Head, 0, sizeof(Node));
	memset(g_Tail, 0, sizeof(Node));


	/*strcpy_s(g_Head->Buffer, sizeof("DUMMY_Head"), "DUMMY_Head");
	strcpy_s(g_Tail->Buffer, sizeof("DUMMY_Tail"), "DUMMY_Tail");*/

	g_Head->prev = NULL;
	g_Head->next = g_Tail;
	g_Tail->prev = g_Head;
	g_Tail->next = NULL;
}


//pParam: 호출자가 메모리를 동적 할당해서 전달 + 값 설정까지 해서 전달
void Push_Head(void* pParam, const char* (*pfParam)(void*)) //자료 특정 X
{
	Node* new_head = (Node*)malloc(sizeof(Node));
	memset(new_head, 0, sizeof(Node));

	//관리 대상 자료에 관한 초기화
	new_head->user = pParam;
	new_head->GetKey = pfParam;


	//연결 리스트에 관한 초기화
	new_head->next = g_Head->next;
	new_head->prev = g_Head;
	new_head->next->prev = new_head;
	new_head->prev->next = new_head;

	g_cntNode++;
}

void Push_Tail(void* pParam, const char* (*pfParam)(void*))
{
	Node* new_tail = (Node*)malloc(sizeof(Node));
	memset(new_tail, 0, sizeof(Node));

	new_tail->user = pParam;
	new_tail->GetKey = pfParam;

	//strcpy_s(new_head->Buffer, sizeof(data), data);

	new_tail->next = g_Tail;
	new_tail->prev = g_Tail->prev;
	new_tail->next->prev = new_tail;
	new_tail->prev->next = new_tail;

	g_cntNode++;
}


//아직은 자료의존성을 피하지 못함
//인자에 형식이 char* 일지 어떻게 알고?
Node* FindNode(const char* pszKey)
{
	Node* pNode = g_Head->next;

	while (pNode->next != NULL)
	{
		if (strcmp(pNode->GetKey(pNode->user), pszKey) == 0)
			return pNode;
		pNode = pNode->next;
	}
	return NULL;
}


int DeleteNode(const char* pszKey)
{
	Node* Del_Node = FindNode(pszKey);


	if (Del_Node == NULL)
	{
		puts("해당 노드는 존재하지않습니다.");
		return 0;
	}


	Del_Node->prev->next = Del_Node->next;
	Del_Node->next->prev = Del_Node->prev;


	//메모리를 해제할때 얘도 해줘야한다
	free(Del_Node->user);
	free(Del_Node);
	g_cntNode--;

	return 1;
}


void RelaseList()
{
	puts("Relase 진행");

	Node* pNode = g_Head;

	while (pNode != NULL)
	{
		Node* Del_Node = pNode;
		pNode = pNode->next;
		free(Del_Node->user);
		free(Del_Node);
	}
	g_cntNode = 0;
	g_Head = NULL;
	g_Tail = NULL;
}

int GetSize()
{
	printf("노드의 개수는: %d개\n", g_cntNode);
	return g_cntNode;
}

Node* GetAt(int idx)
{
	if (idx > g_cntNode - 1 || idx < 0)
	{
		printf("idx범위를 잘 확인해주세요.\n");
		return NULL;
	}


	Node* pNode = g_Head->next;
	int cnt = 0;

	while (pNode->next != NULL)
	{
		if (cnt == idx)
			return pNode;
		cnt++;
		pNode = pNode->next;
	}

	return NULL;
}

int InsertAt(int idx, void* pData, const char* (*pfParam)(void*))
{
	Node* pNode = GetAt(idx);

	if (pNode == NULL)
		return 0;

	Node* newNode = (Node*)malloc(sizeof(Node));
	memset(newNode, 0, sizeof(Node));
	newNode->user = pData;
	newNode->GetKey = pfParam;

	newNode->next = pNode;
	newNode->prev = pNode->prev;

	pNode->prev->next = newNode;
	pNode->prev = newNode;

	g_cntNode++;
	return 1;
}


int main(void)
{ 
	InitList();

	UserData* pNewData = CreateUserData("Jae-Sung", "01082904285");
	UserData* pNewData2 = CreateUserData("Eun-ji", "01012345678");
	UserData* pNewData3 = CreateUserData("sorry", "01082904285");
	
	Push_Head(pNewData,GetKeyFromUserData);
	Push_Head(pNewData2, GetKeyFromUserData);
	Push_Tail(pNewData3, GetKeyFromUserData); 

	PrintList();

	/*printf("0번 인덱스: %s\n", GetAt(0)->user->Name);
	printf("1번 인덱스: %s\n", GetAt(1)->user->Name);*/


	/*if (GetAt(3) != NULL)
		InsertAt(3, pNewData3, GetKeyFromUserData);*/

	puts("\nidx 2번에 tlawogus 추가");
	UserData* user5 = CreateUserData("tlawogus", "01058824285");
	InsertAt(2, user5, GetKeyFromUserData(user5));

	PrintList();

	RelaseList();
	GetSize();
}