#include<stdio.h>
//»ÆÌìÓè 2022141461050
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0, k = i; j < 5; j++)
		{
			if (k < 4)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
			k++;
		}
		for (int j = 0, k = i; j < 5; j++)
		{
			if (k < 1)
			{
				printf(" ");
			}
			else
			{
				printf("*");
			}
			k--;
		}
		printf("\n");
	}
	for (int i = 1; i < 5; i++)
	{
		for (int j = 0, k = i; j < 5; j++)
		{
			if (k < 1)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			k--;
		}
		for (int j = 0, k = i; j < 5; j++)
		{
			if (k < 4)
			{
				printf("*");
			}
			else
			{
				printf(" ");
			}
			k++;
		}

		printf("\n");
	}
}