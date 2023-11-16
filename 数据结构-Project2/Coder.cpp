#include "Coder.h"
#include"Node.h"
#include"HuffmanTree.h"
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

std::string Coder::readUncodedFile(std::string fileDic)
{
    string out = "";
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
    if (text == "") return;

    cout << "正在编码" << file << "，请稍候……" << endl;
    Heap heap;
    Node** nodeArr;
    heap.init(this->createNodes(text, nodeArr));

    HuffmanTree* tree = new HuffmanTree();
    tree->buildTree(heap);
    this->createHuffmanCode(tree);

    string bs = encodeToBinaryString(text, nodeArr);

    saveCodedFile(bs, nodeArr, file);
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

void Coder::saveCodedFile(std::string bs, Node** nodes, std::string fileName)
{
    struct Code
    {
        char value;
        int priority;
    };

    ofstream file;
    file.open(fileName + ".huf", ios::out | ios::binary | ios::app);


    int nodeCount = 0;
    for (int i = 0; nodes[i] != nullptr; i++)
    {
        nodeCount++;
    }

    file.write((char*)(&nodeCount), sizeof(int));
    
    for (int i = 0; i < nodeCount; i++)
    {
        Code cd;
        cd.value = nodes[i]->value;
        cd.priority = nodes[i]->priority;
        file.write((char*)(&cd), sizeof(Code));
    }

    int bsLen = bs.length() / 8 + 1;
    int lastCh = bs.length() % 8;
    file.write((char*)(&lastCh), sizeof(int));

    unsigned char* outBS = new unsigned char[bsLen];

    for (int i = 0, count = 0; i < bsLen * 8;)
    {
        if (i + 8 < bs.length())
        {
            unsigned char sbs = 0;
            for (int j = 0; j < 8; j++)
            {
                if (bs[i + j] == '1') sbs += pow(2, 7 - j);
            }
            outBS[count] = sbs;
            count++;
            i += 8;
        }
        else
        {
            unsigned char sbs = 0;
            for (int j = 0; j < lastCh; j++)
            {
                if (bs[i + j] == '1') sbs += pow(2, 7 - j);
            }
            outBS[count] = sbs;
            count++;
            i += 8;
        }
    }

    file.write((char*)outBS, bsLen * sizeof(unsigned char));

    int codedSize = file.tellp() / 1024;

    file.close();

    ifstream srcFile;
    srcFile.open(fileName, ios::in);
    srcFile.seekg(0, ios::end);
    int uncodedSize = srcFile.tellg() / 1024;
    srcFile.close();

    cout << "文件成功编码为" << fileName + ".huf" << endl;
    cout << "源文件大小" << uncodedSize << "KB，编码文件大小：" << codedSize << "KB，压缩率：" << ((double)codedSize / (double)uncodedSize) * 100 << "%" << endl;
}

void Coder::decodeFile(std::string fileDic)
{
    struct Code
    {
        char value;
        int priority;
    };
    int codeCount = 0;
    ifstream file;
    file.open(fileDic, ios::in | ios::binary);
    if (!file.is_open())
    {
        cout << "文件打开失败" << endl;
        return;
    }

    cout << "正在解码" << fileDic << "，请稍候……" << endl;

    file.read((char*)(&codeCount), sizeof(int));

    Node** nodes = new Node * [codeCount + 1];
    for (int i = 0; i < codeCount + 1; i++)
    {
        nodes[i] = nullptr;
    }
    for (int i = 0; i < codeCount; i++)
    {
        Code cd;
        file.read((char*)(&cd), sizeof(Code));
        nodes[i] = new Node(cd.priority, cd.value);
    }

    Heap heap;
    for (int i = 0; i < codeCount; i++)
    {
        heap.add(new HuffmanTree(nodes[i]));
    }

    HuffmanTree* tree = new HuffmanTree();
    tree->buildTree(heap);
    this->createHuffmanCode(tree);

    int lastCh = 0;
    file.read((char*)(&lastCh), sizeof(int));

    string bs = "";
    unsigned char uc = 0;

    while (file.read((char*)(&uc), sizeof(unsigned char)))
    {
        string shortS = "";
        for (int i = 0; i < 8; i++)
        {
            if (uc % 2 == 1)
            {
                shortS += "1";
            }
            else
            {
                shortS += "0";
            }
            uc /= 2;
        }
        bs = bs + string(shortS.rbegin(), shortS.rend());
    }

    bs = bs.substr(0, bs.length() - 8 + lastCh);

    file.close();

    string text = decodeBinaryString(bs, nodes);

    string newFile = fileDic.substr(0, fileDic.length() - 4);
    ofstream ofile;
    ofile.open(newFile, ios::out | ios::app);
    ofile.write(text.c_str(), text.size());
    ofile.close();
    cout << "文件" << fileDic << "解码成功" << endl;
}
