#pragma once
#include "StackElement.h"
template<class E> class Stack
{
public:
	Stack()//≥ı ºªØ’ª
	{
		top = new StackElement<E>;
		length = 0;
	}

	void clear();
	int getLength();
	bool empty();
	E& topValue();
	Stack<E>* push(const E& value);
	Stack<E>* pop();

	~Stack()
	{
		clear();
	};

private:
	StackElement<E>* top;
	int length;

};

