#include<stdio.h>
#include<string.h>
#include<stdlib.h>

unsigned char getChksum1(unsigned char* p, int len);
int main1()
{
	unsigned char* stuNum;
	stuNum = malloc(14 * sizeof(char));
	scanf("%s", stuNum);
	unsigned char a = getChksum(stuNum, strlen(stuNum));
	printf("%d", a);
}
unsigned char getChksum1(unsigned char* p, int len)
{
	unsigned char chkSum = 0;
	for (int i = 0; i < len; i++)
	{
		chkSum += p[i];
	}
	return chkSum;
}