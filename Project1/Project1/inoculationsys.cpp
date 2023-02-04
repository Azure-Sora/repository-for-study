#include <stdio.h>
#include "inoculationsys.h"
#include "fileoperation.h"
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <windows.h>
#include <math.h>

#define SIZE 10

void init(VacInfo m[], int size, int* pcount);
VacInfo InputInfo();

int Insert(VacInfo m[], int* pcount);
int Dele(VacInfo m[], int* pcount);
int SearchbyName(VacInfo m[], int count);
Date GetDate();
void PrintAll(const VacInfo m[], const int count);
void SendMsg(const VacInfo m[], const int count);


Date td;


int main()
{
	VacInfo table[SIZE];
	memset(table, 0, SIZE * sizeof(VacInfo));
	int count = 0;
	td.year = 2022;
	td.month = 1;
	td.day = 3;

	srand(time(NULL));

	while (1)
	{	
		system("CLS");
		puts("\n===============welcome to inoculation system===============\n");
		puts("1.initialize\n2.Insert\n3.Delete\n4.SearchbyName\n5.Send Message\n6.PrintALL\n7.WritetoFile\n8.Exit\n");
		printf("select a service:");
		int ans;
		scanf("%d", &ans);
		switch (ans)
		{
		case 1:
			init(table, SIZE, &count);
			system("Pause");
			break;
		case 2:
			Insert(table,&count);
			system("Pause");
			break;
		case 3:
			Dele(table, &count);
			system("Pause");
			break;
		case 4:
			SearchbyName(table,count);
			system("Pause");
			break;
		case 5:
			SendMsg(table, count);
			system("Pause");
			break;
		case 6:
			PrintAll(table, count);
			system("Pause");
			break;
		case 7:
			inosyswt(table, count);
			system("Pause");
			break;
		case 8:
			return 1;
		}
	}
	return 0;
}

void init(VacInfo m[], int size,int *pcount)
{
	
}

Date GetDate()
{
	Date dt;
	int y, m, d;
	printf("Please input Date:yyyy/mm/dd:");
	scanf("%u/%u/%u", &y, &m, &d);
	dt.year = y;
	dt.month = m;
	dt.day = d;

	return dt;
}
 
//VacInfo InputInfo()
//{
//
//
//}


int Insert(VacInfo m[], int* pcount)
{
	char temp;
	while (temp = getchar() != '\n' && temp != EOF);
	printf("Please input name:");
	gets_s(m[*pcount].name);
	while(true)
	{
		printf("Please input age:");
		scanf("%d", &m[*pcount].age);
		if (m[*pcount].age >= 0 && m[*pcount].age <= 120)
		{
			break;
		}
		else
		{
			printf("Please input a number between 0 and 120!\n");
		}
	}
	long long tel;
	tel = rand() % 3;
	switch (tel)
	{
	case 0:tel = 18000000000; break;
	case 1:tel = 15800000000; break;
	case 2:tel = 13000000000; break;
	}
	tel = tel + rand() % 100000000;
	sprintf(m[*pcount].tel, "%lld", tel);
	int ApartDays = 0;
	m[*pcount].vacDate[0] = GetDate();
	if (m[*pcount].vacDate[0].year != 0 && m[*pcount].vacDate[0].month != 0 && m[*pcount].vacDate[0].day != 0)
	{
		while (true)
		{
			printf("(The second dose must be 24 days apart from the first dose.)\n");
			m[*pcount].vacDate[1] = GetDate();
			if (m[*pcount].vacDate[1].year == 0 && m[*pcount].vacDate[1].month == 0 && m[*pcount].vacDate[1].day == 0)
			{
				break;
			}
			else
			{
				ApartDays = m[*pcount].vacDate[1].day - m[*pcount].vacDate[0].day + 30 * (m[*pcount].vacDate[1].month - m[*pcount].vacDate[0].month) + 360 * (m[*pcount].vacDate[1].year - m[*pcount].vacDate[0].year);
				if (ApartDays >= 24)
				{
					break;
				}
			}
		}
	}
	(*pcount)++;
	return 0;
}

int Dele(VacInfo m[],int *pcount)
{
	int i = SearchbyName(m, *pcount);
	if (i != -1)
	{
		(*pcount)--;
		m[i] = m[*pcount];
		return 0;
	}
	
	printf("Delete record failed!\n");
	return -1;
}




int SearchbyName(VacInfo m[], int count)
{
	char lookfor[NAMESIZE];
	char temp;
	printf("Please input your name:");
	while (temp = getchar() != '\n' && temp != EOF);
	gets_s(lookfor);
	int index = -1;
	for (int i = 0; i < count; i++)
	{
		if (strcmp(m[i].name, lookfor) == 0)
		{
			index = i;
			break;
		}
	}
	if (index != -1)
	{
		printf("Name:%20s Age:%4d Tel:%12s\n", m[index].name, m[index].age, m[index].tel);
		printf("First Dose:%d/%d/%d  Second Dose:%d/%d/%d\n", m[index].vacDate[0].year, m[index].vacDate[0].month, m[index].vacDate[0].day, m[index].vacDate[1].year, m[index].vacDate[1].month, m[index].vacDate[1].day);
		printf("----------------------------------------\n");
	}
	else
	{
		printf("Can't find %s", lookfor);
	}
	return index;
}

void PrintAll(const VacInfo m[], const int count)
{
	for (int i = 0; i < count; i++)
	{
		printf("Name:%20s Age:%4d Tel:%12s\n", m[i].name, m[i].age, m[i].tel);
		printf("First Dose:%d/%d/%d  Second Dose:%d/%d/%d\n", m[i].vacDate[0].year, m[i].vacDate[0].month, m[i].vacDate[0].day, m[i].vacDate[1].year, m[i].vacDate[1].month, m[i].vacDate[1].day);
		printf("----------------------------------------\n");
	}
}



void SendMsg(const VacInfo m[], const int count)
{
	
}

