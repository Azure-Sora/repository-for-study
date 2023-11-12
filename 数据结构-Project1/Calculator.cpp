#include "Calculator.h"
#include"Stack.h"
#include<string>
#include<cmath>
#include<exception>
using namespace std;

string Calculator::toPostfixExpression(string src)
{
	Stack<char> stack;
	string output;
	simplifyExpression(src);
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
			isFrontNumber = false;
		}
		output = output + stack.topValue() + " ";
		stack.pop();
	}
	return output;
}

double Calculator::CalculatePostfix(string str) 
{
	Stack<double> stack;
	string NumOrOperator = "0123456789+-*/^SCTG!";//定义数字和运算符号，方便之后查找
	int start, end;
	double Num, FirstNum, SecondNum;
	const double Pi = acos(-1.0);//定义圆周率派
	try
	{
		for (int i = 0; i < str.length();)
		{
			start = str.find_first_of(NumOrOperator, i);//找到第一个操作数或者运算符
			end = str.find_first_of(" ", i);//找到第一个空格
			if (end == -1)
			{
				end = str.length();
			}
			string tempstr = str.substr(start, end - start);//截取操作数或者运算符
			if (tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/" || tempstr == "^")//处理加减乘除幂
			{
				SecondNum = stack.topValue();
				stack.pop();
				FirstNum = stack.topValue();
				stack.pop();//拿出前两个需要操作的数
				if (tempstr == "+")
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
			else if (tempstr == "G")//处理对数函数，默认以10为底
			{
				FirstNum = stack.topValue();
				stack.pop();
				Num = log10(FirstNum);
				stack.push(Num);
			}
			else if (tempstr == "!")
			{
				FirstNum = stack.topValue();
				stack.pop();
				Num = tgamma(FirstNum + 1);
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
	catch (exception& e)
	{
		throw e;
	}
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
	else if (op == '^' || op == '!')
	{
		return 3;
	}
	else if (op == 'S' || op == 'C' || op == 'T' || op == 'G')
	{
		return 4;
	}
}

double Calculator::calculateInfix(string src)
{
	Stack<char> opStack;
	Stack<double> numStack;
	double output;
	string multientryOp = "+-*/^";
	string unimal = "!SCTG";
	try
	{
		simplifyExpression(src);
		bool isFrontNumber = false;//标记上一个是数还是运算符，用于处理多位数和小数
		bool isFrontOperator = true;
		string tempNum = "";
		string tempExpression;
		for (auto& s : src)//遍历输入
		{
			if ((s >= '0' && s <= '9') || (s == '.'))//数字拼接
			{
				tempNum = tempNum + s;
				isFrontNumber = true;
				isFrontOperator = false;
				continue;
			}
			else
			{
				if (isFrontNumber)//如果正在处理运算符且上一个为数字，数字入栈
				{
					numStack.push(stod(tempNum));
					tempNum = "";
					isFrontNumber = false;
				}
				if (isFrontOperator && s == '-')//处理负数
				{
					tempNum = tempNum + "-";
					continue;
				}
				isFrontOperator = true;

				if (s == '(')//左括号直接入栈
				{
					opStack.push('(');
				}
				else if (s == ')')//右括号直接出栈，直到遇到左括号
				{
					while (opStack.topValue() != '(')
					{
						try
						{
							judgeOperandAndCalculate(multientryOp, opStack, tempExpression, numStack);
						}
						catch (exception& e)
						{
							throw e;
						}
					}
					opStack.pop();
				}
				else
				{
					if (opStack.empty())
					{
						opStack.push(s);
					}
					else
					{
						while (!opStack.empty() && getOperatorPriority(opStack.topValue()) >= getOperatorPriority(s))//将运算优先级更大的符号全部出栈，然后自己入栈
						{
							try
							{
								judgeOperandAndCalculate(multientryOp, opStack, tempExpression, numStack);
							}
							catch (exception& e)
							{
								throw e;
							}
						}
						opStack.push(s);
					}
				}
			}
		}
		if (tempNum != "") numStack.push(stod(tempNum));
		while (!opStack.empty())//清空栈里剩余的运算符
		{
			try
			{
				judgeOperandAndCalculate(multientryOp, opStack, tempExpression, numStack);
			}
			catch (exception& e)
			{
				throw e;
			}
		}

		if (numStack.getLength() == 1)
		{
			return numStack.topValue();
		}
		else
		{
			cout << "表达式不正确！" << endl;
			throw *(new exception("exception"));
			
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

double Calculator::calculateShortInfix(string src)
{
	string NumOrOperator = "0123456789+-*/^SCTG!";//定义数字和运算符号，方便之后查找
	int start, end;
	double Num, FirstNum, SecondNum;
	const double Pi = acos(-1.0);//定义圆周率派
	for (int i = 0; i < src.length();)
	{
		start = src.find_first_of(NumOrOperator, i);//找到第一个操作数或者运算符
		end = src.find_first_of(" ", i);//找到第一个空格
		if (end == -1)
		{
			end = src.length();
		}
		string tempstr = src.substr(start, end - start);//截取操作数或者运算符
		if (tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/" || tempstr == "^")//处理加减乘除幂
		{
			if (tempstr == "+")
				Num = FirstNum + SecondNum;
			if (tempstr == "-")
				Num = FirstNum - SecondNum;
			if (tempstr == "*")
				Num = FirstNum * SecondNum;
			if (tempstr == "/")
				Num = FirstNum / SecondNum;
			if (tempstr == "^")
				Num = pow(FirstNum, SecondNum);
		}
		else if (tempstr == "S" || tempstr == "C" || tempstr == "T")//处理三角函数
		{
			SecondNum = SecondNum * Pi / 180;//把角度转换为弧度
			if (tempstr == "S")
				Num = sin(SecondNum);
			if (tempstr == "C")
				Num = cos(SecondNum);
			if (tempstr == "T")
				Num = tan(SecondNum);
		}
		else if (tempstr == "G" )//处理对数函数，默认以10为底
			Num = log10(SecondNum);
		else if (tempstr == "!")
			Num = tgamma(SecondNum + 1);
		else if(i == 0)
			SecondNum = stod(tempstr);
		else
			FirstNum = stod(tempstr);
		i = end + 1;//控制下标移动
	}
	return Num;
}

void Calculator::judgeOperandAndCalculate(string& multientryOp, Stack<char>& opStack, string& tempExpression, Stack<double>& numStack)//判断运算符是单目还是双目的，以此取出相应数量操作数进行计算
{
	try
	{
		if (multientryOp.find(opStack.topValue()) != string::npos)
		{
			for (int i = 0; i < 2; i++)
			{
				if (numStack.getLength() == 0)//如果操作数不够了，证明表达式有问题
				{
					cout << "表达式不正确！" << endl;
					throw* (new exception("exception"));
					return;
				}
				tempExpression = tempExpression + to_string(numStack.topValue()) + " ";
				numStack.pop();
			}
			tempExpression = tempExpression + opStack.topValue();
			opStack.pop();
			numStack.push(calculateShortInfix(tempExpression));//把小表达式交给计算函数进行运算
			tempExpression = "";
		}
		else
		{
			if (numStack.getLength() == 0)
			{
				cout << "表达式不正确！" << endl;
				throw* (new exception("exception"));
				return;
			}
			tempExpression = tempExpression + to_string(numStack.topValue()) + " ";
			numStack.pop();
			tempExpression = tempExpression + opStack.topValue();
			opStack.pop();
			numStack.push(calculateShortInfix(tempExpression));
			tempExpression = "";
		}
	}
	catch (exception& e)
	{
		throw e;
	}
}

bool Calculator::isExpressionValid(string src)//简单判断表达式有没有易看出的错误
{
	simplifyExpression(src);
	string validChar = "0123456789.+/*-SCTG()!^";
	string multientryOp = "+-*/^";

	for(auto ch : src)
	{
		if (validChar.find(ch) == string::npos) 
		{
			cout << "表达式含有非法字符" << endl;
			return false;
		}
	}
	if (multientryOp.find(src[src.length() - 1]) != string::npos)
	{
		cout << "缺少右操作数" << endl;
		return false;
	}

	return true;
}

void Calculator::simplifyExpression(string& src)
{
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
}

int Calculator::calByPostfix(string src)//用来调起计算的函数
{
	if (isExpressionValid(src))
	{
		src = toPostfixExpression(src);
		cout << "后缀表达式为：" << src << endl;
		try
		{
			cout << "后缀表达式计算结果为：" << CalculatePostfix(src) << endl;
			return 0;
		}
		catch (const std::exception& e)
		{
			string info = e.what();
			if (info == "invalid stod argument")
			{
				cout << "表达式不正确！" << endl;
			}
			else if (info == "invalid string position")
			{
				cout << "括号不匹配！" << endl;
			}
			return -1;
		}
		
	}
}

int Calculator::calByInfix(string src)
{
	if (isExpressionValid(src))
	{
		try
		{
			cout << "中缀表达式计算结果为：" << calculateInfix(src) << endl;
			return 0;
		}
		catch (const std::exception& e)
		{
			string info = e.what();
			if (info == "invalid stod argument")
			{
				cout << "表达式不正确！" << endl;
			}
			else if (info == "invalid string position")
			{
				cout << "括号不匹配！" << endl;
			}

			return -1;
		}

	}
}
