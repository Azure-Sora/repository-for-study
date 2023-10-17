#include<iostream>
using namespace std;

void hailstone(int n)
{
	cout << n << endl;
	if (n == 1)
	{
		return;
	}
	else if (n % 2 == 0)
	{
		hailstone(n / 2);
	}
	else if (n % 2 == 1)
	{
		hailstone(3 * n + 1);
	}
}

int main()
{
	int n;
	cin >> n;
	hailstone(n);
	return 0;
}