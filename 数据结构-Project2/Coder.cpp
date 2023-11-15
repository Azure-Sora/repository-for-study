#include "Coder.h"
#include"Node.h"
#include"Code.h"
#include"HuffmanTree.h"
#include<fstream>
#include<sstream>
using namespace std;

std::string Coder::readUncodedFile(std::string fileDic)
{
    string out;
    ifstream file;
    file.open(fileDic, ios::in);
    if (!file.is_open())
    {
        cout << "文件打开失败" << endl;
        return out;
    }

    string temp;
    getline(file, temp);
    out += temp;
    while (getline(file, temp))
    {
        out = out + '\n' + temp;
    }
    file.close();
    return out;
}

void Coder::encodeFile(std::string file)
{
    string text = this->readUncodedFile(file);
    Heap heap;
    heap.init(this->createNodes(text));
    HuffmanTree* tree = new HuffmanTree();
    tree->buildTree(heap);
    Code** codes = this->createHuffmanCode(tree);
    cout << encodeToBinaryString(text, codes);
}

std::pair<HuffmanTree**, int> Coder::createNodes(std::string text)
{
    Node** nodes;
    int nodesVolume = 0;
    int nodesCount = 0;
    
    auto expandNodes = [&]() {
        nodesVolume += 10;
        Node** oldnodes = nodes;
        nodes = new Node * [nodesVolume];
        for (int i = 0; i < nodesCount; i++)
        {
            nodes[i] = oldnodes[i];
        }
        //delete oldnodes;
    };

    expandNodes();
    bool exist;
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];
        exist = false;
        for (int j = 0; j < nodesCount; j++)
        {
            if (nodes[j]->value == ch)
            {
                nodes[j]->priority++;
                exist = true;
                break;
            }
        }
        if (!exist)
        {
            if (nodesCount + 1 >= nodesVolume) expandNodes();
            nodes[nodesCount] = new Node(1, ch);
            nodesCount++;
        }
    }

    HuffmanTree** forest = new HuffmanTree * [nodesCount];
    for (int i = 0; i < nodesCount; i++)
    {
        forest[i] = new HuffmanTree(nodes[i]);
    }

    return pair<HuffmanTree**, int>(forest, nodesCount);
}

Code** Coder::createHuffmanCode(HuffmanTree* root)
{
    Code** codes = new Code * [root->countOfLeaves];
    int count = 0;
    getCode(root->root, codes, count);
    return codes;
}

void Coder::getCode(Node* node, Code** codes, int& count)
{
    if (node->left != nullptr)
    {
        node->left->code = node->code + "0";
        if (node->left->isLeaf == false)
        {
            getCode(node->left, codes, count);
        }
        else
        {
            codes[count] = new Code(node->left->value, node->left->code);
            count++;
        }
    }
    if (node->right != nullptr)
    {
        node->right->code = node->code + "1";
        if (node->right->isLeaf == false)
        {
            getCode(node->right, codes, count);
        }
        else
        {
            codes[count] = new Code(node->right->value, node->right->code);
            count++;
        }
    }
}

std::string Coder::encodeToBinaryString(std::string text, Code** codes)
{
    string bs = "";
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];
        for (int j = 0; codes[j] != nullptr; j++)
        {
            if (codes[j]->value == ch)
            {
                bs += codes[j]->code;
                break;
            }
        }
    }

    return bs;
}
