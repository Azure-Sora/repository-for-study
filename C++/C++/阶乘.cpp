#include<iostream>
using namespace std;

int ½×³Ë(int n)
{
	if (n == 1)
	{
		return 1;
	}
	else
	{
		return n * ½×³Ë(n - 1);
	}
}
int main()
{
	int n;
	cin >> n;
	cout << ½×³Ë(n);
	return 0;
}