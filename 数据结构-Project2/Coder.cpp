#include "Coder.h"
#include"Node.h"
#include"Code.h"
#include"HuffmanTree.h"
#include<fstream>
#include<sstream>
#include<mutex>
#include<windows.h>
using namespace std;

mutex mtx;

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
    Node** nodeArr;
    heap.init(this->createNodes(text, nodeArr));

    HuffmanTree* tree = new HuffmanTree();
    tree->buildTree(heap);
    this->createHuffmanCode(tree);

    string a = encodeToBinaryString(text, nodeArr);
    cout << a << endl << endl;
    cout << decodeBinaryString(a, nodeArr);
    //delete[] codes;
}

std::pair<HuffmanTree**, int> Coder::createNodes(std::string text, Node**& nodeArr)
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
        for (int j = nodesCount; j < nodesVolume; j++)
        {
            nodes[j] = nullptr;
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

    nodeArr = nodes;
    return pair<HuffmanTree**, int>(forest, nodesCount);
}

void Coder::createHuffmanCode(HuffmanTree* root)
{
    
    getCode(root->root);
    
}

void Coder::getCode(Node* node)
{
    //string out = "";
    if (node->left != nullptr)
    {
        node->left->code = node->code + "0";
        if (node->left->isLeaf == false)
        {
            getCode(node->left);
        }
    }
    if (node->right != nullptr)
    {
        node->right->code = node->code + "1";
        if (node->right->isLeaf == false)
        {
            getCode(node->right);
        }
    }
}

std::string Coder::encodeToBinaryString(std::string text, Node** nodes)
{
    string bs = "";
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];
        //j < codes[0]->arrLength
        for (int j = 0; nodes[j] != nullptr; j++)
        {
            if (nodes[j]->value == ch)
            {
                bs += nodes[j]->code;
                break;
            }
        }
    }

    return bs;
}

std::string Coder::decodeBinaryString(std::string bs, Node** nodes)
{
    string out = "";
    for (int i = 0; i < bs.length();)
    {
        bool find = false;
        int len = 1;
        while (!find)
        {
            string temps = "";
            for (int j = 0; j < len; j++)
            {
                temps += bs[i + j];
            }
            //k < codes[0]->arrLength
            for (int k = 0; nodes[k] != nullptr; k++)
            {
                if (nodes[k]->code == temps)
                {
                    out += nodes[k]->value;
                    find = true;
                    break;
                }
            }
            
            if(!find) len++;
        }
        find = false;
        i += len;
        len = 1;
    }

    return out;
}
