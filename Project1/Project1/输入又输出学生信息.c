#include<stdio.h>
#include<string.h>
struct student
{
	int number;
	char name[20];
	int score[3];
};
void printScore(struct student* stu)
{
	printf("ѧ�ţ�%d\n������%s\n�ɼ���%d %d %d\n", stu->number, stu->name, stu->score[0], stu->score[1], stu->score[2]);
}
void inputScore(struct student* stu)
{
	char temp;
	printf("������ѧ����Ϣ\n");
	printf("ѧ�ţ�");
	scanf("%d", &(stu->number));
	printf("������");
	while ((temp = getchar()) != '\n' && temp != EOF);
	gets_s(stu->name, 20);
	for (int i = 0; i < 3; i++)
	{
		printf("��%d�ſγ̵ĳɼ���", i + 1);
		scanf("%d", &(stu->score[i]));
	} 
}
int main()
{
	struct student group[5];
	for (int i = 0; i < 1; i++)
	{
		inputScore(&group[i]);
	}
	for (int i = 0; i < 1; i++)
	{
		printScore(&group[i]);
	}
	return 0;
}