#include<iostream>
#include"Heap.h"
#include"Coder.h"
using namespace std;
class Coder;
void showMenu();
void function();

int main()//ûʲô��д��
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
	char input[100];
	cin.getline(input, 100 * sizeof(char));
	string choice = string(input);
	if (choice == "1")
	{
		cout << "�������ļ�����";
		char file[100];
		cin.getline(file, 100 * sizeof(char));
		cd.encodeFile(string(file));
	}
	else if (choice == "2")
	{
		cout << "�������ļ�����";
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
		cout << "���벻��ȷ��" << endl;
	}
	cin.sync();
	system("PAUSE");
}
