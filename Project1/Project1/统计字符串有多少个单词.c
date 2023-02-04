#include<stdio.h>
#include<string.h>
int main()
{
	char words[100];
	int count = 0;
	gets_s(words, 100);
	for (int i = 0; i < 100; i++)
	{
		if (words[i] == ' ')
		{
			count++;
		}
	}
	count++;
	printf("%s中有%d个单词", words, count);
}