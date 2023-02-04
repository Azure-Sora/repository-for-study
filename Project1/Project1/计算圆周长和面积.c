#include<stdio.h>
#define pai 3.14159
int main()
{
	double r = 0, s = 0;
	printf("请输入半径：");
	scanf("%lf", &r);
	s = pai * r * r;
	printf("\n面积为：%.2lf", s);
}