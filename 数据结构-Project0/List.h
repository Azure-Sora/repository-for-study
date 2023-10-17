#pragma once
#include"ListNode.h"
#include <iostream>

template <class E> class List
{
public:

	List()//使用构造函数进行初始化
	{
		head = new ListNode<E>;//头结点
		tail = head;
		current = head;
		length = 0;
	};

	void destroyMe();
	void removeAll();
	void print();
	List<E>* moveToStart();
	List<E>* moveToEnd();
	List<E>* next();
	int getLength();
	E& getValue();
	List<E>* insert(const E& value);
	List<E>* append(const E& value);
	List<E>* remove();
	List<E>* perv();
	int currentPos();
	int search(const E& target);
	List<E>* moveToPos(int pos);
	void sort();
	void loadFormFile(std::string fileName);

	~List()
	{
		destroyMe();
	};

private:
	ListNode<E>* head;
	ListNode<E>* tail;
	ListNode<E>* current;
	int length;

};

