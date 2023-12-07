#pragma once

#include<stdio.h>
#include<string.h>
#include<malloc.h>


typedef struct Node
{
	char* Data;
	struct Node* next;
}Node;


typedef struct LinkedQueue
{
	Node* Front;
	Node* Rear;
	int size;

}LinkedQueue;


void LQ_CreateQueue(LinkedQueue** queue);
void LQ_RemoveQueue(LinkedQueue* queue);

void LQ_Enqueue(LinkedQueue* queue, Node* pData);
char* LQ_Dequeue(LinkedQueue* queue);

Node* LQ_CreateNode(char* pszData);
int LQ_SizeQueue(LinkedQueue* queue);