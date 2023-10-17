#include<iostream>
#include"List.h"
#include"List.cpp"

using namespace std;
int main()
{
	List<int>* intList = new List<int>;
	intList->loadFormFile("int.txt");
	cout << "IntList��" << endl;
	intList->print();
	cout << "����2100000000��λ��" << intList->search(2100000000) << endl << endl;
	intList->sort();
	cout << "�����IntList��" << endl;
	intList->print();
	cout << "����2100000000��λ��" << intList->search(2100000000) << endl << endl;

	List<double>* doubleList = new List<double>;
	doubleList->loadFormFile("double.txt");
	cout << "DoubleList��" << endl;
	doubleList->print();
	cout << "����6.666��λ��" << doubleList->search(6.666) << endl << endl;
	doubleList->sort();
	cout << "�����DoubleList��" << endl;
	doubleList->print();
	cout << "����6.666��λ��" << doubleList->search(6.666) << endl << endl;

	List<string>* stringList = new List<string>;
	stringList->loadFormFile("string.txt");
	cout << "StringList��" << endl;
	stringList->print();
	cout << "����'ԭ��'��λ��" << stringList->search("ԭ��") << endl << endl;
	stringList->sort();
	cout << "�����StringList��" << endl;
	stringList->print();
	cout << "����'ԭ��'��λ��" << stringList->search("ԭ��") << endl << endl;

	return 0;
}