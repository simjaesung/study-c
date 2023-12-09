#include "LinkedListStack.h"

void LLS_CreateStack(LinkedListStack** Stack)
{
	(*Stack) = (LinkedListStack*)malloc(sizeof(LinkedListStack));
	memset((*Stack), 0, sizeof(LinkedListStack));

	/*(*Stack)->List = (Node*)malloc(sizeof(Node));
	memset((*Stack)->List, 0, sizeof(Node));

	(*Stack)->Top = (Node*)malloc(sizeof(Node));
	memset((*Stack)->Top, 0, sizeof(Node));*/

	(*Stack)->List = NULL;
	(*Stack)->Top = NULL;
	(*Stack)->StackSize = 0;
}

Node* LLS_CreateNode(int Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	memset(NewNode, 0, sizeof(Node));

	//NewNode->Data = pszData; //멤버가 char* 만 있을떄는?
	NewNode->Data = Data;

	NewNode->next = NULL;

	return NewNode;
}

void LLS_PrintStack(LinkedListStack* Stack)
{
	Node* pTmp = Stack->Top;

	while (pTmp != NULL)
	{
		printf("%d의 노드\n", pTmp->Data);
		pTmp = pTmp->next;
	}
}

void LLS_ReleseStack(LinkedListStack* Stack)
{
	Node* pTmp = Stack->List;

	while (pTmp != NULL)
	{
		Node* Del_Node = pTmp;
		pTmp = pTmp->next;

		free(pTmp);
		Stack->StackSize--;
	}

	free(Stack);
}

void LLS_PushStack(LinkedListStack* Stack, Node* PushNode)
{
	if (Stack->List == NULL)
		Stack->List = PushNode;
	else
		PushNode->next = Stack->Top;


	Stack->Top = PushNode;
	Stack->StackSize++;
}

Node* LLS_PopStack(LinkedListStack* Stack)
{
	//Pop한 Node의 메모리해제는 어떻게?
	Node* StackTop = Stack->Top;
	Stack->Top = Stack->Top->next;
	StackTop->next = NULL;

	if (--(Stack->StackSize) == 0)
		Stack->List = NULL;

	return StackTop;
}

int LLS_GetTop(LinkedListStack* Stack)
{
	return Stack->Top->Data;
}

int LLS_IsEmpty(LinkedListStack* Stack)
{
	if (Stack->StackSize == 0)
		return 1;
	return 0;
}
int LLS_GetSize(LinkedListStack* Stack)
{
	return Stack->StackSize;
}