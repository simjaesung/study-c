#include<stdio.h>
#include<string.h>
#include<malloc.h>


typedef struct NODE
{
	char szData[64];
	struct NODE* next;
} NODE;

NODE* Head = NULL;
NODE* pTail = NULL;

//���� ����Ʈ ��ü������ ���
void PrintList(void)
{
	/*while (Head != NULL)
	{
		printf("now: [%p] / %s, next: now: [%p]\n", Head, Head->szData,Head->next);
		Head = Head->next;
	}*/
	// Head�� �׻� ��带 �����Ѿ��ϴµ�, ���� �����ϴ°� �����̴�.

	NODE* pNode = Head;
	while (pNode != NULL)
	{
		printf("%s�� �ּ� : [%p] /, next�� �ּ�: [%p]\n", pNode->szData, pNode, pNode->next);
		pNode = pNode->next;
	}
	putchar('\n');
	printf("��� ���: %s\n", Head->szData);
	printf("���� ���: %s\n", pTail->szData);
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
	strcpy_s(newNode->szData,sizeof(newNode->szData), pszData);


	if (Head == NULL)
	{
		Head = newNode;
		pTail = Head;
	}
		
	else
	{
		newNode->next = Head;
		Head = newNode;
	}

	return 1;
}

int InsertNewNode_Tail(char* pszData)
{
	//NODE* pTmp = Head;

	/*while (pTmp -> next != NULL)
	{
		pTmp = pTmp->next;
	}*/

	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	memset(NewNode, 0, sizeof(NODE));
	strcpy_s(NewNode->szData, sizeof(pszData),pszData);

	if (Head == NULL)
		Head = NewNode;
	else
		pTail->next = NewNode;

	pTail = NewNode;
	
	//NewNode->next = NULL;
}

//find�ϴ� ���� �����ҋ��� ���� �ֵ� �����̴�. ���� ���� �ּҸ� ��ȯ���ִ°� ���� ȿ�����̴�.
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

	return 0;
}

	//�ش� ������ DeleteNode �κп� ���ԵǾ�����
	//��ȯ�� NODE * �� �ٲ۴����� �ѹ� �ٽ� �����غ���. �̸� DeleteNode���� �����غ��ô�

//��ü�� �����ϴ� �Լ�
void ReleaseList(void)
{
	NODE* pTmp = Head;
	while (pTmp != NULL)
	{
		NODE* pPrev = pTmp;
		pTmp = pTmp->next;
		free(pPrev);
	}
	Head = NULL; //���� ���� ���ɼ��� �ֱ� ������, �ƿ� ������ �����ϴ� ���� ������ ����
	pTail = 0;
}


int DeleteNode(char* pszData)
{
	NODE* prev = FindData(pszData);

	if (IsEmpthy()) {
		printf("�� ����Ʈ�Դϴ�.\n");
		return 0;
	}

	if (prev) {
		NODE* Del_Node = prev->next;
		prev->next = Del_Node->next;
		if (Del_Node == pTail)
			pTail = prev;

		free(Del_Node);
	}
	else {
		NODE* Del_Node = Head;
		Head = Del_Node->next;
		//Del_Node = NULL;
		free(Del_Node);
	}
	//prev���� NULL�̸�, �����Ǵ� ��尡 ����̰ų� �󸮽�Ʈ�� 2���� ����̴�.
	//�󸮽�Ʈ���� Head ������ ��� ���൵ ����� �󸮽�Ʈ�̴�
	return 1; //������ �ϴ� ���� 1 ��ȯ

}


int main(void)
{
	//List �׽�Ʈ�� ���� �ڵ�
	//��� ������ �� �׽�Ʈ �ڵ带 �����δ� ���� �ʼ�!
	puts("1~3 insert");
	InsertNewNode_Tail("TEST1");
	PrintList();
	InsertNewNode_Tail("TEST2");
	PrintList();
	InsertNewNode_Tail("TEST3");
	PrintList();
	InsertNewNode_Head("TEST4");
	PrintList();
	
	DeleteNode("TEST3");
	PrintList();
	DeleteNode("TEST2");
	PrintList();
	DeleteNode("TEST1");
	PrintList();
	printf("��ü����\n");
	ReleaseList();
	PrintList();


	return 0;
}