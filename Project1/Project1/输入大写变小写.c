#include<stdio.h>
int main()
{
	char da, xiao;
	printf("������һ����д��ĸ��");
	scanf("%c", &da);
	if (da >= 'A' && da <= 'Z')
	{
		xiao = da - 'A' + 'a';
		printf("\nСдΪ��%c", xiao);
	}
	else
	{
		printf("���벻��һ����д��ĸ��");
	}
	return 0;
}