#include<iostream>
using namespace std;

template <class E>
void insertionSort(E arr[], int n)
{
	auto insert = [&](int src, int pos) {//把新元素插入到pos的后面
		E val = arr[src];
		while (src - 1 != pos)
		{
			arr[src] = arr[src - 1];
			src--;
		}
		arr[src] = val;
	};

	auto binarySearch = [&](int high, int low, int target) {//在有序区间二分查找找到小于等于目标元素的最大元素位置
		int mid = 0;
		while (low != high)
		{
			mid = (low + high) / 2;
			if (arr[mid] >= arr[target])
			{
				high = mid;
			}
			else
			{
				low = (low == mid) ? mid + 1 : mid;
			}
		}
		return (arr[low] <= arr[target]) ? low : low - 1;
	};

	for (int i = 0; i < n; i++)
	{
		if (i == 0) continue;
		int pos = binarySearch(i - 1, 0, i);
		insert(i, pos);
	}
}

int test()
{
	int a;
	a = 5;
	a += 1;
	TEST:
	return 0xdeadbeef;
	goto TEST;
}

int main()
{

	/*int arr[] = { 5,6,8,6,3,1,0,13,6,2 };

	insertionSort(arr, 10);

	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << endl;
	}*/


	// char cstr[5] = { '1','2','\0','4','\0' };
	// string stdstr;
	// stdstr.assign(cstr, 5);
	// int a = stdstr.length();
	// system("PAUSE");

	return 0;
}