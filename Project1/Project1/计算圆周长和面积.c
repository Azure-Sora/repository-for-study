#include<stdio.h>
#define pai 3.14159
int main()
{
	double r = 0, s = 0;
	printf("������뾶��");
	scanf("%lf", &r);
	s = pai * r * r;
	printf("\n���Ϊ��%.2lf", s);
}