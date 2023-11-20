#include "HuffmanTree.h"

int HuffmanTree::weight()
{
	return root->priority;
}

void HuffmanTree::buildTree(Heap& heap)//在堆中构建哈夫曼树，一直合并前两课树直到只剩一棵树
{
	while (heap.length > 1)
	{
		HuffmanTree* newTree = new HuffmanTree(heap.heap[0], heap.heap[1]);
		heap.remove(1);
		heap.remove(0);
		heap.add(newTree);//每次添加新合成的树后都会自动排序
	}
	this->root = heap.heap[0]->root;
}
