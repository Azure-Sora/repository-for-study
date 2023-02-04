#include<iostream>
using namespace std;

int main()
{
	int arr[10];
	cout << "请输入10个数字：";
	for (int i = 0; i < 10; i++)
	{
		cin >> arr[i];
	}
	cout << endl << "原顺序：";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << arr[i];
	}
	int a, b, c = 0 ;
	for (int j = 0; j < 9; j++)
	{
		for (int i = 0; i < 9 - j; i++)
		{
			a = arr[i];
			b = arr[i + 1];
			if (a > b)
			{
				arr[i + 1] = a;
				arr[i] = b;

			}
		}
	}
	cout << endl << "排序后：";
	for (int i = 0; i < 10; i++)
	{
		cout << " " << arr[i];
	}
	return 0;
}
