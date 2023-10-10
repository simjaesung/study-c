#include<stdio.h>
#include<string.h>
#include<malloc.h>


typedef struct NODE
{
	char szData[64];
	struct NODE* next;
} NODE;

NODE* Head = NULL;

//연결 리스트 전체데이터 출력
void PrintList(void)
{
	NODE* pNode = Head;
	while (pNode != NULL)
	{
		printf("now: [%p] /%s, next[%p]\n", pNode, pNode->szData, pNode->next);
		pNode = pNode->next;
	}

	putchar('\n');
}

int IsEmpthy(void)
{
	if (Head == NULL)
		return 1;
	else
		return 0;
}

int InsertNewNode_Head(char* pszData)
{
	NODE* newNode = (NODE*)malloc(sizeof(NODE));
	memset(newNode, 0, sizeof(NODE));

	strcpy_s(newNode->szData, sizeof(newNode->szData), pszData);

	if (Head == NULL)
		Head = newNode;
	else
	{
		newNode->next = Head;
		Head = newNode;
	}

	return 1;
}

int InsertNewNode_Tail(char* pszData)
{
	NODE* pTmp = Head;

	while (pTmp->next != NULL)
	{
		pTmp = pTmp->next;
	}

	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	strcpy_s(NewNode->szData, sizeof(pszData), pszData);

	pTmp->next = NewNode;
	NewNode->next = NULL;
}

//find하는 경우는 삭제할떄가 가장 주된 이유이다. 따라서 앞전 주소를 반환해주는게 가장 효율적이다.
NODE* FindData(char* pszData)
{
	NODE* pTmp = Head;
	NODE* pPrev = NULL;

	while (pTmp != NULL)
	{
		if (strcmp(pTmp->szData, pszData) == 0)
		{
			return pPrev;
		}
		pPrev = pTmp;
		pTmp = pTmp->next;
	}
	return pPrev;
}

//해당 내용은 DeleteNode 부분에 포함되어있음
//반환형 NODE * 로 바꾼다음에 한번 다시 적용해보자. 이를 DeleteNode에도 적용해봅시다

//전체를 삭제하는 함수
void ReleaseList(void)
{
	NODE* pTmp = Head;
	while (pTmp != NULL)
	{
		NODE* pPrev = pTmp;
		pTmp = pTmp->next;
		free(pPrev);
	}
	Head = NULL; //추후 사용될 가능성이 있기 때문에, 아예 정보를 삭제하는 것은 무리가 있음
}

//우선 작성한 노드 삭제 함수(find 사용 X)

//int DeleteNode(char* pszData)
//{
//	NODE* pTmp = Head;
//	NODE* pPrev = NULL;
//
//	while (pTmp != NULL)
//	{
//		if ((strcmp(pTmp->szData, pszData)) == 0)
//		{
//			if (pTmp == Head) {
//				//헤드 변경
//				Head = pTmp->next;
//			}
//			else {
//				//삭제
//				pPrev->next = pTmp->next;
//				//pNode->next = NULL;
//			}
//			free(pTmp);
//			printf("해당 Node를 삭제하였습니다.\n");
//			return 1;
//		}
//		pPrev = pTmp;
//		pTmp = pTmp->next;
//	}
//	printf("해당 Node는 존재하지 않습니다.\n");
//	return 0;
//}

int DeleteNode(char* pszData)
{
	NODE* prev = FindData(pszData);

	if (IsEmpthy()) {
		printf("빈 리스트입니다.\n");
		return 0;
	}
		
	if (prev) {
		NODE* Del_Node = prev->next;
		prev->next = Del_Node->next;
		free(Del_Node);
	}
	else {
		NODE* Del_Node = Head;
		Head = Del_Node->next;
		//Del_Node = NULL;
		free(Del_Node);
	} 
	//prev값이 NULL이면, 삭제되는 노드가 헤드이거나 빈리스트인 2가지 경우이다.
	//빈리스트에서 Head 연산을 어떻게 해줘도 결과는 빈리스트이다
	return 1; //삭제를 하던 말던 1 반환
	
}

int Push(char* pszData)
{
	InsertNewNode_Head(pszData);
}


void Pop(void)
{
	DeleteNode(Head->szData);
}

int main(void)
{
	DeleteNode("TEST3");
	Push("TEST1");
	PrintList();
	Push("TEST2");
	PrintList();
	Push("TEST3");
	PrintList();
	Pop();
	Pop();
	Pop();
	//Pop();

	PrintList();
	Push("TEST4");
	PrintList();
	Pop();
	PrintList();
	return 0;
}