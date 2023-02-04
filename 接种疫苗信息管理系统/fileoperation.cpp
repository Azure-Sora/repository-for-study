#include <stdio.h>
#include "fileoperation.h"
#include <windows.h>

void inosyswt(VacInfo t[], int size)
{
	FILE  *fp;
	fp = fopen("info.txt", "w");
	if(!fp)
		return;

	fwrite(t, sizeof(VacInfo), size, fp);

	fclose(fp);
	printf("%d records write completed!\n",size);
}



//maxlenΪ���������ŵ���󳤶ȣ�����Ŀǰ�ļ���������ĳ��� 
//����ֵΪ��ȡ�ɹ���¼��
int inosysrd(VacInfo t[],int maxlen)
{
	FILE  *fp;
	int count = 0;
	fp = fopen("info.txt", "r");
	if (!fp)
		return 0;
	fread(t, sizeof(VacInfo), maxlen, fp);
	fclose(fp);
	for (int i = 0; i < maxlen; i++)
	{
		if (t[i].age != 0)
		{
			count++;
		}
		else
		{
			break;
		}
	}
	printf("%d records read completed!\n", count);
	return count;
} 
