#include<stdio.h>
#define SIZE 10
int main()
{
	int arr[SIZE], temp, index;
	for (int i = 0; i < SIZE; i++)
	{
		printf("请输入第%d个数：", i + 1);
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < SIZE; i++)
	{
		index = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		if (i != index)
		{
			temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
	for (int i = 0; i < SIZE; i++)
	{
		printf("%d\n", arr[i]);
	}
	return 0;
}