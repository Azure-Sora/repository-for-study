#include<stdio.h>

int main()
{
	double hua = 0, she = 0;
	printf("�����뻪�϶ȣ�");
	scanf("%lf", &hua);
	she = (5.0 / 9) * (hua - 32);
	printf("\n���϶�Ϊ%.1lf\n", she);
	return 0;
}