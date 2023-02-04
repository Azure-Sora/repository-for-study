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



//maxlen为数组允许存放的最大长度，不是目前文件数据数组的长度 
//返回值为读取成功记录数
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
