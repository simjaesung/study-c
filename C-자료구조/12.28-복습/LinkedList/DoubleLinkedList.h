#pragma once


#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef struct Node
{
	int Data;
	struct Node* prev;
	struct Node* next;
}Node;



Node* CreateNode(int Data);
void PrintList(Node** Head);
void ReleaseList(Node** Head);
void PushHead(Node** Head, Node* NewNode);
void PushTail(Node** Head, Node* NewNode);
void InsertAfter(Node* PrevNode, Node* NewNode);
void DeleteNode(Node** Head, int Data);
Node* GetNodeAt(Node** Head, int Data);
int GetNodeCount(Node** Head);
void ReversePrintList(Node** Head);