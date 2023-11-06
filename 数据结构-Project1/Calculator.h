#pragma once
#include"Stack.h"
#include<iostream>
using std::string;

class Calculator
{
public:
	Calculator() {};
	friend void operator>>(std::istream& in, Calculator& cacu);
	string toPostfixExpression(string src);
	double CalculatePostfix(string str);
	int getOperatorPriority(char op);
	double calculateInfix(string src);
	double calculateShortInfix(string src);
	void judgeOperandAndCalculate(string& multientryOp, Stack<char>& opStack, string& tempExpression, Stack<double>& numStack);

private:
	
};
