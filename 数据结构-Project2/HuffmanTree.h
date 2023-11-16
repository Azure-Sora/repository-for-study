#pragma once
#include"Node.h"
#include"Heap.h"
class Heap;

class HuffmanTree
{
public:
	Node* root;
	int countOfLeaves = 0;

	HuffmanTree(Node* leaf = nullptr)
	{
		this->root = leaf;
	}
	HuffmanTree(HuffmanTree* tree1, HuffmanTree* tree2)
	{
		Node* newRoot = new Node(tree1->weight() + tree2->weight(), tree1->root, tree2->root);
		this->root = newRoot;
	}

	int weight();
	void buildTree(Heap& heap);

};

