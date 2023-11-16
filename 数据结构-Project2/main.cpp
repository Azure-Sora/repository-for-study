#include<iostream>
#include"Heap.h"
#include"Coder.h"
using namespace std;
class Coder;
void showMenu();
void function();

int main()
{
	while (true)
	{
		showMenu();
		function();
		system("CLS");
	}
	return 0;
}

void showMenu()
{
	cout << "请输入数字选择功能:\n1.编码文件\n2.解码文件\n3.退出程序" << endl;
}

void function()
{
	Coder cd;
	string choice;
	cin >> choice;
	if (choice == "1")
	{
		string file;
		cout << "请输入文件名：";
		cin >> file;
		cd.encodeFile(file);
	}
	else if (choice == "2")
	{
		string file;
		cout << "请输入文件名：";
		cin >> file;
		cd.decodeFile(file);
	}
	else if (choice == "3")
	{
		exit(0);
	}
	else
	{
		cout << "输入不正确！" << endl;
	}
	system("PAUSE");
}
