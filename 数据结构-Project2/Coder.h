#pragma once
#include<iostream>
#include<utility>
class HuffmanTree;
class Node;
class Code;

class Coder
{
public:
	std::string readUncodedFile(std::string file);
	void encodeFile(std::string file);
	std::pair<HuffmanTree**, int> createNodes(std::string text);
	Code** createHuffmanCode(HuffmanTree* root);
	void getCode(Node* node, Code** codes, int& count);
	std::string encodeToBinaryString(std::string text, Code** codes);
		
};

