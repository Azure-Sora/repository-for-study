#include<iostream>
using namespace std;
void BubbleSort(int arr[]);
int main()
{
	int arr[10];
	cout << "请输入10个数" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << "第" << i + 1 << "个数为：";
		cin >> arr[i];
	}
	BubbleSort(arr);
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}
	return 0;
}
void BubbleSort(int arr[])
{
	for (int i = 0; i < 10; i++)
	{
		int index = i;
		for (int j = i; j < 10; j++)
		{
			if (arr[j] < arr[index])
			{
				index = j;
			}
		}
		if (arr[i] != arr[index])
		{
			int temp = arr[i];
			arr[i] = arr[index];
			arr[index] = temp;
		}
	}
}