#include "Heap.h"

Heap* Heap::add(HuffmanTree* newTree)
{
	if (length == volume) expand();
	heap[length] = newTree;
	length++;
	sortHeap();
	return this;
}

void Heap::expand()
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

void Heap::remove(int pos)
{
	HuffmanTree* temp = heap[pos];
	delete temp;
	for (int i = pos; i < length - 1; i++)
	{
		heap[i] = heap[i + 1];
	}
	length--;
}

void Heap::sortHeap()
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
		}
		if (i != smallest)
		{
			HuffmanTree* temp = heap[i];
			heap[i] = heap[smallest];
			heap[smallest] = temp;
		}
	}
}