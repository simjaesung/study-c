#pragma once

#include<stdio.h>
#include<string.h>
#include<stdlib.h>


typedef struct Node
{
	int Data;
	struct Node* prev;
	struct Node* next;

}Node;


Node* CDLL_CreatNode(int Data);
void CDLL_PrintList(Node** Head);
void CDLL_ReversePrintList(Node** Head);
void CDLL_ReleaseList(Node** Head);
void CDLL_PushTail(Node** Head, Node* NewNode);
void CDLL_DeleteNode(Node** Head, int Data);
void CDLL_InsertAt(Node* prevNode, Node* NewNode);
Node* GetNodeByData(Node** Head, int Data);

