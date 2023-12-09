#pragma once
#include<iostream>
#include<utility>
class HuffmanTree;
class Node;

class Coder
{
public:
	std::string readUncodedFile(std::string file);
	void encodeFile(std::string file);
	std::pair<HuffmanTree**, int> createNodes(std::string& text, Node**& nodeArr);
	void createHuffmanCode(HuffmanTree* root);
	void getCode(Node* node);
	std::string encodeToBinaryString(std::string& text, Node** nodes);
	std::string decodeBinaryString(std::string& bs, Node** nodes);
	void saveCodedFile(std::string& bs, Node** nodes, std::string fileName);
	void decodeFile(std::string filePath);
	void showProgress(const int& done, const int& total, const int offset, const int proportion);
		
};

