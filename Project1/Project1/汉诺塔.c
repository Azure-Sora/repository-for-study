#include<stdio.h>

void hanoi(int n, char a, char b, char c);
void move();
int main()
{
	int m = 0;
	printf("���������Ӹ�����");
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
		hanoi(n - 1, a, c, b);//��A�ϵ����Ӿ���C�Ƶ�B
		move(a, c);
		hanoi(n - 1, b, a, c);//��B�ϵ����Ӿ���A�Ƶ�C
	}
}
void move(char qian, char hou)
{
	printf("%c--->%c\n", qian, hou);
}