#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c, C, S;
	printf("请输入边长：");
	scanf("%lf%lf%lf", &a, &b, &c);
	C = 0.5 * (a + b + c);
	S = sqrt(C * (C - a) * (C - b) * (C - c));
	printf("\n面积为：%lf", S);
	return 0;
}