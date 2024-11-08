#include <stdio.h>
#include <stdlib.h>

int myfib(int n)
{
	if (n < 3) { return 1; }
	return myfib(n - 2) + myfib(n - 1);
}

int fib(int n)
{
	return myfib(n);
}

void main(int argc,char** argv)
{
	int x = atoi(argv[1]);
	printf("fib(%d)=%d\n", x, fib(x));
}