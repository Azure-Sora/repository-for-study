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
	


	void test();

private:
	
};
