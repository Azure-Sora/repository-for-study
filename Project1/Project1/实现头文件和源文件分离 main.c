#include<stdio.h>
#include"powers.h"
#include"powers.c"
//黄天予 2022141461050
extern int a;
int main()
{
	printf("输入一个整数：");
	scanf("%d", &a);
	printf("平方：%d\n", sqr(a));
	printf("立方：%d\n", cube(a));
	printf("四次方：%d\n", quad(a));
	return 0;
}