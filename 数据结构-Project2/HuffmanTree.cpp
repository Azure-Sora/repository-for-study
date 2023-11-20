#include "HuffmanTree.h"

int HuffmanTree::weight()
{
	return root->priority;
}

void HuffmanTree::buildTree(Heap& heap)//�ڶ��й�������������һֱ�ϲ�ǰ������ֱ��ֻʣһ����
{
	while (heap.length > 1)
	{
		HuffmanTree* newTree = new HuffmanTree(heap.heap[0], heap.heap[1]);
		heap.remove(1);
		heap.remove(0);
		heap.add(newTree);//ÿ������ºϳɵ����󶼻��Զ�����
	}
	this->root = heap.heap[0]->root;
}
