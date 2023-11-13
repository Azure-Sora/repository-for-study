#pragma once
#include"HuffmanTree.h"
class HuffmanTree;

class Heap
{
public:
	HuffmanTree** heap = nullptr;
	int length = 0;
	int volume = 0;

	Heap()
	{
		expand();
	}

	Heap* add(HuffmanTree* newTree);
	void sortHeap();
	void expand();
	void remove(int pos);
};

