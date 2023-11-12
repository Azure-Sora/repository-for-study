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
	bool isFrontNumber = false;//�����һ��������������������ڴ����λ����С��
	bool isFrontOperator = true;
	for (auto &s : src)//��������
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
			if (isFrontOperator && s == '-')//������
			{
				output = output + "-";
				continue;
			}
			isFrontOperator = true;

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
	string NumOrOperator = "0123456789+-*/^SCTG!";//�������ֺ�������ţ�����֮�����
	int start, end;
	double Num, FirstNum, SecondNum;
	const double Pi = acos(-1.0);//����Բ������
	try
	{
		for (int i = 0; i < str.length();)
		{
			start = str.find_first_of(NumOrOperator, i);//�ҵ���һ�����������������
			end = str.find_first_of(" ", i);//�ҵ���һ���ո�
			if (end == -1)
			{
				end = str.length();
			}
			string tempstr = str.substr(start, end - start);//��ȡ���������������
			if (tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/" || tempstr == "^")//����Ӽ��˳���
			{
				SecondNum = stack.topValue();
				stack.pop();
				FirstNum = stack.topValue();
				stack.pop();//�ó�ǰ������Ҫ��������
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
			else if (tempstr == "S" || tempstr == "C" || tempstr == "T")//�������Ǻ���
			{
				FirstNum = stack.topValue();
				stack.pop();
				FirstNum = FirstNum * Pi / 180;//�ѽǶ�ת��Ϊ����
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
			else if (tempstr == "G")//�������������Ĭ����10Ϊ��
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
				stack.push(stod(tempstr));//������Ϊ������ת��Ϊdouble������ջ
			}
			i = end + 1;//�����±��ƶ�
		}

		return stack.topValue();
	}
	catch (exception& e)
	{
		throw e;
	}
}

int Calculator::getOperatorPriority(char op)//������������ȼ�
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
		bool isFrontNumber = false;//�����һ��������������������ڴ����λ����С��
		bool isFrontOperator = true;
		string tempNum = "";
		string tempExpression;
		for (auto& s : src)//��������
		{
			if ((s >= '0' && s <= '9') || (s == '.'))//����ƴ��
			{
				tempNum = tempNum + s;
				isFrontNumber = true;
				isFrontOperator = false;
				continue;
			}
			else
			{
				if (isFrontNumber)//������ڴ������������һ��Ϊ���֣�������ջ
				{
					numStack.push(stod(tempNum));
					tempNum = "";
					isFrontNumber = false;
				}
				if (isFrontOperator && s == '-')//������
				{
					tempNum = tempNum + "-";
					continue;
				}
				isFrontOperator = true;

				if (s == '(')//������ֱ����ջ
				{
					opStack.push('(');
				}
				else if (s == ')')//������ֱ�ӳ�ջ��ֱ������������
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
						while (!opStack.empty() && getOperatorPriority(opStack.topValue()) >= getOperatorPriority(s))//���������ȼ�����ķ���ȫ����ջ��Ȼ���Լ���ջ
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
		while (!opStack.empty())//���ջ��ʣ��������
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
			cout << "���ʽ����ȷ��" << endl;
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
	string NumOrOperator = "0123456789+-*/^SCTG!";//�������ֺ�������ţ�����֮�����
	int start, end;
	double Num, FirstNum, SecondNum;
	const double Pi = acos(-1.0);//����Բ������
	for (int i = 0; i < src.length();)
	{
		start = src.find_first_of(NumOrOperator, i);//�ҵ���һ�����������������
		end = src.find_first_of(" ", i);//�ҵ���һ���ո�
		if (end == -1)
		{
			end = src.length();
		}
		string tempstr = src.substr(start, end - start);//��ȡ���������������
		if (tempstr == "+" || tempstr == "-" || tempstr == "*" || tempstr == "/" || tempstr == "^")//����Ӽ��˳���
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
		else if (tempstr == "S" || tempstr == "C" || tempstr == "T")//�������Ǻ���
		{
			SecondNum = SecondNum * Pi / 180;//�ѽǶ�ת��Ϊ����
			if (tempstr == "S")
				Num = sin(SecondNum);
			if (tempstr == "C")
				Num = cos(SecondNum);
			if (tempstr == "T")
				Num = tan(SecondNum);
		}
		else if (tempstr == "G" )//�������������Ĭ����10Ϊ��
			Num = log10(SecondNum);
		else if (tempstr == "!")
			Num = tgamma(SecondNum + 1);
		else if(i == 0)
			SecondNum = stod(tempstr);
		else
			FirstNum = stod(tempstr);
		i = end + 1;//�����±��ƶ�
	}
	return Num;
}

void Calculator::judgeOperandAndCalculate(string& multientryOp, Stack<char>& opStack, string& tempExpression, Stack<double>& numStack)//�ж�������ǵ�Ŀ����˫Ŀ�ģ��Դ�ȡ����Ӧ�������������м���
{
	try
	{
		if (multientryOp.find(opStack.topValue()) != string::npos)
		{
			for (int i = 0; i < 2; i++)
			{
				if (numStack.getLength() == 0)//��������������ˣ�֤�����ʽ������
				{
					cout << "���ʽ����ȷ��" << endl;
					throw* (new exception("exception"));
					return;
				}
				tempExpression = tempExpression + to_string(numStack.topValue()) + " ";
				numStack.pop();
			}
			tempExpression = tempExpression + opStack.topValue();
			opStack.pop();
			numStack.push(calculateShortInfix(tempExpression));//��С���ʽ�������㺯����������
			tempExpression = "";
		}
		else
		{
			if (numStack.getLength() == 0)
			{
				cout << "���ʽ����ȷ��" << endl;
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

bool Calculator::isExpressionValid(string src)//���жϱ��ʽ��û���׿����Ĵ���
{
	simplifyExpression(src);
	string validChar = "0123456789.+/*-SCTG()!^";
	string multientryOp = "+-*/^";

	for(auto ch : src)
	{
		if (validChar.find(ch) == string::npos) 
		{
			cout << "���ʽ���зǷ��ַ�" << endl;
			return false;
		}
	}
	if (multientryOp.find(src[src.length() - 1]) != string::npos)
	{
		cout << "ȱ���Ҳ�����" << endl;
		return false;
	}

	return true;
}

void Calculator::simplifyExpression(string& src)
{
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
	while (src.find("lg") != string::npos)//Ԥ�������룬�ѳ��ö���תΪ�״���ĵ�������
	{
		src.replace(src.find("lg"), 2, "G");
	}
}

int Calculator::calByPostfix(string src)//�����������ĺ���
{
	if (isExpressionValid(src))
	{
		src = toPostfixExpression(src);
		cout << "��׺���ʽΪ��" << src << endl;
		try
		{
			cout << "��׺���ʽ������Ϊ��" << CalculatePostfix(src) << endl;
			return 0;
		}
		catch (const std::exception& e)
		{
			string info = e.what();
			if (info == "invalid stod argument")
			{
				cout << "���ʽ����ȷ��" << endl;
			}
			else if (info == "invalid string position")
			{
				cout << "���Ų�ƥ�䣡" << endl;
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
			cout << "��׺���ʽ������Ϊ��" << calculateInfix(src) << endl;
			return 0;
		}
		catch (const std::exception& e)
		{
			string info = e.what();
			if (info == "invalid stod argument")
			{
				cout << "���ʽ����ȷ��" << endl;
			}
			else if (info == "invalid string position")
			{
				cout << "���Ų�ƥ�䣡" << endl;
			}

			return -1;
		}

	}
}
