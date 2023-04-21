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
	Number& operator--()
	{
		this->num--;
		return *this;
	}
	Number& operator--(int)
	{
		Number temp = *this;
		this->num--;
		return *this;
	}
};
ostream& operator<<(ostream& cout, Number& num)
{
	cout << num.num;
	return cout;
}
int main()
{
	Number num1;
	++num1;
	cout << num1 << endl;
	return 0;
}