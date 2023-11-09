#pragma once
#include"Stack.h"
#include<iostream>
using std::string;

class Calculator
{
public:
	Calculator() {};
	int calByPostfix(string src);
	int calByInfix(string src);

private:
	string toPostfixExpression(string src);
	double CalculatePostfix(string str);
	int getOperatorPriority(char op);
	double calculateInfix(string src);
	double calculateShortInfix(string src);
	void judgeOperandAndCalculate(string& multientryOp, Stack<char>& opStack, string& tempExpression, Stack<double>& numStack);
	bool isExpressionValid(string src);
	void simplifyExpression(string& src);
};
