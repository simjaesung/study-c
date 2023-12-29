#pragma once

#include <stdio.h>
#include <stdlib.h>


typedef struct Node
{
	int Data;
}Node;


typedef struct CircularQueue
{
	int Capacity;
	int Front;
	int Rear;

	Node* Nodes;
}CircularQueue;


void CQ_CreateQueue(CircularQueue** Queue, int Size);
void CQ_DeleteQueue(CircularQueue* Queue);
void CQ_Enqueue(CircularQueue* Queue, int Data);
int CQ_Dequeue(CircularQueue* Queue);
int CQ_IsEmpty(CircularQueue* Queue);
int CQ_IsFull(CircularQueue* Queue);
void CQ_PrintNodes(CircularQueue* Queue);