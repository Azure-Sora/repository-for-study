#include<stdio.h>
int main()
{
	int n = 0;
	printf("输入一个n：");
	scanf("%d", &n);
	printf("小于等于%d的素数有：" , n);
	printf("\n2\n");
	for (int now_num = 3; now_num <= n; now_num++)
	{
		for (int i = 2; i < now_num; i++)
		{
			if (now_num % i == 0)
			{
				break;
			}
			else if (now_num == i + 1)
			{
				printf("%d\n", now_num);
			}
		}
	}
	printf("\n黄天予 2022141461050");
	return 0;
}