#include<stdio.h>
#include<stdlib.h>

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void selection_sort(int arr[], int n)
{
	for(int i = 0; i < n; i++)
	{
		int min = i;
		for(int j = i+1; j < n; j++)
		{
			if(arr[min] > arr[j])
			{
				min = j;
			}
		}
		swap(&arr[i], &arr[min]);
	}
}


int main()
{
	int arr[10] = {5,4,9,6,8,7,2,14,16,11};
	int n = 10;
	selection_sort(arr, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
