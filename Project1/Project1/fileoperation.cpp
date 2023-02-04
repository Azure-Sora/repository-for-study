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



//maxlen为数组允许存放的最大长度，不是目前文件数据数组的长度 
//返回值为读取成功记录数
int inosysrd(VacInfo t[],int maxlen)
{
	FILE  *fp;
	return 0;
} 
