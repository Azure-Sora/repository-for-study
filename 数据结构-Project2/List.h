#pragma once
#include"ListNode.h"
#include <iostream>
#include <fstream>
using namespace std;

template <class E> class List
{
public:

	List()//ʹ�ù��캯�����г�ʼ��
	{
		head = new ListNode<E>;//ͷ���
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
void List<E>::destroyMe()//��ͷ��㿪ʼ�������ٽ��
{
	while (head != nullptr)
	{
		current = head;
		head = head->next;
		delete current;
	}
}

template<class E>
void List<E>::removeAll()//���֮���ٴγ�ʼ��
{
	destroyMe();
	head = new ListNode<E>;
	tail = head;
	current = head;
	length = 0;
}

template<class E>
List<E>* List<E>::moveToStart()//��������ָ�룬֧����ʽ���
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
	//������bug��current == nullptr��ʱ�������⣬���Ҳ����취����һ�������ã�
	//����������ķ��������������һ��֮��һ�ѱ���
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
		ListNode<E>* newNode = new ListNode<E>(value, current->next);//�ڲ���λ�ú󷽲����½��
		current->next = newNode;
		if (current == tail) tail = newNode;//����β���
		length++;
	}
	catch (...)
	{
		std::cerr << "����ʧ��" << endl;
	}
	
	return this;
}

template<class E>
List<E>* List<E>::append(const E& value)//��β��׷���½��
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
		std::cerr << "׷��ʧ��" << endl;
	}
	
	return this;
}

template<class E>
List<E>* List<E>::remove()
{
	try
	{
		perv();//�ƶ���ǰһλ��
		if (current->next == tail) tail = current;//����β���
		ListNode<E>* newNext = current->next->next;//��ǰ׼������ɾ��λ�õ�ǰ��
		delete current->next;
		current->next = newNext;
		current = current->next;//�ص�ԭ����λ��
		length--;
	}
	catch (...)
	{
		std::cerr << "ɾ��ʧ��" << endl;
	}
	
	return this;
}

template<class E>
List<E>* List<E>::perv()
{
	if (current == head) return this;
	ListNode<E>* perv = head;//��ͷ�����ң�ֱ���ҵ�ǰһ�����
	while (perv->next != current)
	{
		perv = perv->next;
	}
	current = perv;
	return this;
}

template<class E>
int List<E>::currentPos()//��ͷ��������ֱ���������ڵĽ��
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
List<E>* List<E>::moveToPos(int pos)//һ��һ��������
{
	if (pos > length)
	{
		std::cerr << "Խ��" << endl;
		return this;
	}
	current = head;
	for (int i = pos; i > 0; i--)
	{
		current = current->next;
	}
	return this;
}

