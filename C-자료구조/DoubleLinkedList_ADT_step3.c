//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct UserData
//{
//	const char* (*GetKey)(void*); 
//	//UserData ����Ʈ��, �� �Լ��� ���� ����Ų��
//	
//	char Name[70]; //Key
//	char Phone[70];
//}UserData;
//
//const char* GetKeyUserData(UserData* pUser)
//{
//	return pUser->Name;
//}
//
//UserData* CreateUser(char* pszName, char* pszPhone)
//{
//	UserData* user = (UserData*)malloc(sizeof(UserData));
//	memset(user, 0, sizeof(UserData));
//
//	strcpy_s(user->Name, sizeof(user->Name), pszName);
//	strcpy_s(user->Phone, sizeof(user->Phone), pszPhone);
//
//	user->GetKey = GetKeyUserData;
//
//	return user;
//}
//
//typedef struct Node
//{
//	void* user;
//
//	struct Node* prev;
//	struct Node* next;
//}Node;
//
//
//Node* g_Head = NULL;
//Node* g_Tail = NULL;
//int g_cntNode;
//
//
//void PrintList()
//{
//	Node* pNode = g_Head->next;
//
//	//�������� ������ �� �ۿ� ����
//	UserData* pUser = pNode->user;
//
//	while (pNode->next != NULL)
//	{
//		printf("%s / �޸� �ּ�: [%p] / ���� �ּ�: [%p]\n", pUser->GetKey(pNode->user),pNode, pNode->next);
//		pNode = pNode->next;
//	}
//	putchar('\n');
//}
//
//
//void InitList()
//{
//	g_Head = (Node*)malloc(sizeof(Node));
//	g_Tail = (Node*)malloc(sizeof(Node));
//	g_cntNode = 0;
//
//	memset(g_Head, 0, sizeof(Node));
//	memset(g_Tail, 0, sizeof(Node));
//	
//
//	/*strcpy_s(g_Head->Buffer, sizeof("DUMMY_Head"), "DUMMY_Head");
//	strcpy_s(g_Tail->Buffer, sizeof("DUMMY_Tail"), "DUMMY_Tail");*/
//
//	g_Head->prev = NULL;
//	g_Head->next = g_Tail;
//	g_Tail->prev = g_Head;
//	g_Tail->next = NULL;
//}
//
//
////pParam: ȣ���ڰ� �޸𸮸� ���� �Ҵ��ؼ� ���� + �� �������� �ؼ� ����
//void Push_Head(void* pData)
//{
//	Node* new_head = (Node*)malloc(sizeof(Node));
//	memset(new_head, 0, sizeof(Node));
//
//	new_head->user = pData;
//
//	new_head->next = g_Head->next;
//	new_head->prev = g_Head;
//	new_head->next->prev = new_head;
//	new_head->prev->next = new_head;
//
//	g_cntNode++;
//}
//
//void Push_Tail(void* pData)
//{
//	Node* new_tail = (Node*)malloc(sizeof(Node));
//	memset(new_tail, 0, sizeof(Node));
//	
//	new_tail->user = pData;
//
//	new_tail->next = g_Tail;
//	new_tail->prev = g_Tail->prev;
//	new_tail->next->prev = new_tail;
//	new_tail->prev->next = new_tail;
//
//	g_cntNode++;
//}
//
//
////������ �ڷ��������� ������ ����
////���ڿ� ������ char* ���� ��� �˰�?
//Node* FindNode(const char* data)
//{
//	Node* pNode = g_Head->next;
//	const char* (*pfGetKey)(void*) = NULL;
//
//	while (pNode->next != NULL)
//	{
//		//���� ��� ������ ����ü ù ��° ����� �Լ� ���������� ����
//		pfGetKey = pNode->user;
//
//		if (strcmp(GetKeyUserData(pNode->user), data) == 0)
//			return pNode;
//
//		/*if (strcmp(pfGetKey(pNode->user), data) == 0)
//			return pNode;*/
//
//		pNode = pNode->next;
//	}
//	return NULL;
//}
//
//
//int DeleteNode(const char* data)
//{
//	Node* Del_Node = FindNode(data);
//	
//
//	if (Del_Node == NULL)
//	{
//		puts("�ش� ���� ���������ʽ��ϴ�.");
//		return 0;
//	}
//		
//
//	Del_Node->prev->next = Del_Node->next;
//	Del_Node->next->prev = Del_Node->prev;
//
//	
//	//�޸𸮸� �����Ҷ� �굵 ������Ѵ�
//	free(Del_Node->user);
//	free(Del_Node);
//	g_cntNode--;
//
//	return 1;
//}
//
//
//void RelaseList()
//{
//	puts("Relase ����");
//
//	Node* pNode = g_Head;
//
//	while (pNode != NULL)
//	{
//		Node* Del_Node = pNode;
//		pNode = pNode->next;
//		free(Del_Node->user);
//		free(Del_Node);
//	}
//	g_cntNode = 0;
//	g_Head = NULL;
//	g_Tail = NULL;
//}
//
//int GetSize()
//{
//	printf("����� ������: %d��\n", g_cntNode);
//	return g_cntNode;
//}
//
//Node* GetAt(int idx)
//{
//	if (idx > g_cntNode - 1 || idx < 0)
//	{
//		printf("idx������ �� Ȯ�����ּ���.\n");
//		return NULL;
//	}
//
//
//	Node* pNode = g_Head->next;
//	int cnt = 0;
//
//	while (pNode->next != NULL)
//	{
//		if (cnt == idx)
//			return pNode;
//		cnt++;
//		pNode = pNode->next;
//	}
//
//	return NULL;
//}
//
//int InsertAt(int idx, void* pData)
//{
//	Node* pNode = GetAt(idx);
//
//	if (pNode == NULL)
//		return 0;
//
//	Node* newNode = (Node*)malloc(sizeof(Node));
//	memset(newNode, 0, sizeof(Node));
//
//	newNode->user = pData;
//
//	newNode->next = pNode;
//	newNode->prev = pNode->prev;
//
//	pNode->prev->next = newNode;
//	pNode->prev = newNode;
//
//	g_cntNode++;
//	return 1;
//}
//
//
//int main(void)
//{
//	InitList();
//	
//	UserData* pNewData1 = CreateUser("Jae-Sung", "01082904285");
//	UserData* pNewData2 = CreateUser("Eun-ji", "01063752717");
//	UserData* pNewData3 = CreateUser("sorry", "01082904285");
//
//	Push_Head(pNewData1);
//	Push_Head(pNewData2);
//	Push_Tail(pNewData3);
//
//	PrintList();
//
//	//printf("0�� �ε���: %s\n",GetAt(0)->user->Name);
//	//printf("1�� �ε���: %s\n", GetAt(1)->user->Name);
//	UserData* pNewData4 = CreateUser("shong", "heisdog");
//	if (GetAt(2)!=NULL)
//		InsertAt(2, pNewData4);
//	 
//	PrintList();
//	printf("test: %s\n", pNewData1->GetKey(pNewData1));
//	DeleteNode("sorry");
//	PrintList();
//	
//	RelaseList();
//	GetSize();
//}