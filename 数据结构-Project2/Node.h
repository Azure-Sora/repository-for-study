#pragma once
#include<iostream>
class Node
{
public:
	int priority;
	bool isLeaf;
	char value;
	Node* left;
	Node* right;
	std::string code;

	Node(int priority, char value) :priority(priority), isLeaf(true), value(value), left(nullptr), right(nullptr), code("") {};
	Node(int priority, Node* left, Node* right) :priority(priority), isLeaf(false), value('\0'), left(left), right(right), code("") {};

	~Node()
	{

	};
};

