#include<iostream>
#include"Stack.h"
#include"Calculator.h"
using namespace std;

void showMenu();
void calculate();

int main()
{
	while (1)
	{
		showMenu();
		calculate();
	}

	return 0;
}

void showMenu()
{
	system("CLS");
	cout << "��������ʽ" << endl;
	cout << "֧��+-*/^()��sin cos tan��lg" << endl;
	cout << "��ʽʵ����cos60*lg10000^(2+2)" << endl;
	cout << "����\"exit\"�˳�" << endl;
	cout << "�����룺";
}

void calculate()
{
	Calculator cacu;
	string a;
	cin >> a;

	if (a == "exit") exit(0);

	if (cacu.calByInfix(a) == 0)cacu.calByPostfix(a);
	
	

	system("PAUSE");
}