#include<iostream>
using namespace std;

int �׳�(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * �׳�(n - 1);
	}
}
int main()
{
	int n;
	cin >> n;
	cout << �׳�(n);
	return 0;
}