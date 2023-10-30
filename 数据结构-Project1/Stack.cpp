#include "Stack.h"

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
	StackElement<E>* temp = top->front;
	delete top;
	top = temp;
	length--;
	return this;
}
