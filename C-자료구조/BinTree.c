#include<stdio.h>
#include<malloc.h>
#include<string.h>
#include<stdlib.h>

typedef struct Node
{
	char pszData[32];

	struct Node* left;
	struct Node* right;
} Node;


Node* g_pRoot;
int g_nSize;

void ReleaseTree(Node* pParent)
{
	if (pParent == NULL)
	{
		return;
	}
	
	//child 부터 삭제
	ReleaseTree(pParent->left);
	ReleaseTree(pParent->right);

	printf("[DELETE] 노드: %s / 주소: %p\n", pParent->pszData, pParent);
	free(pParent);
	g_nSize -= 1;
	g_pRoot = NULL;
}

int IsEmpty(void)
{
	if (g_nSize == 0)
		return 1;
	else
		return 0;
}

void PrintTree(Node* pParent)
{
	if (pParent == NULL)
	{
		return;
	}

	PrintTree(pParent->left);
	printf("%s 노드 / 주소: %p\n", pParent->pszData, pParent);
	PrintTree(pParent->right);
}

Node* FindNode(const char* pszData)
{
	Node* pTmp = g_pRoot;
	while (pTmp != NULL)
	{
		//값비교하기
		int cmp = strcmp(pTmp->pszData, pszData);
		if (cmp == 0)
		{
			return pTmp;
		}
		else
		{
			if (cmp < 0)
				pTmp = pTmp->right;
			else
				pTmp = pTmp->left;
		}
	}
	return NULL;
}

int DeleteByMerging(const char* pszData)
{
	if (FindNode(pszData) == NULL)
	{
		puts("해당 노드는 존재하지 않습니다.");
		return 0;
	}

	Node* pTmp = g_pRoot;
	Node* pPTmp = NULL; //pTmp 부모 저장

	while (pTmp != NULL) 
		//pTmp의 부모를 찾기 위한 작업 / 이럴꺼면 FindNode함수 반환을 부모로 하는게 나을지도?
	{
		int cmp = strcmp(pTmp->pszData, pszData);
		if (cmp == 0) break;
		else
		{
			pPTmp = pTmp; //pTmp의 부모노드 저장
			if (cmp < 0) pTmp = pTmp->right;
			else pTmp = pTmp->left;
		}
	}

	if (pTmp->left == NULL) //왼쪽 자식이 없을 때
	{
		if (pTmp == g_pRoot) g_pRoot = pTmp->right;
		else
		{
			if (strcmp(pPTmp->pszData, pTmp->pszData) < 0) //pTmp가 pPTmp의 왼쪽 자식? 오른쪽 자식?
				pPTmp->right = pTmp->right; //pTmp의 데이터가 더 클 시, 오른쪽 자식
			else
				pPTmp->left = pTmp->right; //pTmp의 데이터가 더 클 시, 왼쪽 자식
		}

		free(pTmp);
		g_nSize -= 1;
		return 1;
	}
	else
	{
		Node* pLTmp = pTmp->left;
		while (pLTmp->right != NULL)
			pLTmp = pLTmp->right;

		pLTmp->right = pTmp->right;

		if (pTmp == g_pRoot) g_pRoot = pTmp->left;
		else
		{
			if (strcmp(pPTmp->pszData, pTmp->pszData) < 0)
				pPTmp->right = pTmp->left;
			else
				pPTmp->left = pTmp->left;
		}

		free(pTmp);
		g_nSize -= 1;
		return 1;
	}

	puts("삭제 실패");
	return 0;
}

int DeleteByCopying(const char* pszData)
{

	return 0;
}

int InsertNode(const char* pszData)
{
	Node* pNewNode = (Node*)malloc(sizeof(Node));
	memset(pNewNode, 0, sizeof(Node));
	strcpy_s(pNewNode->pszData, sizeof(pNewNode->pszData), pszData);

	if (g_pRoot == NULL)
	{
		g_pRoot = pNewNode;
		g_nSize += 1;
		return 1;
	}
	else
	{
		Node* pTmp = g_pRoot; 
		while (pTmp != NULL)
		{
			//값비교하기
			if (strcmp(pTmp->pszData,pNewNode->pszData) < 0)
			{
				if (pTmp->right == NULL)
				{
					pTmp->right = pNewNode;
					g_nSize += 1;
					return 1;
				}
				else
					pTmp = pTmp->right;
			}
			else
			{
				if (pTmp->left == NULL)
				{
					pTmp->left = pNewNode;
					g_nSize += 1;
					return 1;
				}
				else
					pTmp = pTmp->left;
			}
		}
	}
	return 0;
}


int GetSize(void)
{
	return g_nSize;
}


int main()
{
	InsertNode("5번 항목");
	InsertNode("4번 항목");
	InsertNode("7번 항목");
	InsertNode("6번 항목");
	InsertNode("8번 항목");

	
	PrintTree(g_pRoot);
	//printf("[주소]: %p / [Data]: %s\n", FindNode("7번 항목"),FindNode("7번 항목")->pszData);
	//printf("[주소]: %p / [Data]: %s\n", FindNode("8번 항목"), FindNode("8번 항목")->pszData);
	printf("size: %d\n",GetSize());

	puts("\n6번항목 삭제");
	DeleteByMerging("6번 항목");
	PrintTree(g_pRoot);
	//printf("size: %d\n", GetSize());

	ReleaseTree(g_pRoot);
	printf("size: %d\n", GetSize());
	PrintTree(g_pRoot);
	return 0;
}