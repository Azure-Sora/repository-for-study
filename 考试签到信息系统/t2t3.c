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
	int studentNo;			//ѧ��
	char nameStr[20];		//����
	time_t checkinTime;		//time_t��ʽ��ǩ��ʱ��
	time_t checkoutTime;	//time_t��ʽ��ǩ��ʱ��
	char subject[20];		//���Կ�Ŀ
	unsigned char chksum;	//������ʹ��
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
	printf("������ɣ�\n");
}

int ReadDataFromFile(char* fname, checkinData data[])
{
	int iCount = 0;
	int iRet;
	unsigned char* chksumold, newchksum;	//������Ŀʹ��

	//��fname�ļ�
	FILE* fp = fopen(fname, "rb");

	//�򿪴�����ʾ������-1��
	/*
	your code here
	*/
	if (fp == NULL)
	{
		printf("�ļ���ȡʧ�ܣ�\n");
		return -1;
	}


	//ѭ����ȡ���ṹ������data[]
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

	//�ر��ļ�
	fclose(fp);

	//������ʹ�ã�����У����	
	/*
	your code here
	*/

	printf("���ļ�%s���� %d ����¼\n\n", fname, iCount);


	//���ض����ļ�¼���ṹ�壩����
	return iCount;
}

int WriteDataFromFile(char* fname, checkinData data[], int nCount)
{
	int i = 0;


	//��fname�ļ�
	FILE* fp = fopen(fname, "wb");

	//�򿪴�����ʾ������-1��
	/*
	your code here
	*/
	if (fp == NULL)
	{
		printf("���ļ�ʧ�ܣ�\n");
		return -1;
	}


	//������ʹ�ã�����У����	
	/*
	your code here
	*/



	//һ����д�ṹ������data[]���ļ�
	/*
	your code here
	*/
	fwrite(data, sizeof(checkinData), nCount, fp);

	//�ر��ļ�
	fclose(fp);

	printf("д�� %d ����¼���ļ�%s\n\n", nCount, fname);

	//���ض����ļ�¼���ṹ�壩����
	return nCount;
}


void displayMenu()
{
	puts("********����ǩ��ϵͳ********");
	puts("1 ѧ��ǩ��");
	puts("2 ѧ��ǩ��");
	puts("3 ��������");
	puts("4 ��ʾȫ����Ϣ");
	puts("5 ��ʾδ����ѧ��");
	puts("6 ��ʾ�ѽ���ѧ��");
	puts("7 �˳�");
	puts("***************************");
	puts("\n");

}

int search(int no, checkinData data[], int count)
{
	//����ѧ�Ų�ѯ
	/*
	your code here
	*/
	//��ѯ��
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
	//����checkin��Ϣ	
	/*
	your code here
	*/
	checkinData tmp;
	int id;
	char temp;
	printf("\n������ID��");
	scanf("%d", &id);
	if (search(id, data, count) != -1)
	{
		printf("��ǩ����");
		return count;
	}
	tmp.studentNo = id;
	printf("������������");
	char name[20];
	while (temp = getchar() != '\n' && temp != EOF);
	scanf("%s", name);
	strcpy(tmp.nameStr, name);
	printf("�������Ŀ��");
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
	//����checkout	
	/*
	your code here
	*/
	int tmpNo, id;
	checkinData* p;
	printf("\n������ID��");
	scanf("%d", &tmpNo);
	id = search(tmpNo, data, count);
	/*
	your code here
	*/
	//��ѯ����
	if (id < 0)
	{
		puts("���󣺸�ѧ��δǩ��");
		return -1;
	}
	p = &data[id];
	//�Ѿ�ǩ��
	if (p->checkoutTime > 0)
	{
		puts("���󣺸�ѧ���Ѿ�ǩ��");
		return -1;
	}
	p->checkoutTime = time(NULL);

	return 1;
}


void displayARecord(checkinData* p)
{
	/*
	your code here
	int studentNo;			//ѧ��
	char nameStr[20];		//����
	time_t checkinTime;		//time_t��ʽ��ǩ��ʱ��
	time_t checkoutTime;	//time_t��ʽ��ǩ��ʱ��
	char subject[20];		//���Կ�Ŀ
	unsigned char chksum;	//������ʹ��
	*/
	char checkinTime[50];
	strftime(checkinTime, 50, "%x %X", &(p->checkinTime));
	char checkoutTime[50];
	if (p->checkoutTime != 0)
	{
		strftime(checkoutTime, 50, "%x %X", &(p->checkoutTime));
	}
	printf("\nѧ��:%d\n����:%s\nǩ��ʱ��:%s\nǩ��ʱ��:%s\n���Կ�Ŀ:%s\n", p->studentNo, p->nameStr, checkinTime, checkoutTime, p->subject);
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
