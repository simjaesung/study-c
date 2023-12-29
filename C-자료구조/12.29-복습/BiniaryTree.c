#include "BiniaryTree.h"


Node* BT_CreateNode(char Data)
{
	Node* NewNode = (Node*)malloc(sizeof(Node));
	NewNode->Data = Data;
	NewNode->left = NULL;
	NewNode->right = NULL;

	return NewNode;
}

void BT_DeleteNode(Node* DelNode)
{
	free(DelNode);
}


void BT_DeleteTree(Node* Root)
{
	if (Root == NULL)
		return;

	BT_DeleteTree(Root->left);
	BT_DeleteTree(Root->right);
	
	free(Root);
}

void BT_Preorder(Node* Root)
{
	if (Root == NULL)
		return;

	printf("%c\n", Root->Data);
	BT_Preorder(Root->left);
	BT_Preorder(Root->right);

}

void BT_Inorder(Node* Root)
{
	if (Root == NULL)
		return;

	BT_Inorder(Root->left);
	printf("%c\n", Root->Data);
	BT_Inorder(Root->right);
}

void BT_Postorder(Node* Root)
{
	
	if (Root == NULL)
		return;

	BT_Postorder(Root->left);
	BT_Postorder(Root->right);
	printf("%c\n", Root->Data);

}