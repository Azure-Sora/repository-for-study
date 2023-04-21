#include<iostream>
using namespace std;
class Person
{
public:
	Person(int a, int b) :a(a), b(b) {};
	int a;
	int b;
};
ostream& operator<<(ostream& cout, Person& p)
{
	cout << " p.a=" << p.a << " P.b=" << p.b;
	return cout;
}
int main()
{
	Person p1(10, 20);
	Person p2(30, 40);
	cout << p1 << p2 << endl;
	return 0;
}