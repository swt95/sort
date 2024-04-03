#include<stdio.h>
#include<stdlib.h>

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void insert_sort(int arr[], int n)
{
	for(int i = 1; i < n; i++)
	{
		int key = arr[i];
		int j = i - 1;
		while(j >= 0 && arr[j] > key)
		{
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}


int main()
{
	int arr[10] = {5,4,9,6,8,7,2,14,16,11};
	int n = 10;
	insert_sort(arr, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
