#include<stdio.h>

void swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}


void QuickSort(int arr[], int first, int last)
{
	int p = arr[first];

	int left = first + 1;
	int right = last;


	while (left <= right)
	{
		while (left <= last && arr[left] < p)
			left++;

		while (arr[right] > p)
			right--;

		if (left < right)
		{
			swap(&arr[left], &arr[right]);
			left++;
			right--;
		}
		else
			break;
	}

	swap(&arr[first], &arr[right]);

	if (first < right - 1)
		QuickSort(arr, first, right - 1);
	if(right + 1 < last)
		QuickSort(arr, right + 1, last);
}


int main()
{
	int arr[7] = { 3,7,1,5,6,2,4 };

	QuickSort(arr, 0, 6);
	
	for (int i = 0; i < 7; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	
	return 0;
}