#include "Heap.h"
#include<utility>

Heap* Heap::add(HuffmanTree* newTree)//往堆里加一棵树，堆不够大就扩大，加入后即进行一次排序
{
	if (length >= volume) expand();
	heap[length] = newTree;
	length++;
	sortHeap();
	return this;
}

void Heap::init(std::pair<HuffmanTree**, int> initData)//使用森林和森林中树的数量初始化一个堆
{
	delete heap;
	heap = initData.first;
	length = initData.second;
	volume = initData.second;
	sortHeap();
}


void Heap::expand()//把堆容量扩大10
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

void Heap::remove(int pos)//删除pos下标的树，并把后面的前移
{
	HuffmanTree* temp = heap[pos];
	delete temp;
	for (int i = pos; i < length - 1; i++)
	{
		heap[i] = heap[i + 1];
	}
	length--;
}

char Heap::getFirstValuedNode(Node* node)//用于辅助排序
{
	if (node->isLeaf) return node->value;
	return getFirstValuedNode(node->left);
}

void Heap::sortHeap()//选择排序，如果两树权重相同，找到树最左下角结点里的字符再进行比较，这样保证每次排序都有相同的结果
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