#include<stdio.h>
#include<string.h>
//黄天予2022141461050
struct student
{
	int number;
	char name[20];
	int score[3];
};
void printScore(struct student *stu)
{
	printf("学号：%d\n姓名：%s\n成绩：%d %d %d\n", stu->number, stu->name, stu->score[0], stu->score[1], stu->score[2]);
}
int main()
{
	struct student group[5];
	group[0].number = 114;
	group[1].number = 514;
	group[2].number = 1919;
	group[3].number = 810;
	group[4].number = 123;
	strcpy(group[0].name, "ZhangSan");
	strcpy(group[1].name, "LiSi");
	strcpy(group[2].name, "WangWu");
	strcpy(group[3].name, "Van");
	strcpy(group[4].name, "Billy");
	group[0].score[0] = 13;
	group[0].score[1] = 54;
	group[0].score[2] = 575;
	group[1].score[0] = 77;
	group[1].score[1] = 43;
	group[1].score[2] = 75;
	group[2].score[0] = 699;
	group[2].score[1] = 4657;
	group[2].score[2] = 454;
	group[3].score[0] = 74;
	group[3].score[1] = 40;
	group[3].score[2] = 457;
	group[4].score[0] = 555;
	group[4].score[1] = 77;
	group[4].score[2] = 99;
	for (int i = 0; i < 5; i++)
	{
		printScore(&group[i]);
	}
	return 0;
}