#include<stdio.h>
#include<string.h>
int main()
{
	char all[40000] = { '\0'}, now[10] = {'\0'};
	int n = 0, count = 0;
	printf("������n��");
	scanf("%d", &n);
	printf("С�ڵ���n�����У�\n");
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
	printf("һ����%d��1", count);
}