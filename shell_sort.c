#include<stdio.h>
#include<stdlib.h>

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void shell_sort(int arr[], int n)
{
	int i,j,inc,key;
	for(inc = n / 2; inc > 0; inc /= 2)
	{
		for(i = inc; i < n; i++)
		{
			key = arr[i];
			j = i-inc;
			while(j >= 0 && key < arr[j])
			{
				arr[j+inc] = arr[j];
				j-=inc;	
			}
			arr[j+inc] = key; 
		}
	}
}

int main()
{
	int arr[10] = {5,4,9,6,8,7,2,14,16,11};
	int n = 10;
	shell_sort(arr, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
