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
	printf("学号：%d\n姓名：%s\n成绩：%d %d %d\n", stu->number, stu->name, stu->score[0], stu->score[1], stu->score[2]);
}
void inputScore(struct student* stu)
{
	char temp;
	printf("请输入学生信息\n");
	printf("学号：");
	scanf("%d", &(stu->number));
	printf("姓名：");
	while ((temp = getchar()) != '\n' && temp != EOF);
	gets_s(stu->name, 20);
	for (int i = 0; i < 3; i++)
	{
		printf("第%d门课程的成绩：", i + 1);
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