#pragma once
template<class E> class StackElement
{
public:
	E value;
	StackElement* front;
	StackElement(E val, StackElement* front = nullptr) :value(val), front(front) {};
	StackElement(StackElement* front = nullptr) :front(front) {};
private:
};

