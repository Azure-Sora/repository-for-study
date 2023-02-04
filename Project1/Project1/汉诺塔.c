#include<stdio.h>

void hanoi(int n, char a, char b, char c);
void move();
int main()
{
	int m = 0;
	printf("请输入盘子个数：");
	scanf("%d", &m);
	hanoi(m, 'A', 'B', 'C');
}
void hanoi(int n, char a, char b, char c)
{
	if (n == 1)
	{
		move(a, c);
	}
	else
	{
		hanoi(n - 1, a, c, b);//把A上的盘子经由C移到B
		move(a, c);
		hanoi(n - 1, b, a, c);//把B上的盘子经由A移到C
	}
}
void move(char qian, char hou)
{
	printf("%c--->%c\n", qian, hou);
}