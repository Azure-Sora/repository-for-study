#pragma once
#include<iostream>
class Code
{
public: 
	char value;
	std::string code;
	int arrLength;
	Code() {};
	Code(char value, std::string code) :value(value), code(code) {};
};

