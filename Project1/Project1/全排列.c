#include<stdio.h>
int count = 0;
int swap(int *one, int *two)//交换数组里两个数的位置
{
	int temp = 0;
	temp = *one;
	*one = *two;
	*two = temp;
}
int permutation(int arr[], int start, int end)
{
	if (start == end)//操作的数已经是最后一个数的时候就打印出整个数列
	{
		for (int i = 0; i < end; i++)
		{
			printf("%d", arr[i]);
		}
		printf("\n");
		count++;
	}
	else
	{
		for (int j = start ; j < end; j++)
		{
			if (start != j)//跳过第一轮
			{
				swap(&arr[start], &arr[j]);//把一个位置的数依次与后面的数互换位置
			}
			permutation(arr, start + 1, end);//通过递归，从倒数第二个数开始操作
			if (start != j)
			{
				swap(&arr[start], &arr[j]);//把位置换回来
			}
		}
	}
}
int main()
{
	int source[10], n;
	printf("要排列的数个数是：");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		source[i] = i + 1;
	}
	permutation(source, 0, n);
	printf("一共%d种排序", count);
	return 0;
}