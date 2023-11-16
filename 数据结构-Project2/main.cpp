#include<iostream>
#include"Heap.h"
#include"Coder.h"
using namespace std;
class Coder;
int main()
{
	Coder cd;
	/*string a = cd.readUncodedFile("ASC.txt");
	Heap heap;
	heap.init(cd.createNodes(a));
	HuffmanTree* tree = new HuffmanTree();
	tree->buildTree(heap);
	Code** codes = cd.createHuffmanCode(tree);*/
	cd.encodeFile("novel.txt");

	cd.decodeFile("novel.txt.huf");

	system("PAUSE");

	/*Node* node1 = new Node(10, "a");
	Node* node2 = new Node(20, "b");
	Node* node3 = new Node(15, "c");
	Node* node4 = new Node(30, "d");
	Node* node5 = new Node(40, "e");
	Node* node6 = new Node(50, "f");
	Node* node7 = new Node(6, "g");

	Heap heap;
	heap.add(new HuffmanTree(node1))->add(new HuffmanTree(node2))->add(new HuffmanTree(node3))->add(new HuffmanTree(node4))->add(new HuffmanTree(node5))->add(new HuffmanTree(node6))->add(new HuffmanTree(node7));
	HuffmanTree* tree = new HuffmanTree();
	tree->buildTree(heap);

	cout << "a";
	cout << "a";*/

	
	return 0;
}