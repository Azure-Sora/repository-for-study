#pragma once
#include"ListNode.h"
#include <iostream>
#include <fstream>
using namespace std;

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
	List<E>* moveToPos(int pos);

	~List()
	{
		destroyMe();
	};

	ListNode<E>* head;
	ListNode<E>* tail;
	ListNode<E>* current;
	int length;

};

template<class E>
void List<E>::destroyMe()//从头结点开始依次销毁结点
{
	while (head != nullptr)
	{
		current = head;
		head = head->next;
		delete current;
	}
}

template<class E>
void List<E>::removeAll()//清空之后再次初始化
{
	destroyMe();
	head = new ListNode<E>;
	tail = head;
	current = head;
	length = 0;
}

template<class E>
List<E>* List<E>::moveToStart()//返回自身指针，支持链式编程
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
	current = current->next;
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
	//这里有bug，current == nullptr的时候会出问题，但找不到办法返回一个空引用，
	//尝试用下面的方法解决，但改了一下之后一堆报错
}

//template<class E>
//std::optional<std::reference_wrapper<E>> List<E>::getValue()
//{
//	if (current != nullptr) return { current->value };
//	else std::nullopt;
//}



template<class E>
List<E>* List<E>::insert(const E& value)
{
	try
	{
		ListNode<E>* newNode = new ListNode<E>(value, current->next);//在操作位置后方插入新结点
		current->next = newNode;
		if (current == tail) tail = newNode;//更新尾结点
		length++;
	}
	catch (...)
	{
		std::cerr << "插入失败" << endl;
	}
	
	return this;
}

template<class E>
List<E>* List<E>::append(const E& value)//在尾部追加新结点
{
	try
	{
		ListNode<E>* newNode = new ListNode<E>(value);
		tail->next = newNode;
		tail = newNode;
		length++;
	}
	catch (...)
	{
		std::cerr << "追加失败" << endl;
	}
	
	return this;
}

template<class E>
List<E>* List<E>::remove()
{
	try
	{
		perv();//移动到前一位置
		if (current->next == tail) tail = current;//更新尾结点
		ListNode<E>* newNext = current->next->next;//提前准备连接删除位置的前后
		delete current->next;
		current->next = newNext;
		current = current->next;//回到原操作位置
		length--;
	}
	catch (...)
	{
		std::cerr << "删除失败" << endl;
	}
	
	return this;
}

template<class E>
List<E>* List<E>::perv()
{
	if (current == head) return this;
	ListNode<E>* perv = head;//从头往后找，直到找到前一个结点
	while (perv->next != current)
	{
		perv = perv->next;
	}
	current = perv;
	return this;
}

template<class E>
int List<E>::currentPos()//从头往后数，直到数到现在的结点
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
List<E>* List<E>::moveToPos(int pos)//一个一个往后数
{
	if (pos > length)
	{
		std::cerr << "越界" << endl;
		return this;
	}
	current = head;
	for (int i = pos; i > 0; i--)
	{
		current = current->next;
	}
	return this;
}

