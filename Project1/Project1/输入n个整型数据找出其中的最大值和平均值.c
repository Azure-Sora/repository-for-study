#include<stdio.h>
int computeMax(int vNumbers[], int vCount);
float computeAverage(int vNumbers[], int vCount);
int main()
{
	int n = 0;
	int numbers[100];
	printf("Ҫ����ĸ�����");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		printf("�������%d�����֣�", i + 1);
		scanf("%d", &numbers[i]);
	}
	printf("�������ֵΪ��%d\n", computeMax(numbers, n));
	printf("��ƽ��ֵΪ��%f\n", computeAverage(numbers, n));
}
int computeMax(int vNumbers[], int vCount)
{
	int index = 0;
	for (int i = 1; i < vCount; i++)
	{
		if (vNumbers[i] > vNumbers[index])
		{
			index = i;
		}
	}
	return vNumbers[index];
}
float computeAverage(int vNumbers[], int vCount)
{
	float all = 0.0;
	for (int i = 0; i < vCount; i++)
	{
		all += vNumbers[i];
	}
	return (float)(all / vCount);
}