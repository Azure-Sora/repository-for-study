#include "Calculator.h"
#include"Stack.cpp"
#include<string>
#include<cmath>
using namespace std;

string Calculator::toPostfixExpression(string src)
{
	Stack<char> stack;
	string output;
	while (src.find("sin") != string::npos)//Ԥ�������룬�����Ǻ���תΪ�״���ĵ�������
	{
		src.replace(src.find("sin"), 3, "S");
	}
	while (src.find("cos") != string::npos)
	{
		src.replace(src.find("cos"), 3, "C");
	}
	while (src.find("tan") != string::npos)
	{
		src.replace(src.find("tan"), 3, "T");
	}
	bool isFrontNumber = false;//�����һ��������������������ڴ����λ����С��
	bool isFrontOperator = true;
	for (auto s : src)//��������
	{
		if ((s >= '0' && s <= '9') || (s == '.'))//����ֱ��ƴ��
		{
			output = output + s;
			isFrontNumber = true;
			isFrontOperator = false;
			continue;
		}
		else
		{
			if (isFrontNumber)//������ڴ������������һ��Ϊ���֣�ƴ��һ���ո�ָ�
			{
				output = output + " ";
				isFrontNumber = false;
			}
			isFrontOperator = true;
			if (isFrontOperator && s == '-')//������
			{
				output = output + "-";
				continue;
			}

			if (s == '(')//������ֱ����ջ
			{
				stack.push('(');
			}
			else if (s == ')')//������ֱ�ӳ�ջ��ֱ������������
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
					while (!stack.empty() && getOperatorPriority(stack.topValue()) >= getOperatorPriority(s))//���������ȼ�����ķ���ȫ����ջ��Ȼ���Լ���ջ
					{
						output = output + stack.topValue() + " ";
						stack.pop();
					}
					stack.push(s);
				}
			}
		}
	}
	while (!stack.empty())//���ջ��ʣ��������
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
	string NumOrOperator = "0123456789+-*/^SCT";
	int start, end;
	double Num, FirstNum, SecondNum;
	const double Pi = acos(-1.0);
	for (int i = 0; i < str.length();) {
		start = str.find_first_of(NumOrOperator,i);
		end = str.find_first_of(" ", i);
		string tempstr = str.substr(start, end - start);
		if(tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/" || tempstr == "^"){
			
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
			if (tempstr == "^") {
				Num = 1;
				for(int i = 0;i < SecondNum;i++){
					Num = Num * FirstNum;
				}
				//Num = pow(FirstNum, SecondNum);
				stack.push(Num);
			}
		}else if(tempstr == "S" || tempstr == "C" || tempstr == "T"){
			FirstNum = stack.topValue();
			stack.pop();
			FirstNum = FirstNum * Pi / 180;
			if(tempstr == "S"){
				Num = sin(FirstNum);
				stack.push(Num);
			}
			if(tempstr == "C"){
				Num = cos(FirstNum);
				stack.push(Num);
			}
			if (tempstr == "T") {
				Num = tan(FirstNum);
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
	else if (op == 'S' || op == 'C' || op == 'T')
	{
		return 4;
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
