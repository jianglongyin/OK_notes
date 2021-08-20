#include <stdio.h>

void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void Cocktailsort(int arr[], int size)
{
	int left = 0;
	int right = size-1;
	while(left < right)
	{
		for (int i = left; i < right; ++i)
		{
			if (arr[i] > arr[i+1])
			{
				swap(arr, i, i+1);
			}
		}
		right--;
		for (int i = right; i > left; --i)
		{
			if (arr[i] < arr[i-1])
			{
				swap(arr, i, i-1);
			}
		}
		left++;
	}
}

int main(int argc, char const *argv[])
{
	int arr[5] = {58, 49, 78, 36, 24};
	printf("排序之前: ");
	int i;
	for (i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
	Cocktailsort(arr, sizeof(arr)/sizeof(int));
	printf("排序之后: ");
	for (i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}