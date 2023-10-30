#include "Calculator.h"
#include"Stack.cpp"
#include<string>
using namespace std;

string Calculator::toPostfixExpression(string src)
{
	Stack<char> stack;
	string output;
	bool isFrontNumber;
	//auto s=src.begin(); s!=src.end(); s++
	for (auto s : src)
	{
		if (s >= '0' && s <= '9')
		{
			output = output + s;
			isFrontNumber = true;
			continue;
		}
		else
		{
			if (isFrontNumber)
			{
				output = output + " ";
				isFrontNumber = false;
			}
			if (s == '(')
			{
				stack.push('(');
			}
			else if (s == ')')
			{
				while (stack.topValue() != '(')
				{
					output = output + stack.topValue() + " ";
					stack.pop();
				}
				stack.pop();
			}
			else
			{
				if (stack.empty())
				{
					stack.push(s);
				}
				else
				{
					while (!stack.empty() && getOperatorPriority(stack.topValue()) >= getOperatorPriority(s))
					{
						output = output + stack.topValue() + " ";
						stack.pop();
					}
					stack.push(s);
				}
			}
		}
	}
	while (!stack.empty())
	{
		if (isFrontNumber)
		{
			output = output + " ";
		}
		output = output + stack.topValue() + " ";
		stack.pop();
	}

	return output;
}

double Calculator::CalculatePostfix(string str) {
	Stack<double> stack;
	string NumOrOperator = "0123456789+-*/";
	int start, end;
	double Num, FirstNum, SecondNum;
	for (int i = 0; i < str.length();) {
		start = str.find_first_of(NumOrOperator,i);
		end = str.find_first_of(" ", i);
		string tempstr = str.substr(start, end - start);
		if(tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/"){
			
			SecondNum = stack.topValue();
			stack.pop();
			FirstNum = stack.topValue();
			stack.pop();
			if(tempstr == "+"){
				Num = FirstNum + SecondNum;
				stack.push(Num);
			}
			if (tempstr == "-") {
				Num = FirstNum - SecondNum;
				stack.push(Num);
			}
			if (tempstr == "*") {
				Num = FirstNum * SecondNum;
				stack.push(Num);
			}
			if (tempstr == "/") {
				Num = FirstNum / SecondNum;
				stack.push(Num);
			}
		}else{
			stack.push(stod(tempstr));
		}
		i = end + 1;
	}

	return stack.topValue();
}

int Calculator::getOperatorPriority(char op)
{
	if (op == '(')
	{
		return 0;
	}
	else if (op == '+' || op == '-')
	{
		return 1;
	}
	else if (op == '*' || op == '/')
	{
		return 2;
	}
	else if (op == '^')
	{
		return 3;
	}
}

void Calculator::test()
{
	std::cout << "test";
}

void operator>>(istream& in, Calculator& cacu)
{
	string a;
	in >> a;
	cout << a;
}
