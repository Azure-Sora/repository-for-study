#include <stdio.h>
#include "fileoperation.h"
#include <windows.h>

void inosyswt(VacInfo t[], int size)
{
	FILE  *fp;
	fp = fopen("info.txt","w");
	if(!fp)
		return;

	fwrite(t,sizeof(VacInfo),size,fp);

	fclose(fp);
	printf("%d records write completed!\n",size);
}



//maxlenΪ���������ŵ���󳤶ȣ�����Ŀǰ�ļ���������ĳ��� 
//����ֵΪ��ȡ�ɹ���¼��
int inosysrd(VacInfo t[],int maxlen)
{
	FILE  *fp;
	return 0;
} 
