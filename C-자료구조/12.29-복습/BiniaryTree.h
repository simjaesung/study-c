#pragma once


#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
	struct Node* left;
	struct Node* right;
	char Data;
}Node;


Node* BT_CreateNode(char Data);
void BT_DeleteNode(Node* DelNode);
void BT_DeleteTree(Node* Root);

void BT_Preorder(Node* Root);
void BT_Inorder(Node* Root);
void BT_Postorder(Node* Root);