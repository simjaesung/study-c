#include<stdio.h>
#include<string.h>
#include<malloc.h>


typedef struct NODE
{
	char szData[64];
	struct NODE* next;
} NODE;

NODE* Head = NULL;

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

	strcpy_s(newNode->szData,sizeof(newNode->szData), pszData);


	if (Head == NULL)
		Head = newNode;
	else
	{
		newNode->next = Head;
		Head = newNode;
		/*newNode->next = Head;
		Head = newNode;*/
	}

	return 1;
}

int InsertNewNode_Tail(char* pszData)
{
	NODE* pTmp = Head;

	while (pTmp -> next != NULL)
	{
		pTmp = pTmp->next;
	}

	NODE* NewNode = (NODE*)malloc(sizeof(NODE));
	strcpy_s(NewNode->szData, sizeof(pszData),pszData);

	pTmp->next = NewNode;
	NewNode->next = NULL;
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
}

//�켱 �ۼ��� ��� ���� �Լ�

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
//				//��� ����
//				Head = pTmp->next;
//			}
//			else {
//				//����
//				pPrev->next = pTmp->next;
//				//pNode->next = NULL;
//			}
//			free(pTmp);
//			printf("�ش� Node�� �����Ͽ����ϴ�.\n");
//			return 1;
//		}
//		pPrev = pTmp;
//		pTmp = pTmp->next;
//	}
//	printf("�ش� Node�� �������� �ʽ��ϴ�.\n");
//	return 0;
//}

//int DeleteNode(char* pszData) 
//{
//	NODE* prev = FindData(pszData);
//
//	if (prev || prev == NULL) {
//		if (prev == NULL)
//		{
//			NODE* BF_Head = Head;
//			Head = Head->next;
//			free(BF_Head);
//		}
//		else {
//			NODE* Del_Node = prev->next;
//			prev->next = prev->next->next;
//			free(Del_Node);
//		}		
//		return 1; //���� ����
//	}	
//	return 0; //���� ����(����X)
//}

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
	InsertNewNode_Head("TEST1");
	InsertNewNode_Head("TEST2");
	InsertNewNode_Head("TEST3");
	PrintList();

	puts("��� ����");
	DeleteNode("TEST3");
	PrintList();//�ݵ�� �׽�Ʈ ���ϱ�!!!!
	
	puts("��ġ ã��");
	printf("FindNode before TEST1 : %p\n", FindData("TEST1"));

	puts("2 ����");
	DeleteNode("TEST2");
	PrintList();

	puts("2 ����");
	InsertNewNode_Head("TEST2");
	PrintList();

	puts("3 ����");
	DeleteNode("TEST3");
	PrintList();


	puts("3 ����");
	InsertNewNode_Head("TEST3");
	PrintList();

	puts("1 ����");
	DeleteNode("TEST1");
	PrintList();


	puts("1 ����");
	InsertNewNode_Head("TEST1");
	PrintList();

	puts("4 ���� ����");
	InsertNewNode_Tail("TEST4");
	PrintList();
	DeleteNode("TEST2");
	PrintList();
	DeleteNode("TEST4");
	PrintList();


	printf("��ü����\n");
	ReleaseList();
	PrintList();


	return 0;
}