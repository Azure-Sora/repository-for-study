#include<stdio.h>
#include<math.h>
int main()
{
	double a, b, c, C, S;
	printf("������߳���");
	scanf("%lf%lf%lf", &a, &b, &c);
	C = 0.5 * (a + b + c);
	S = sqrt(C * (C - a) * (C - b) * (C - c));
	printf("\n���Ϊ��%lf", S);
	return 0;
}