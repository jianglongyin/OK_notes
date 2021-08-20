#include <stdio.h>

void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

void selectsort(int arr[], int size)
{
	for (int i = 0; i < size-1; ++i)			//用来控制轮次，并且得到已排序的元素末尾
	{
		int min = i;							//用来记录最小元素的下标位置
		for (int j = i+1; j < size; ++j)
		{
			if (arr[min] > arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			swap(arr, i, min);		//将最小元素放到最开始的位置
		}
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
	selectsort(arr, sizeof(arr)/sizeof(int));
	printf("排序之后: ");
	for (i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}