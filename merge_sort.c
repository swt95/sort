#include<stdio.h>
#include<stdlib.h>

void merge(int arr[],int tempArr[], int left, int mid, int right)
{
	int l_pos = left;
	int r_pos = mid + 1;
	int pos = left;

	while(l_pos <= mid && r_pos <= right)
	{
		if(arr[l_pos] < arr[r_pos])
		{
			tempArr[pos] = arr[l_pos];
			pos++;
			l_pos++;
		}
		else if(arr[l_pos] > arr[r_pos])
		{
			tempArr[pos] = arr[r_pos];
			pos++;
			r_pos++;
		}
	}

	while(l_pos <= mid)
	{
		tempArr[pos++] = arr[l_pos++];
	}

	while(r_pos <= right)
	{
		tempArr[pos++] = arr[r_pos++];
	}
	while(left <= right)
	{
		arr[left] = tempArr[left];
		left++;
	}
}

void msort(int arr[], int tempArr[], int left, int right)
{
	if(left < right)
	{
		int mid = (left + right) / 2;
		msort(arr, tempArr, left, mid);
		msort(arr, tempArr, mid+1, right);

		merge(arr, tempArr, left, mid, right);
	}

}


void merge_sort(int arr[], int n)
{
	int * tempArr = (int *)malloc(n * sizeof(int));
	if(tempArr)
	{
		msort(arr, tempArr, 0, n-1);
		free(tempArr);
	}
	else
	{
		printf("error: failed  to allocate memory");
	}

}	

int main()
{
	int arr[] = {9,5,2,7,12,4,3,1,11}
	int n = 9;
	merge_sort(arr, n);
	for(int i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
		printf("\n");
	}
	return 0;
}
