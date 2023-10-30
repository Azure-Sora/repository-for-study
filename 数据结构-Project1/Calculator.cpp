#include "Calculator.h"
#include"Stack.cpp"
#include<string>
#include<cmath>
using namespace std;

string Calculator::toPostfixExpression(string src)
{
	Stack<char> stack;
	string output;
	while (src.find("sin") != string::npos)//预处理输入，把三角函数转为易处理的单个符号
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
	while (src.find("lg") != string::npos)//预处理输入，把常用对数转为易处理的单个符号
	{
		src.replace(src.find("lg"), 2, "G");
	}
	bool isFrontNumber = false;//标记上一个是数还是运算符，用于处理多位数和小数
	bool isFrontOperator = true;
	for (auto &s : src)//遍历输入
	{
		if ((s >= '0' && s <= '9') || (s == '.'))//数字直接拼接
		{
			output = output + s;
			isFrontNumber = true;
			isFrontOperator = false;
			continue;
		}
		else
		{
			if (isFrontNumber)//如果正在处理运算符且上一个为数字，拼接一个空格分隔
			{
				output = output + " ";
				isFrontNumber = false;
			}
			if (isFrontOperator && s == '-')//处理负数
			{
				output = output + "-";
				continue;
			}
			isFrontOperator = true;

			if (s == '(')//左括号直接入栈
			{
				stack.push('(');
			}
			else if (s == ')')//右括号直接出栈，直到遇到左括号
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
					while (!stack.empty() && getOperatorPriority(stack.topValue()) >= getOperatorPriority(s))//将运算优先级更大的符号全部出栈，然后自己入栈
					{
						output = output + stack.topValue() + " ";
						stack.pop();
					}
					stack.push(s);
				}
			}
		}
	}
	while (!stack.empty())//清空栈里剩余的运算符
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

double Calculator::CalculatePostfix(string str) 
{
	Stack<double> stack;
	string NumOrOperator = "0123456789+-*/^SCTG";//定义数字和运算符号，方便之后查找
	int start, end;
	double Num, FirstNum, SecondNum;
	const double Pi = acos(-1.0);//定义圆周率派
	for (int i = 0; i < str.length();) 
	{
		start = str.find_first_of(NumOrOperator,i);//找到第一个操作数或者运算符
		end = str.find_first_of(" ", i);//找到第一个空格
		if (end == -1) 
		{
			end = str.length();
		}
		string tempstr = str.substr(start, end - start);//截取操作数或者运算符
		if(tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/" || tempstr == "^")//处理加减乘除幂
		{
			SecondNum = stack.topValue();
			stack.pop();
			FirstNum = stack.topValue();
			stack.pop();//拿出前两个需要操作的数
			if(tempstr == "+")
			{
				Num = FirstNum + SecondNum;
				stack.push(Num);
			}
			if (tempstr == "-") 
			{
				Num = FirstNum - SecondNum;
				stack.push(Num);
			}
			if (tempstr == "*") 
			{
				Num = FirstNum * SecondNum;
				stack.push(Num);
			}
			if (tempstr == "/") 
			{
				Num = FirstNum / SecondNum;
				stack.push(Num);
			}
			if (tempstr == "^") 
			{
				Num = pow(FirstNum, SecondNum);
				stack.push(Num);
			}
		}
		else if (tempstr == "S" || tempstr == "C" || tempstr == "T")//处理三角函数
		{
			FirstNum = stack.topValue();
			stack.pop();
			FirstNum = FirstNum * Pi / 180;//把角度转换为弧度
			if (tempstr == "S") 
			{
				Num = sin(FirstNum);
				stack.push(Num);
			}
			if (tempstr == "C") 
			{
				Num = cos(FirstNum);
				stack.push(Num);
			}
			if (tempstr == "T") 
			{
				Num = tan(FirstNum);
				stack.push(Num);
			}
		}
		else if(tempstr == "G")//处理对数函数，默认以10为底
		{
			FirstNum = stack.topValue();
			stack.pop();
			Num = log10(FirstNum);
			stack.push(Num);
		}
		else
		{
			stack.push(stod(tempstr));//读到的为数，则转换为double并且入栈
		}
		i = end + 1;//控制下标移动
	}

	return stack.topValue();
}

int Calculator::getOperatorPriority(char op)//定义操作符优先级
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
	else if (op == 'S' || op == 'C' || op == 'T' || op == 'G')
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
	string input;
	in >> input;
	if (input == "exit") exit(0);
	input = cacu.toPostfixExpression(input);
	cout << endl << "后缀表达式为：" << input << endl;
	cout << "结果为：" << cacu.CalculatePostfix(input);
}
