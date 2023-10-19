#include "List.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

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
void List<E>::print()
{
	if (length == 0)
	{
		std::cerr << "链表为空!" << endl;
		return;
	}
	ListNode<E>* temp = current;//记录当前操作位置，方便还原
	current = head->next;
	while (current != nullptr)
	{
		cout << current->value << endl;
		current = current->next;
	}
	current = temp;
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
int List<E>::search(const E& target)
{
	ListNode<E>* temp = current;//从头往后搜索
	int position = 0;
	current = head;
	while (current->value != target)
	{
		if (current == tail)//如果搜到尾结点了还是没找到，返回-1
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

template<class E>
void List<E>::sort()//使用选择排序
{
	if (length < 2) return;//空的或者只有一个结点不用排序
	ListNode<E>* temp = current;
	int nowPos = 1;//从第一个位置开始依次选择最大的并移动位置
	while (nowPos <= length)
	{
		int biggestPos = nowPos;
		for (int i = nowPos; i <= length; i++)//选择排序
		{
			if (moveToPos(i)->getValue() > moveToPos(biggestPos)->getValue())
			{
				biggestPos = i;
			}
		}
		if (biggestPos != nowPos)
		{
			E val = moveToPos(biggestPos)->getValue();//暂存最大值
			remove();
			moveToPos(nowPos - 1);
			insert(val);//调用写好的函数来实现移动位置
		}
		nowPos++;
	}
}

template<class E>
void List<E>::loadFormFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	while (!file.eof())//一行一行读取内容，以换行为分隔
	{
		E val;
		file >> val;
		if (file.fail())
		{
			std::cerr << "读取异常!" << endl;
			break;
		}
		append(val);//把读入的string放进输入流，自动转换为E类型
	}
	file.close();
}







