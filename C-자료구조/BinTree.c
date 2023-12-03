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
	
	//child ���� ����
	ReleaseTree(pParent->left);
	ReleaseTree(pParent->right);

	printf("[DELETE] ���: %s / �ּ�: %p\n", pParent->pszData, pParent);
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
	printf("%s ��� / �ּ�: %p\n", pParent->pszData, pParent);
	PrintTree(pParent->right);
}

Node* FindNode(const char* pszData)
{
	Node* pTmp = g_pRoot;
	while (pTmp != NULL)
	{
		//�����ϱ�
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
		puts("�ش� ���� �������� �ʽ��ϴ�.");
		return 0;
	}

	Node* pTmp = g_pRoot;
	Node* pPTmp = NULL; //pTmp �θ� ����

	while (pTmp != NULL) 
		//pTmp�� �θ� ã�� ���� �۾� / �̷����� FindNode�Լ� ��ȯ�� �θ�� �ϴ°� ��������?
	{
		int cmp = strcmp(pTmp->pszData, pszData);
		if (cmp == 0) break;
		else
		{
			pPTmp = pTmp; //pTmp�� �θ��� ����
			if (cmp < 0) pTmp = pTmp->right;
			else pTmp = pTmp->left;
		}
	}

	if (pTmp->left == NULL) //���� �ڽ��� ���� ��
	{
		if (pTmp == g_pRoot) g_pRoot = pTmp->right;
		else
		{
			if (strcmp(pPTmp->pszData, pTmp->pszData) < 0) //pTmp�� pPTmp�� ���� �ڽ�? ������ �ڽ�?
				pPTmp->right = pTmp->right; //pTmp�� �����Ͱ� �� Ŭ ��, ������ �ڽ�
			else
				pPTmp->left = pTmp->right; //pTmp�� �����Ͱ� �� Ŭ ��, ���� �ڽ�
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

	puts("���� ����");
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
			//�����ϱ�
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
	InsertNode("5�� �׸�");
	InsertNode("4�� �׸�");
	InsertNode("7�� �׸�");
	InsertNode("6�� �׸�");
	InsertNode("8�� �׸�");

	
	PrintTree(g_pRoot);
	//printf("[�ּ�]: %p / [Data]: %s\n", FindNode("7�� �׸�"),FindNode("7�� �׸�")->pszData);
	//printf("[�ּ�]: %p / [Data]: %s\n", FindNode("8�� �׸�"), FindNode("8�� �׸�")->pszData);
	printf("size: %d\n",GetSize());

	puts("\n6���׸� ����");
	DeleteByMerging("6�� �׸�");
	PrintTree(g_pRoot);
	//printf("size: %d\n", GetSize());

	ReleaseTree(g_pRoot);
	printf("size: %d\n", GetSize());
	PrintTree(g_pRoot);
	return 0;
}