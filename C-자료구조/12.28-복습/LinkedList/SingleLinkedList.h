#pragma once

#include <stdio.h>
#include <string.h>
#include<malloc.h>


typedef struct Node 
{
	int Data;
	struct Node* next;

}Node;



void SLL_PrintList(Node** Head);
Node* SLL_CreateNode(int Data);
void SLL_ReleaseList(Node** Head);
void SLL_AppendNode(Node** Head, Node* NewNode);
Node* SLL_GetNodeAt(Node** Head, int Data);
void SLL_DeleteNode(Node** Head, int Data);
void SLL_InsertAfter(Node* BeforeNode, Node* NewNode);
void SLL_InsertNewHead(Node** Head, Node* NewNode);
void SLL_InsertBefore(Node** Head, Node* CurrentNode, Node* NewNode);