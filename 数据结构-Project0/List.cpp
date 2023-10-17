#include "List.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

template<class E>
void List<E>::destroyMe()
{
	while (head != nullptr)
	{
		current = head;
		head = head->next;
		delete current;
	}
}

template<class E>
void List<E>::removeAll()
{
	destroyMe();
	head = new ListNode<E>;
	tail = head;
	current = head;
	length = 0;
}

template<class E>
void List<E>::print()
{
	ListNode<E>* temp = current;
	current = head->next;
	while (current != nullptr)
	{
		cout << current->value << endl;
		current = current->next;
	}
	current = temp;
}

template<class E>
List<E>* List<E>::moveToStart()
{
	current = head;
	return this;
}

template<class E>
List<E>* List<E>::moveToEnd()
{
	current = tail;
	return this;
}

template<class E>
List<E>* List<E>::next()
{
	if(current->next != nullptr) current = current->next;
	return this;
}

template<class E>
int List<E>::getLength()
{
	return length;
}

template<class E>
E& List<E>::getValue()
{
	if (current != nullptr) return current->value;
}

template<class E>
List<E>* List<E>::insert(const E& value)
{
	ListNode<E>* newNode = new ListNode<E>(value, current->next);
	current->next = newNode;
	if (current == tail) tail = newNode;
	length++;
	return this;
}

template<class E>
List<E>* List<E>::append(const E& value)
{
	ListNode<E>* newNode = new ListNode<E>(value);
	tail->next = newNode;
	tail = newNode;
	length++;
	return this;
}

template<class E>
List<E>* List<E>::remove()
{
	perv();
	if (current->next == tail) tail = current;
	ListNode<E>* newNext = current->next->next;
	delete current->next;
	current->next = newNext;
	current = current->next;
	length--;
	return this;
}

template<class E>
List<E>* List<E>::perv()
{
	if (current == head) return this;
	ListNode<E>* perv = head;
	while (perv->next != current)
	{
		perv = perv->next;
	}
	current = perv;
	return this;
}

template<class E>
int List<E>::currentPos()
{
	int position = 0;
	ListNode<E>* pos = head;
	while (pos != current)
	{
		pos = pos->next;
		position++;
	}
	return position;
}

template<class E>
int List<E>::search(const E& target)
{
	ListNode<E>* temp = current;
	int position = 0;
	current = head;
	while (current->value != target)
	{
		if (current == tail)
		{
			current = temp;
			return -1;
		}
		current = current->next;
		position++;
	}
	current = temp;
	return position;
}

template<class E>
List<E>* List<E>::moveToPos(int pos)
{
	if (pos > length) return this;
	current = head;
	for (int i = pos; i > 0; i--)
	{
		current = current->next;
	}
	return this;
}

template<class E>
void List<E>::sort()
{
	if (length < 2) return;
	ListNode<E>* temp = current;
	int nowPos = 1;
	while (nowPos <= length)
	{
		int biggestPos = nowPos;
		for (int i = nowPos; i <= length; i++)
		{
			if (moveToPos(i)->getValue() > moveToPos(biggestPos)->getValue())
			{
				biggestPos = i;
			}
		}
		if (biggestPos != nowPos)
		{
			E val = moveToPos(biggestPos)->getValue();
			remove();
			moveToPos(nowPos - 1);
			insert(val);
		}
		nowPos++;
	}
}

template<class E>
void List<E>::loadFormFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	while (!file.eof())
	{
		E val;
		file >> val;
		append(val);
	}
	file.close();
}







