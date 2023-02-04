#include<stdio.h>
#include<string.h>
int main()
{
	char all[40000] = { '\0'}, now[10] = {'\0'};
	int n = 0, count = 0;
	printf("请输入n：");
	scanf("%d", &n);
	printf("小于等于n的数有：\n");
	for (int i = 1; i <= n; i++)
	{
		printf("%d\n", i);
		sprintf(now, "%d", i);
		strcat(all, now);
	}
	for (int i = 0; i <= strlen(all); i++)
	{
		if (all[i] == '1')
		{
			count++;
		}
	}
	printf("一共有%d个1", count);
}