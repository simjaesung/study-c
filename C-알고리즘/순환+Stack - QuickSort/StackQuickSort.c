#include "LinkedListStack.h"
#include<stdio.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

void QuickSort(int arr[], int first, int last)
{

	LinkedListStack* Stack = NULL;
	LLS_CreateStack(&Stack);

	LLS_PushStack(Stack, LLS_CreateNode(last)); //right
	LLS_PushStack(Stack, LLS_CreateNode(first)); //left


	while (LLS_IsEmpty(Stack) != 1)
	{
		
		int first = LLS_PopStack(Stack)->Data;
		int last = LLS_PopStack(Stack)->Data;
		int right = last; //last
		int left = first + 1; // first + 1
		int p = arr[first]; // first

		while (left <= right)
		{
			while (arr[left] < p && left <= last)
				left++;

			while (arr[right] > p)
				right--;

			if (right > left)
				swap(&arr[left++], &arr[right--]);
			else
				break;
		}

		swap(&arr[first], &arr[right]);

		if (right - 1 > first)
		{
			LLS_PushStack(Stack, LLS_CreateNode(right - 1)); //right
			LLS_PushStack(Stack, LLS_CreateNode(first));
		}
			
		if (last > right + 1)
		{
			LLS_PushStack(Stack, LLS_CreateNode(last)); //right
			LLS_PushStack(Stack, LLS_CreateNode(right + 1));
		}
	}
}



int main()
{

	int arr[7] = { 5,3,4,2,6,7,1 };

	QuickSort(arr, 0, 6);

	for(int i = 0; i< 7; i++)
		printf("%d ",arr[i]);

	printf("\n");



	return 0;
}