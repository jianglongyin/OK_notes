#include <stdio.h>

void swap(int a[], int i, int j)
{
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

//冒泡排序
void Bubblesort(int arr[], int size)
{
	int i, j;
	for (i = 0; i < size - 1; ++i)		//进行比较的次数，每次比较之后，最大的一个数就像气泡一样浮到最后面
	{
		for (j = 0; j < size - 1 - i; ++j)		//依次对相邻的两个元素进行比较，较大的数往后移
		{
			if (arr[j] > arr[j+1])
			{
				swap(arr, j, j+1);
			}
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
	Bubblesort(arr, sizeof(arr)/sizeof(int));
	printf("排序之后: ");
	for (i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}