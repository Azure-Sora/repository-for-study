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
	cout << "����������ѡ����:\n1.�����ļ�\n2.�����ļ�\n3.�˳�����" << endl;
}

void function()
{
	Coder cd;
	string choice;
	cin >> choice;
	if (choice == "1")
	{
		string file;
		cout << "�������ļ�����";
		cin >> file;
		cd.encodeFile(file);
	}
	else if (choice == "2")
	{
		string file;
		cout << "�������ļ�����";
		cin >> file;
		cd.decodeFile(file);
	}
	else if (choice == "3")
	{
		exit(0);
	}
	else
	{
		cout << "���벻��ȷ��" << endl;
	}
	system("PAUSE");
}
