#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int Data;
	struct Node* Child;
	struct Node* Silbing;
} Node;


Node* LCRS_CreateNode(int Data);
void LCRS_DeleteNode(Node* DelNode);
void LCRS_DeleteTree(Node* RootNode);

void LCRS_AddChildNode(Node* ParentNode, Node* ChildNode);
void LCRS_PrintTree(Node* Node, int Depth);
void LCRS_PrintNodesAtLevel(Node* Node, int level);

