#include<stdio.h>
#include"powers.h"
#include"powers.c"
//������ 2022141461050
extern int a;
int main()
{
	printf("����һ��������");
	scanf("%d", &a);
	printf("ƽ����%d\n", sqr(a));
	printf("������%d\n", cube(a));
	printf("�Ĵη���%d\n", quad(a));
	return 0;
}