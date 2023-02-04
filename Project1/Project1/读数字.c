#include<stdio.h>
int fun(int data, int* pArray, int size);
void read(int* pArray, int n);
int main()
{
	int input, abs, nums;
	int size = 0;
	int arr[7];
	while (1)
	{
		printf("请输入[-100000,100000]之间的整数：");
		scanf("%d", &input);
		if (input >= -100000 && input <= 100000)
		{
			break;
		}
	}
	if (input < 0)
	{
		abs = input * (-1);
	}
	else
	{
		abs = input;
	}
	for (int i = 1; abs % i != abs; i = 10 * i)
	{
		size++;
	}
	nums = fun(input, arr, size);
	read(arr, nums);

}
int fun(int data, int* pArray, int size)
{
	int nums = 0;
	int divide = 1;
	for (int i = 0; i < size - 1; i++)
	{
		divide = divide * 10;
	}
	if (data < 0)
	{
		pArray[6] = -1;
		data = data * -1;
		nums++;
	}
	for (int i = 0; i < size; i++)
	{
		*(pArray + i) = data / divide;
		data = data - divide * (data / divide);
		divide = divide / 10;
		nums++;
	}
	return nums;
}
void read(int* pArray, int n)
{
	if (pArray[6] == -1)
	{
		printf("fu ");
		n--;
	}
	for (int i = 0; i < n; i++)
	{
		switch (pArray[i])
		{
		case 0:printf("ling"); break;
		case 1:printf("yi"); break;
		case 2:printf("er"); break;
		case 3:printf("san"); break;
		case 4:printf("si"); break;
		case 5:printf("wu"); break;
		case 6:printf("liu"); break;
		case 7:printf("qi"); break;
		case 8:printf("ba"); break;
		case 9:printf("jiu"); break;
		}
		if (i != (n - 1))
		{
			printf(" ");
		}
	}
}