#include<iostream>
#include"Stack.h"
#include"Calculator.h"
using namespace std;

void showMenu();
void calculate();

int main()
{
	/*Stack<int>* stack = new Stack<int>;
	stack->push(114);
	stack->push(514);

	cout << "length=" << stack->getLength() << endl;
	cout << stack->topValue() << endl;

	stack->pop();

	cout << "length=" << stack->getLength() << endl;
	cout << stack->topValue() << endl;*/

	/*Calculator a;
	string str;
	cin >> str;
	string out = a.toPostfixExpression(str);
	cout << out << endl;
	double temp = a.CalculatePostfix(out);
	cout << temp;*/

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
	/*cin >> cacu;
	cout << endl;*/
	string a;
	cin >> a;
	cout << endl << cacu.calculateInfix(a) << endl;
	system("PAUSE");
}