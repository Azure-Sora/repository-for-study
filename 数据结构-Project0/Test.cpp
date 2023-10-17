#include<iostream>
#include"List.h"
#include"List.cpp"

using namespace std;
int main()
{
	//List<double>* list = new List<double>;
	//list->append(1.2)->append(2.6)->append(3.3)->append(2.7)->append(6.3)->append(0.2);
	//list->print();
	//list->moveToPos(list->search(3.3));
	////cout << list->getValue();

	//cout << endl;
	//list->sort();
	//list->print();

	/*List<string>* list = new List<string>;
	list->append("456")->append("123")->append("998");
	list->print();

	list->sort();
	list->print();*/
	
	List<int>* list = new List<int>;
	list->loadFormFile("1.txt");
	list->print();

	return 0;
}