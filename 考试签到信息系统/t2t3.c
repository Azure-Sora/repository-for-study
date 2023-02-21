#include <stdio.h>
#include <string.h>
#include <time.h>

unsigned char getChksum(unsigned char* p, int len)
{

	unsigned char chkSum = 0;
	for (int i = 0; i < len; i++)
	{
		chkSum += p[i];
	}
	return chkSum;
	/*
	your code for calculate chksum of p
	*/
}


typedef struct tagcheckinData
{
	int studentNo;			//学号
	char nameStr[20];		//姓名
	time_t checkinTime;		//time_t格式的签到时间
	time_t checkoutTime;	//time_t格式的签退时间
	char subject[20];		//考试科目
	unsigned char chksum;	//第三题使用
}checkinData;


void partBubbleSort(checkinData* data, int start, int count)
{
	/*
	your code here
	*/
	for (int i = start; i < count; i++)
	{
		for (int j = start; j < count - i; j++)
		{
			if (data[j].studentNo > data[j + 1].studentNo)
			{
				checkinData temp = data[j];
				data[j] = data[j + 1];
				data[j + 1] = temp;
			}
		}
	}
	printf("排序完成！\n");
}

int ReadDataFromFile(char* fname, checkinData data[])
{
	int iCount = 0;
	int iRet;
	unsigned char* chksumold, newchksum;	//第三题目使用

	//打开fname文件
	FILE* fp = fopen(fname, "rb");

	//打开错误，提示并返回-1；
	/*
	your code here
	*/
	if (fp == NULL)
	{
		printf("文件读取失败！\n");
		return -1;
	}


	//循环读取到结构体数组data[]
	/*
	your code here
	*/
	while (1)
	{
		int dataExist = 1;
		dataExist = fread(&data[iCount], sizeof(checkinData), 1, fp);
		if (dataExist)
		{
			iCount++;
		}
		else
		{
			break;
		}
	}

	//关闭文件
	fclose(fp);

	//第三题使用，计算校验码	
	/*
	your code here
	*/

	printf("从文件%s读到 %d 条记录\n\n", fname, iCount);


	//返回读到的记录（结构体）个数
	return iCount;
}

int WriteDataFromFile(char* fname, checkinData data[], int nCount)
{
	int i = 0;


	//打开fname文件
	FILE* fp = fopen(fname, "wb");

	//打开错误，提示并返回-1；
	/*
	your code here
	*/
	if (fp == NULL)
	{
		printf("打开文件失败！\n");
		return -1;
	}


	//第三题使用，计算校验码	
	/*
	your code here
	*/



	//一次性写结构体数组data[]到文件
	/*
	your code here
	*/
	fwrite(data, sizeof(checkinData), nCount, fp);

	//关闭文件
	fclose(fp);

	printf("写入 %d 条记录到文件%s\n\n", nCount, fname);

	//返回读到的记录（结构体）个数
	return nCount;
}


void displayMenu()
{
	puts("********考试签到系统********");
	puts("1 学生签到");
	puts("2 学生签退");
	puts("3 部分排序");
	puts("4 显示全部信息");
	puts("5 显示未交卷学生");
	puts("6 显示已交卷学生");
	puts("7 退出");
	puts("***************************");
	puts("\n");

}

int search(int no, checkinData data[], int count)
{
	//根据学号查询
	/*
	your code here
	*/
	//查询到
	for (int i = 0; i < count; i++)
	{
		int idOfIndex = data[i].studentNo;
		if (no == idOfIndex)
		{
			return i;
		}
	}
	return -1;
}

int checkin(checkinData data[], int count)
{
	//输入checkin信息	
	/*
	your code here
	*/
	checkinData tmp;
	int id;
	char temp;
	printf("\n请输入ID：");
	scanf("%d", &id);
	if (search(id, data, count) != -1)
	{
		printf("已签到！");
		return count;
	}
	tmp.studentNo = id;
	printf("请输入姓名：");
	char name[20];
	while (temp = getchar() != '\n' && temp != EOF);
	scanf("%s", name);
	strcpy(tmp.nameStr, name);
	printf("请输入科目：");
	char subject[20];
	while (temp = getchar() != '\n' && temp != EOF);
	scanf("%s", subject);
	strcpy(tmp.subject, subject);
	tmp.checkoutTime = 0;
	tmp.checkinTime = time(NULL);
	data[count] = tmp;
	return count + 1;
}

int checkout(checkinData data[], int count)
{
	//输入checkout	
	/*
	your code here
	*/
	int tmpNo, id;
	checkinData* p;
	printf("\n请输入ID：");
	scanf("%d", &tmpNo);
	id = search(tmpNo, data, count);
	/*
	your code here
	*/
	//查询不到
	if (id < 0)
	{
		puts("错误：该学生未签到");
		return -1;
	}
	p = &data[id];
	//已经签退
	if (p->checkoutTime > 0)
	{
		puts("错误：该学生已经签退");
		return -1;
	}
	p->checkoutTime = time(NULL);

	return 1;
}


void displayARecord(checkinData* p)
{
	/*
	your code here
	int studentNo;			//学号
	char nameStr[20];		//姓名
	time_t checkinTime;		//time_t格式的签到时间
	time_t checkoutTime;	//time_t格式的签退时间
	char subject[20];		//考试科目
	unsigned char chksum;	//第三题使用
	*/
	char checkinTime[50];
	strftime(checkinTime, 50, "%x %X", &(p->checkinTime));
	char checkoutTime[50];
	if (p->checkoutTime != 0)
	{
		strftime(checkoutTime, 50, "%x %X", &(p->checkoutTime));
	}
	printf("\n学号:%d\n姓名:%s\n签到时间:%s\n签退时间:%s\n考试科目:%s\n", p->studentNo, p->nameStr, checkinTime, checkoutTime, p->subject);
}

void displayall(checkinData data[], int count)
{
	/*
	your code here
	*/
	for (int i = 0; i < count; i++)
	{
		displayARecord(&data[i]);
	}
}

void displayUnChkout(checkinData data[], int count)
{
	/*
	your code here
	*/
	for (int i = 0; i < count; i++)
	{
		if (data[i].checkoutTime == 0)
		{
			displayARecord(&data[i]);
		}

	}
}

void displayChkout(checkinData data[], int count)
{
	/*
	your code here
	*/
	for (int i = 0; i < count; i++)
	{
		if (data[i].checkoutTime != 0)
		{
			displayARecord(&data[i]);
		}

	}
}

int main()
{
	int key;
	int quit = 0;

	checkinData gData[100];
	int gCount = 0;

	int ret = gCount = ReadDataFromFile("checkin.dat", gData);
	if (ret != -1)
		gCount = ret;

	while (1)
	{
		displayMenu();
		scanf("%d", &key);
		switch (key)
		{
		case 1: gCount = checkin(gData, gCount);
			break;
		case 2: checkout(gData, gCount);
			break;
		case 3: partBubbleSort(gData, 1, gCount - 1);
			break;
		case 4: displayall(gData, gCount);
			break;
		case 5: displayUnChkout(gData, gCount);
			break;
		case 6: displayChkout(gData, gCount);
			break;
		case 7: quit = 1;
			break;
		default:
			break;
		}
		if (quit == 1)
			break;
	}
	WriteDataFromFile("checkin.dat", gData, gCount);

	return 1;
}
