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
	cout << "请输入表达式" << endl;
	cout << "支持+-*/^()，sin cos tan，lg" << endl;
	cout << "格式实例：cos60*lg10000^(2+2)" << endl;
	cout << "输入\"exit\"退出" << endl;
	cout << "请输入：";
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