#include<stdio.h>
int main()
{
	int n;
	while (true)
	{
		printf("请输入正整数（输入小于1时退出）:");
		scanf("%d", &n);
		if (n <= 0)
		{
			break;
		}
		printf("整数%d的考拉兹序列是：%d,", n, n);
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
	printf("输入%d，结束循环", n);
}