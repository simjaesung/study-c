#pragma once


#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int Data;
	struct Node* next;
}Node;

typedef struct SLLQueue
{
	Node* Front;
	Node* Rear;
	int Size;

}SLLQueue;

void SLLQ_CreateQueue(SLLQueue** Queue);
void SLLQ_DeleteQueue(SLLQueue* Queue);

Node* SLLQ_CreateNode(int Data);
void SLLQ_DeleteNode(Node* DelNode);

void SLLQ_Enqueue(SLLQueue* Queue, Node* NewNode);
int SLLQ_Dequeue(SLLQueue* Queue);

int SLLQ_IsEmpty(SLLQueue* Queue);