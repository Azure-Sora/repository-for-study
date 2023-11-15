#pragma once
#include<iostream>
class Code
{
public: 
	char value;
	std::string code;
	Code() {};
	Code(char value, std::string code) :value(value), code(code) {};
};

