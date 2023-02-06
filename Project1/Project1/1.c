#include<stdio.h>
#include<string.h>
#include<stdlib.h>
typedef struct student{
	int age;
	char gender;
	char* name;
}student;
int main()
{
	student stu1;
	char name[50];
	printf("name:");
	scanf("%s", name);
	stu1.name = (char*)malloc((strlen(name) + 1) * sizeof(char));
	strcpy(stu1.name, name);
	printf("%s", stu1.name);
}