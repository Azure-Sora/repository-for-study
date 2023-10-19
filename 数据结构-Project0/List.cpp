#include "List.h"
#include <iostream>
#include <fstream>

using std::cout;
using std::endl;
using std::string;

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
void List<E>::print()
{
	if (length == 0)
	{
		std::cerr << "����Ϊ��!" << endl;
		return;
	}
	ListNode<E>* temp = current;//��¼��ǰ����λ�ã����㻹ԭ
	current = head->next;
	while (current != nullptr)
	{
		cout << current->value << endl;
		current = current->next;
	}
	current = temp;
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
int List<E>::search(const E& target)
{
	ListNode<E>* temp = current;//��ͷ��������
	int position = 0;
	current = head;
	while (current->value != target)
	{
		if (current == tail)//����ѵ�β����˻���û�ҵ�������-1
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

template<class E>
void List<E>::sort()//ʹ��ѡ������
{
	if (length < 2) return;//�յĻ���ֻ��һ����㲻������
	ListNode<E>* temp = current;
	int nowPos = 1;//�ӵ�һ��λ�ÿ�ʼ����ѡ�����Ĳ��ƶ�λ��
	while (nowPos <= length)
	{
		int biggestPos = nowPos;
		for (int i = nowPos; i <= length; i++)//ѡ������
		{
			if (moveToPos(i)->getValue() > moveToPos(biggestPos)->getValue())
			{
				biggestPos = i;
			}
		}
		if (biggestPos != nowPos)
		{
			E val = moveToPos(biggestPos)->getValue();//�ݴ����ֵ
			remove();
			moveToPos(nowPos - 1);
			insert(val);//����д�õĺ�����ʵ���ƶ�λ��
		}
		nowPos++;
	}
}

template<class E>
void List<E>::loadFormFile(std::string fileName)
{
	std::ifstream file;
	file.open(fileName);
	while (!file.eof())//һ��һ�ж�ȡ���ݣ��Ի���Ϊ�ָ�
	{
		E val;
		file >> val;
		if (file.fail())
		{
			std::cerr << "��ȡ�쳣!" << endl;
			break;
		}
		append(val);//�Ѷ����string�Ž����������Զ�ת��ΪE����
	}
	file.close();
}







