#include<stdio.h>
int main()
{
	char da, xiao;
	printf("请输入一个大写字母：");
	scanf("%c", &da);
	if (da >= 'A' && da <= 'Z')
	{
		xiao = da - 'A' + 'a';
		printf("\n小写为：%c", xiao);
	}
	else
	{
		printf("输入不是一个大写字母。");
	}
	return 0;
}