#include<stdio.h>
int main()
{
	int n = 0;
	printf("����һ��n��");
	scanf("%d", &n);
	printf("С�ڵ���%d�������У�" , n);
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
	printf("\n������ 2022141461050");
	return 0;
}