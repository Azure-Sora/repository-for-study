#include<iostream>
using namespace std;
class Number
{
	friend ostream& operator<<(ostream& cout, Number& num);
public:
	Number()
	{
		this->num = 0;
	}
	Number(int num)
	{
		this->num = num;
	}
	int num;
	Number& operator++()
	{
		this->num++;
		return *this;
	}
	Number& operator++(int)
	{
		Number temp = *this;
		this->num++;
		return *this;
	}
	bool operator==(Number& src)
	{
		return this->num == src.num;
	}
	bool operator>(Number& src)
	{
		return this->num > src.num;
	}
	bool operator!=(Number& src)
	{
		return this->num != src.num;
	}
};
ostream& operator<<(ostream& cout, Number& num)
{
	cout << num.num;
	return cout;
}
int main()
{
	Number n1(5);
	Number n2(6);
	cout << (n1 == n2) << endl;
	cout << (n2 > n1) << endl;
	return 0;
}