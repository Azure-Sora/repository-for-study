#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
	srand(time(0));
	int matrix[5][5];
	int sum1 = 0;
	int sum2 = 0;
	int sum = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			matrix[i][j] = rand() % 100;
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			printf("%5d", matrix[i][j]);
		}
		printf("\n");
	}
	for (int i = 0; i < 5; i++)
	{
		sum1 += matrix[i][i];
	}
	int j = 4;
	for (int i = 0; i < 5; i++)
	{
		sum2 += matrix[i][j];
		j--;
	}
	sum = sum1 + sum2 - matrix[2][2];
	printf("对角线之和是%d", sum);
}
