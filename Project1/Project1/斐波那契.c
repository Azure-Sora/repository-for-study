#include<stdio.h>
int feibo(int n)
{
	if (n <= 2)
	{
		return 1;//ǰ����Ϊ1
	}
	else
	{
		return feibo(n - 1) + feibo(n - 2);//�����ʼÿһ����ǰ����֮��
	}
}
int main()
{
	int n = 0;
	printf("Ҫ���?�������");
	scanf("%d", &n);
	printf("��%d����%d",n , feibo(n));
	return 0;
}