#include<stdio.h>
int main()
{
	int n;
	while (true)
	{
		printf("������������������С��1ʱ�˳���:");
		scanf("%d", &n);
		if (n <= 0)
		{
			break;
		}
		printf("����%d�Ŀ����������ǣ�%d,", n, n);
		while (true)
		{
			if (n % 2 == 0)
			{
				n = n / 2;
			}
			else
			{
				n = n * 3 + 1;
			}
			printf("%d", n);
			if (n == 1)
			{
				break;
			}
			printf(",");
		}
		printf("\n");
	}
	printf("����%d������ѭ��", n);
}