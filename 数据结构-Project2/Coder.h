#pragma once
#include<iostream>
#include<utility>
#include"Code.h"
class HuffmanTree;
class Node;
class Code;

class Coder
{
public:
	std::string readUncodedFile(std::string file);
	void encodeFile(std::string file);
	std::pair<HuffmanTree**, int> createNodes(std::string text, Node**& nodeArr);
	void createHuffmanCode(HuffmanTree* root);
	void getCode(Node* node);
	std::string encodeToBinaryString(std::string text, Node** nodes);
	std::string decodeBinaryString(std::string bs, Node** nodes);
		
};

