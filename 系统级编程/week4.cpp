// #include <stdio.h>
// #include <string.h>
//
// #define MAXLINE_LEN 80
//
// int main(int argc, char* argv[])
// {
// 	char Buffer[MAXLINE_LEN];
// 	char* space;
// 	char* word;
//
// 	printf("Input> ");
// 	do {
// 		if (fgets(Buffer, MAXLINE_LEN, stdin) == NULL) break;
// 		word = Buffer;
// 		while (space = strchr(word, ' '))
// 		{
// 			*space = '\0';
// 			printf("%s\n", word);
// 			word = ++space;
// 			while (*word == ' ') word++;
// 		}
// 		if (strchr(word, '\n')) {
// 			printf("%sInput> ", word);
// 		}
// 		else {
// 			printf("%s\n", word);
// 		}
// 	} while (strncmp(Buffer, "exit", 4));
// 	return 0;
// }
//

#include <cstdint>
#include <cstdio>
#include <cstring>

typedef struct
{
	char a;
	int b;
} test_struct_t;


int main(int argc, char* argv[])
{
	test_struct_t a, b;
	a.a = 0;
	a.b = 0;
	memset(&b, '\0', sizeof(b));
	if (0 == memcmp(&a, &b, sizeof(a)))
	{
		printf("struct a is equal struct b");
	}
	else
	{
		printf("struct a is unequal with struct b");
	}
	return 0;
}
