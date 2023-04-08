#include<stdio.h>
#include<math.h>

int main() 
{
	unsigned long long i = 11;
	unsigned long long n;
	unsigned long long rn = 2022040920220409;
	/* 189 
	* 
	*/
	while (1)
	{
		n = 187 * i;
		if ((n % 49 == 46) && (n % 48 == 41) && (n % 47 == 50) && (n % 46 == 15) && (n % 45 == 29) && (n % 44 == 33)) {
			printf("it's %lld", n);
			break;
		}
		if ((rn % 49 == 46) && (rn % 48 == 41) && (rn % 47 == 50) && (rn % 46 == 15) && (rn % 45 == 29) && (rn % 44 == 33)) {
			printf("it's %lld", rn);
			break;
		}
		i += 10;
	}
	return 0;
}