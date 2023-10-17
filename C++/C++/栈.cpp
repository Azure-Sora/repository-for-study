#include<iostream>
#include<stack>
using namespace std;

class myClass
{
	friend bool operator==(myClass& a, myClass& b);

private:
	int a;
	int b;
public:
	myClass(int a, int b) : a(a), b(b) {};



};

bool operator==(myClass& a, myClass& b)
{
	return (a.a == b.a && a.b == b.b) ? true : false;
}

int main()
{

	stack<int>* s = new stack<int>;
	s->push(10);
	
	cout << (new myClass(1, 2) == new myClass(1, 2)) << endl;
	cout << (new myClass(2, 2) == new myClass(1, 2));

	return 0;
}