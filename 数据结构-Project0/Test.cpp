#include<iostream>
#include"List.h"
#include"List.cpp"

using namespace std;
int main()
{
	List<int>* intList = new List<int>;
	intList->loadFormFile("int.txt");
	cout << "IntList：" << endl;
	intList->print();
	cout << "数据2100000000在位置" << intList->search(2100000000) << endl << endl;
	intList->sort();
	cout << "排序后IntList：" << endl;
	intList->print();
	cout << "数据2100000000在位置" << intList->search(2100000000) << endl << endl;

	List<double>* doubleList = new List<double>;
	doubleList->loadFormFile("double.txt");
	cout << "DoubleList：" << endl;
	doubleList->print();
	cout << "数据6.666在位置" << doubleList->search(6.666) << endl << endl;
	doubleList->sort();
	cout << "排序后DoubleList：" << endl;
	doubleList->print();
	cout << "数据6.666在位置" << doubleList->search(6.666) << endl << endl;

	List<string>* stringList = new List<string>;
	stringList->loadFormFile("string.txt");
	cout << "StringList：" << endl;
	stringList->print();
	cout << "数据'原神'在位置" << stringList->search("原神") << endl << endl;
	stringList->sort();
	cout << "排序后StringList：" << endl;
	stringList->print();
	cout << "数据'原神'在位置" << stringList->search("原神") << endl << endl;

	return 0;
}