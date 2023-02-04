#include<stdio.h>
int feibo(int n)
{
	if (n <= 2)
	{
		return 1;//前两项为1
	}
	else
	{
		return feibo(n - 1) + feibo(n - 2);//第三项开始每一项是前两项之和
	}
}
int main()
{
	int n = 0;
	printf("要求第?项的数：");
	scanf("%d", &n);
	printf("第%d项是%d",n , feibo(n));
	return 0;
}