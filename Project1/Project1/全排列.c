#include<stdio.h>
int count = 0;
int swap(int *one, int *two)//������������������λ��
{
	int temp = 0;
	temp = *one;
	*one = *two;
	*two = temp;
}
int permutation(int arr[], int start, int end)
{
	if (start == end)//���������Ѿ������һ������ʱ��ʹ�ӡ����������
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
			if (start != j)//������һ��
			{
				swap(&arr[start], &arr[j]);//��һ��λ�õ�������������������λ��
			}
			permutation(arr, start + 1, end);//ͨ���ݹ飬�ӵ����ڶ�������ʼ����
			if (start != j)
			{
				swap(&arr[start], &arr[j]);//��λ�û�����
			}
		}
	}
}
int main()
{
	int source[10], n;
	printf("Ҫ���е��������ǣ�");
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		source[i] = i + 1;
	}
	permutation(source, 0, n);
	printf("һ��%d������", count);
	return 0;
}