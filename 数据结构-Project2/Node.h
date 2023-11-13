#pragma once
#include<iostream>
class Node
{
public:
	int priority;
	bool isLeaf;
	std::string value;
	Node* left;
	Node* right;

	Node(int priority, std::string value) :priority(priority), isLeaf(true), value(value), left(nullptr), right(nullptr) {};
	Node(int priority, Node* left, Node* right) :priority(priority), isLeaf(false), value(""), left(left), right(right) {};

	~Node()
	{

	};
};

