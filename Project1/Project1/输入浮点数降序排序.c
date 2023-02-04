#include<stdio.h>
#define SIZE 10
void sort(double arr[]);
int main()
{
	double arr[SIZE];
	for (int i = 0; i < SIZE; i++)
	{
		printf("请输入第%d个数：", i + 1);
		scanf("%lf", &arr[i]);
	}
	sort(arr);
	for (int i = 0; i < SIZE; i++)
	{
		printf("%lf\n", arr[i]);
	}
	return 0;
}
void sort(double arr[])
{
	double temp;
	int index;
	for (int i = 0; i < SIZE; i++)
	{
		index = i;
		for (int j = i + 1; j < SIZE; j++)
		{
			if (arr[j] > arr[index])
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
}