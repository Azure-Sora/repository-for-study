#include<iostream>
#include"Stack.h"
#include"Calculator.h"
using namespace std;

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

	Calculator a;
	string str;
	cin >> str;
	string out = a.toPostfixExpression(str);
	cout << out << endl;
	double temp = a.CalculatePostfix(out);
	cout << temp;

	return 0;
}