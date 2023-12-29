#include "LCRS.h"


Node* LCRS_CreateNode(int Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));

	NewNode->Data = Data;
	NewNode->Child = NULL;
	NewNode->Silbing = NULL;

	return NewNode;
}

void LCRS_DeleteNode(Node* DelNode)
{
	free(DelNode);
}

void LCRS_DeleteTree(Node* RootNode)
{
	Node* pTmp = RootNode;

	if(pTmp->Child != NULL)
		LCRS_DeleteTree(pTmp->Child);

	if (pTmp->Silbing != NULL)
		LCRS_DeleteTree(pTmp->Silbing);

	free(pTmp);
}

void LCRS_AddChildNode(Node* ParentNode, Node* ChildNode)
{
	if (ParentNode->Child == NULL)
		ParentNode->Child = ChildNode;
	else
	{
		Node* pTmp = ParentNode->Child;

		while (pTmp->Silbing != NULL)
			pTmp = pTmp->Silbing;

		pTmp->Silbing = ChildNode;
	}
}

void LCRS_PrintTree(Node* Node, int Depth)
{
	for (int i = 0; i < Depth - 1; i++)
		printf("   ");

	if (Depth > 0)
		printf("+--");

	printf("%d\n", Node->Data);

	if (Node->Child != NULL)
		LCRS_PrintTree(Node->Child, Depth + 1);

	if(Node->Silbing != NULL)
		LCRS_PrintTree(Node->Silbing, Depth);
}

void LCRS_PrintNodesAtLevel(Node* Node, int level)
{
	if(level == 0)
		printf("%d\n", Node->Data);

	if (Node->Child != NULL)
		LCRS_PrintNodesAtLevel(Node->Child, level - 1);

	if (Node->Silbing != NULL)
		LCRS_PrintNodesAtLevel(Node->Silbing, level);
}