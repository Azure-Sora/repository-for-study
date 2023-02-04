#include<stdio.h>
#define SIZE 10
void sort(int arr[])
{
	int temp;
	for (int i = 0; i < SIZE; i++)
	{
		for (int j = 0; j < SIZE - i - 1; j++)
		{
			if (arr[j] < arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}
}
int main()
{
	int arr[SIZE], temp, index;
	for (int i = 0; i < SIZE; i++)
	{
		printf("请输入第%d个数：", i + 1);
		scanf("%d", &arr[i]);
	}
	sort(arr);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}