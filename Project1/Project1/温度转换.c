#include<stdio.h>

int main()
{
	double hua = 0, she = 0;
	printf("请输入华氏度：");
	scanf("%lf", &hua);
	she = (5.0 / 9) * (hua - 32);
	printf("\n摄氏度为%.1lf\n", she);
	return 0;
}