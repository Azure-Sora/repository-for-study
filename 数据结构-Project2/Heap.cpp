#include "Heap.h"
#include<utility>

Heap* Heap::add(HuffmanTree* newTree)//�������һ�������Ѳ���������󣬼���󼴽���һ������
{
	if (length >= volume) expand();
	heap[length] = newTree;
	length++;
	sortHeap();
	return this;
}

void Heap::init(std::pair<HuffmanTree**, int> initData)//ʹ��ɭ�ֺ�ɭ��������������ʼ��һ����
{
	delete heap;
	heap = initData.first;
	length = initData.second;
	volume = initData.second;
	sortHeap();
}


void Heap::expand()//�Ѷ���������10
{
	volume += 10;
	HuffmanTree** oldHeap = heap;
	heap = new HuffmanTree * [volume];
	for (int i = 0; i < length; i++)
	{
		heap[i] = oldHeap[i];
	}
	delete oldHeap;
	
}

void Heap::remove(int pos)//ɾ��pos�±���������Ѻ����ǰ��
{
	HuffmanTree* temp = heap[pos];
	delete temp;
	for (int i = pos; i < length - 1; i++)
	{
		heap[i] = heap[i + 1];
	}
	length--;
}

char Heap::getFirstValuedNode(Node* node)//���ڸ�������
{
	if (node->isLeaf) return node->value;
	return getFirstValuedNode(node->left);
}

void Heap::sortHeap()//ѡ�������������Ȩ����ͬ���ҵ��������½ǽ������ַ��ٽ��бȽϣ�������֤ÿ����������ͬ�Ľ��
{

	for (int i = 0; i < length; i++)
	{
		int smallest = i;
		for (int j = i; j < length; j++)
		{
			if (heap[j]->weight() < heap[smallest]->weight())
			{
				smallest = j;
			}
			if (heap[j]->weight() == heap[smallest]->weight())
			{
				if (getFirstValuedNode(heap[j]->root) < getFirstValuedNode(heap[smallest]->root))
				{
					smallest = j;
				}
			}
		}
		if (i != smallest)
		{
			HuffmanTree* temp = heap[i];
			heap[i] = heap[smallest];
			heap[smallest] = temp;
		}
	}
}