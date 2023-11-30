//#include<stdio.h>
//#include<malloc.h>
//#include<string.h>
//
//typedef struct UserData
//{
//	const char* (*GetKey)(void*); 
//	//UserData 포인트시, 이 함수를 먼저 가르킨다
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
//	//의존성이 존재할 수 밖에 없다
//	UserData* pUser = pNode->user;
//
//	while (pNode->next != NULL)
//	{
//		printf("%s / 메모리 주소: [%p] / 다음 주소: [%p]\n", pUser->GetKey(pNode->user),pNode, pNode->next);
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
////pParam: 호출자가 메모리를 동적 할당해서 전달 + 값 설정까지 해서 전달
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
////아직은 자료의존성을 피하지 못함
////인자에 형식이 char* 일지 어떻게 알고?
//Node* FindNode(const char* data)
//{
//	Node* pNode = g_Head->next;
//	const char* (*pfGetKey)(void*) = NULL;
//
//	while (pNode->next != NULL)
//	{
//		//관리 대상 데이터 구조체 첫 번째 멤버가 함수 포인터임을 가정
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
//		puts("해당 노드는 존재하지않습니다.");
//		return 0;
//	}
//		
//
//	Del_Node->prev->next = Del_Node->next;
//	Del_Node->next->prev = Del_Node->prev;
//
//	
//	//메모리를 해제할때 얘도 해줘야한다
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
//	puts("Relase 진행");
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
//	printf("노드의 개수는: %d개\n", g_cntNode);
//	return g_cntNode;
//}
//
//Node* GetAt(int idx)
//{
//	if (idx > g_cntNode - 1 || idx < 0)
//	{
//		printf("idx범위를 잘 확인해주세요.\n");
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
//	//printf("0번 인덱스: %s\n",GetAt(0)->user->Name);
//	//printf("1번 인덱스: %s\n", GetAt(1)->user->Name);
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