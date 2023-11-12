#pragma once
#include "StackElement.h"
template<class E> class Stack
{
public:
	Stack()//��ʼ��ջ
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

	StackElement<E>* top;
	int length;

private:
	
};

template<class E>
void Stack<E>::clear()
{
	while (top->front != nullptr)
	{
		StackElement<E>* temp = top;
		top = top->front;
		delete temp;
	}
	length = 0;
}

template<class E>
int Stack<E>::getLength()
{
	return length;
}

template<class E>
bool Stack<E>::empty()
{
	return length > 0 ? false : true;
}

template<class E>
E& Stack<E>::topValue()
{
	return top->value;
}

template<class E>
Stack<E>* Stack<E>::push(const E& value)
{
	StackElement<E>* newEle = new StackElement<E>(value);
	newEle->front = top;
	top = newEle;
	length++;
	return this;
}

template<class E>
Stack<E>* Stack<E>::pop()
{
	StackElement<E>* temp = (top->front == nullptr ? nullptr : top->front);
	delete top;
	top = temp;
	length--;
	return this;
}


