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