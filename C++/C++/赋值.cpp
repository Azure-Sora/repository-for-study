#include<iostream>
using namespace std;
class Test
{
	friend ostream& operator<< (ostream& cout, Test& test);
public:
	int* p;
	int n;
	Test& operator= (Test& src)
	{
		if (this->p != NULL)
		{
			delete this->p;
		}
		p = new int(*src.p);
		n = src.n;
		return *this;
	}
	Test()
	{
		this->p = new int[1];
		this->n = 5;
		*p = 10;
	}
	~Test()
	{
		if (this->p != NULL)
		{
			delete this->p;
		}
	}
	
};
ostream& operator<< (ostream& cout, Test& test)
{
	cout << test.n << *test.p;
	return cout;
}
int main()
{
	Test t1;
	Test t2;
	Test t3;
	t3 = t2 = t1;
	cout << t1;
	return 0;
}