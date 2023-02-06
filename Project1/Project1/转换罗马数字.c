#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//void convertNumbers(char* input, char** destination);
int main()
{
	char input[50];
	while (1)
	{
		scanf("%s", input);
		int whetherInputInvalid = 0;
		for (int i = 0; input[i] != '\0'; i++)
		{
			if (!(input[i] >= '0' && input[i] <= '9') || strlen(input) > 9)
			{
				whetherInputInvalid = 1;
				break;
			}
		}
		if (whetherInputInvalid) {
			printf(" ‰»ÎŒﬁ–ß£°\n");
		}
		else
		{
			break;
		}
	}
	//char** romanNumerals = (char**)malloc(strlen(input) * sizeof(char*));
	/*for (int i = 0; i < strlen(input); i++)
	{
		romanNumerals[i] = (char*)malloc(5 * sizeof(char));
	}*/
	int length = strlen(input);
	char romanNumerals[9][5];
	const char allRomanNumerals[][5] = {"  ", "I ", "II ", "III ", "IV ", "V ", "VI ", "VII ", "VIII ", "IX "};
	for (int i = 0; input[i] != '\0'; i++)
	{
		int index = input[i] - '0';
		strcpy(romanNumerals[i], allRomanNumerals[index]);
	}
	strcpy(romanNumerals, romanNumerals);
	for (int i = 0; input[i] != '\0'; i++)
	{
		printf("%s", romanNumerals[i]);
	}
	return 0;
}
//void convertNumbers(char* input, char** destination)
//{
//	int length = strlen(input);
//	char convertedNumbers[9][5];
//	const char allRomanNumerals[][5] = {"  ", "I ", "II ", "III ", "IV ", "V ", "VI ", "VII ", "VIII ", "IX "};
//	for (int i = 0; input[i] != '\0'; i++)
//	{
//		int index = input[i] - '0';
//		strcpy(convertedNumbers[i], allRomanNumerals[index]);
//	}
//	destination = convertedNumbers;
//}