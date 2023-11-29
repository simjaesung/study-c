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
	//���� ��� �ڷ�
	void* user;

	//��� �Լ� ������
	const char* (*GetKey)(void*);

	//�ڷᱸ��
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
		//printf("%s�� ��ȭ��ȣ: %s / �޸� �ּ�: [%p] / ���� �ּ�: [%p]\n", pNode->user->Name, pNode->user->Phone, pNode, pNode->next);
		printf("%s�� / �޸� �ּ�: [%p] / ���� �ּ�: [%p]\n", pNode->GetKey(pNode->user), pNode, pNode->next);
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


//pParam: ȣ���ڰ� �޸𸮸� ���� �Ҵ��ؼ� ���� + �� �������� �ؼ� ����
void Push_Head(void* pParam, const char* (*pfParam)(void*)) //�ڷ� Ư�� X
{
	Node* new_head = (Node*)malloc(sizeof(Node));
	memset(new_head, 0, sizeof(Node));

	//���� ��� �ڷῡ ���� �ʱ�ȭ
	new_head->user = pParam;
	new_head->GetKey = pfParam;


	//���� ����Ʈ�� ���� �ʱ�ȭ
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


//������ �ڷ��������� ������ ����
//���ڿ� ������ char* ���� ��� �˰�?
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
		puts("�ش� ���� ���������ʽ��ϴ�.");
		return 0;
	}


	Del_Node->prev->next = Del_Node->next;
	Del_Node->next->prev = Del_Node->prev;


	//�޸𸮸� �����Ҷ� �굵 ������Ѵ�
	free(Del_Node->user);
	free(Del_Node);
	g_cntNode--;

	return 1;
}


void RelaseList()
{
	puts("Relase ����");

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
	printf("����� ������: %d��\n", g_cntNode);
	return g_cntNode;
}

Node* GetAt(int idx)
{
	if (idx > g_cntNode - 1 || idx < 0)
	{
		printf("idx������ �� Ȯ�����ּ���.\n");
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

	/*printf("0�� �ε���: %s\n", GetAt(0)->user->Name);
	printf("1�� �ε���: %s\n", GetAt(1)->user->Name);*/


	/*if (GetAt(3) != NULL)
		InsertAt(3, pNewData3, GetKeyFromUserData);*/

	puts("\nidx 2���� tlawogus �߰�");
	UserData* user5 = CreateUserData("tlawogus", "01058824285");
	InsertAt(2, user5, GetKeyFromUserData(user5));

	PrintList();

	RelaseList();
	GetSize();
}