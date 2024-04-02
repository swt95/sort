#include<stdio.h>
#include<stdlib.h>

void mySwap(int* a, int* b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	if(lson < n && arr[largest] < arr[lson])
	{
		largest = lson;
	}
	if(rson < n && arr[largest] < arr[rson])
	{
		largest = rson;
	}
	if(largest != i)
	{
		mySwap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}
}

void heap_sort(int arr[], int n)
{
	int i;
	for(i = n/2-1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	for(i = n-1; i >=0; i--)
	{
		mySwap(&arr[0], &arr[i]);
		heapify(arr, i, 0);

	}
}

int main()
{
	int arr[10] = {2,3,8,1,4,9,10,7,16,14};
	int n = 10;
	heap_sort(arr, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
