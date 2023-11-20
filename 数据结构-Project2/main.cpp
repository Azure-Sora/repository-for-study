#include<iostream>
#include"Heap.h"
#include"Coder.h"
using namespace std;
class Coder;
void showMenu();
void function();

int main()//没什么好写的
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
	char input[100];
	cin.getline(input, 100 * sizeof(char));
	string choice = string(input);
	if (choice == "1")
	{
		cout << "请输入文件名：";
		char file[100];
		cin.getline(file, 100 * sizeof(char));
		cd.encodeFile(string(file));
	}
	else if (choice == "2")
	{
		cout << "请输入文件名：";
		char file[100];
		cin.sync();
		cin.getline(file, 100 * sizeof(char));
		cd.decodeFile(string(file));
	}
	else if (choice == "3")
	{
		exit(0);
	}
	else
	{
		cout << "输入不正确！" << endl;
	}
	cin.sync();
	system("PAUSE");
}
