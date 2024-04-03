#include<stdio.h>
#include<stdlib.h>

//swap
void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

int func(int arr[], int left, int right)
{
	int key = arr[right];
	int i = left;
	for(int j = left; j < right; j++)
	{
		if(arr[j] < key)
		{
			swap(&arr[j], &arr[i]);
			i++;
		}
	}
	swap(&arr[i], &arr[right]);
	return i;
}

void quick(int arr[], int left, int right)
{
	if(left < right)
	{

		int mid = func(arr, left, right);
		quick(arr, left, mid -1);
		quick(arr, mid + 1, right);
	}
}

void quick_sort(int arr[], int n)
{
	quick(arr, 0, n-1);
}

int main()
{
	int arr[10] = {2,8,6,5,14,16,7,15,1,13};
	int n = 10;

	quick_sort(arr, n);
	for(int i =0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
