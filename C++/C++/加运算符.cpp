#include<iostream>
using namespace std;
class Point
{
public:
	Point(){}
	Point(int a)
	{
		this->a = a;
	}
	int a;
	Point operator+(Point& p)
	{
		Point temp;
		temp.a = this->a + p.a;
		return temp;
	}
};
int main()
{
	Point p1(5);
	Point p2(10);
	Point p3 = p1 + p2;
	cout << p3.a;
}
//class Person
//{
//public:
//	static string type;
//	Person() {};
//	Person(int age, string name, int weight) :age(age), name(name), weight(new int(weight)) {};
//	Person(const Person& p)
//	{
//		this->age = p.age;
//		this->name = p.name;
//		this->weight = new int(*p.weight);
//	}
//	void showMe()
//	{
//		cout << "age:" << this->age << endl;
//		cout << "name:" << this->name << endl;
//		cout << "weight:" << *this->weight << endl;
//	}
//private:
//	int age;
//	string name;
//	int* weight;
//};
//string Person::type = "ÈË";
//int main()
//{
//	Person p1 = Person(24, "ÌïËù", 100);
//	p1.showMe();
//	Person p2(p1);
//	p2.showMe();
//	cout << Person::type;
//}


