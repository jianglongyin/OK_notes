#include <stdio.h>

void insertsort(int arr[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int get = arr[i];		//右手抓到的第一张牌
		int j = i-1;			//左手右边的第一张牌
		while(j >= 0 && get < arr[j])			//将抓到的牌和左手的牌从右往左依次比较
		{
			arr[j+1] = arr[j];			//如果抓到的牌比手上的牌小，就将其右移
			j--;
		}
		arr[j+1] = get;			//直到该手牌比抓到的牌小（二者相等），将抓到的牌插入到这个位置
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
	insertsort(arr, sizeof(arr)/sizeof(int));
	printf("插入排序之后: ");
	for (i = 0; i < sizeof(arr)/sizeof(int); ++i)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");

	return 0;
}