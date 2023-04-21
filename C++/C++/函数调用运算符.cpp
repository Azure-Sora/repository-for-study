#include<iostream>
using namespace std;
class Print
{
public:
	void operator()(string src)
	{
		cout << src;
	}
};

int main()
{
	Print()("1!5!");
	return 0;
}