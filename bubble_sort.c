#include<stdio.h>
#include<stdlib.h>

void swap(int * a, int * b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int n)
{
	for(int i = n; i >1; i--)
	{
		int flag = 0;
		for(int j = 1; j < i; j++)
		{
			//======正序和倒序与此有关=======
			if(arr[j-1] < arr[j])
			//===============================
			{
				swap(&arr[j-1], &arr[j]);
				flag = 1;
			}
		}
		if(!flag)
		{
			break;
		}
	}

}


int main()
{
	int arr[10]= {4,6,9,6,8,3,7,15,19,11};
	int n = 10;
	bubble_sort(arr, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
