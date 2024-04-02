#include<stdio.h>
#include<stdlib.h>

//swap
void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

//维护堆
void heapify(int arr[], int n, int i)
{
	int largest = i;
	int lson = i * 2 + 1;
	int rson = i * 2 + 2;
	//============大根堆和小根堆只与这一段有关================
	if(lson < n && arr[largest] > arr[lson])
	{
		largest = lson;
	}
	if(rson < n && arr[largest] > arr[rson])
	{
		largest = rson;
	}
	//==========================================================
	if(largest != i)
	{
		swap(&arr[largest], &arr[i]);
		heapify(arr, n, largest);
	}


}

//函数入口
void heap_sort(int arr[], int n)
{
	//建堆
	for(int i = n / 2 - 1; i >= 0; i--)
	{
		heapify(arr, n, i);
	}

	//排序
	for(int i = n-1; i >= 0; i--)
	{
		swap(&arr[0], &arr[i]);
		heapify(arr, i, 0);
	}
}

int main()
{
	int arr[10] = {2,8,6,5,14,16,7,15,1,13};
	int n = 10;

	heap_sort(arr, n);
	for(int i =0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
