#include "Coder.h"
#include"Node.h"
#include"HuffmanTree.h"
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

std::string Coder::readUncodedFile(std::string fileDic)//把源文件的所有内容读进一个string里
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
    getline(file, out);
    while (getline(file, temp))//读完一行手动添加一个换行符
    {
        out = out + '\n' + temp;
    }
    file.close();
    return out;
}

void Coder::encodeFile(std::string file)//用于编码文件的主函数
{
    string text = this->readUncodedFile(file);
    if (text == "") return;

    cout << "正在编码" << file << "，请稍候……" << endl;
    Heap heap;
    Node** nodeArr;
    heap.init(this->createNodes(text, nodeArr));//把文本的字符及其权重初始化到堆中

    HuffmanTree* tree = new HuffmanTree();
    tree->buildTree(heap);//建立哈夫曼树
    this->createHuffmanCode(tree);//建立哈夫曼编码

    string bs = encodeToBinaryString(text, nodeArr);//把文本转换为二进制串

    saveCodedFile(bs, nodeArr, file);//写入编码好的文件
}

/*
* 取出字符结点及权重值
* text 源文本
* nodeArr 用于把所有编码结点记录下来方便二进制化的时候用
* return 由一个一个结点自己作为树的森林和总结点数
*/
std::pair<HuffmanTree**, int> Coder::createNodes(std::string text, Node**& nodeArr)
{
    Node** nodes;
    int nodesVolume = 0;
    int nodesCount = 0;
    
    auto expandNodes = [&]() {//扩展容纳结点的数组的容量
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
    };

    expandNodes();
    bool exist;//记录一个字符是否已存在
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];
        exist = false;
        for (int j = 0; j < nodesCount; j++)//在已有的结点中寻找取到的字符，有就增加权重
        {
            if (nodes[j]->value == ch)
            {
                nodes[j]->priority++;
                exist = true;
                break;
            }
        }
        if (!exist)//没有就新增结点
        {
            if (nodesCount + 1 >= nodesVolume) expandNodes();
            nodes[nodesCount] = new Node(1, ch);
            nodesCount++;
        }
    }

    HuffmanTree** forest = new HuffmanTree * [nodesCount];//把结点化为森林
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

/*
* 使用递归的方式计算编码，根节点编码为空。每次调用让左节点的编码为自己+"0"，右节点为自己+"1"，再分别对不是叶子结点的左右孩子调用
*/
void Coder::getCode(Node* node)
{
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

/*
* 遍历源文本，把每一个字符转换为定好的哈夫曼码，再全部串在一起返回
*/
std::string Coder::encodeToBinaryString(std::string text, Node** nodes)
{
    string bs = "";
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];
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

/*
* 解码读入的二进制串，返回源文本
*/
std::string Coder::decodeBinaryString(std::string bs, Node** nodes)
{
    string out = "";
    for (int i = 0; i < bs.length();)//先假设编码只有一位，遍历寻找是否有对应的字符，没有则把编码长度加一位，再次寻找字符，直到找到字符，i+=本次编码长度
    {
        bool find = false;
        int len = 1;//假设的编码长度
        while (!find)
        {
            string temps = "";
            for (int j = 0; j < len; j++)//取出本次假设的编码
            {
                temps += bs[i + j];
            }
            for (int k = 0; nodes[k] != nullptr; k++)//寻找对应字符
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
        printf("\r已完成%.1lf%%  ", (double)i / (double)bs.length() * 34 + 66);
    }

    return out;
}

/*
* 把编码好的二进制串加上附加信息后保存在文件中
*/
void Coder::saveCodedFile(std::string bs, Node** nodes, std::string fileName)
{
    struct Code //用于记录字符及其权重的结构体
    {
        char value;
        int priority;
    };

    ofstream file;
    file.open(fileName + ".huf", ios::out | ios::binary | ios::app);//写入的新文件

    string fileIdentification = "HUF";//用于标记文件为该程序编码，在解码时验证
    file.write(fileIdentification.c_str(), 3 * sizeof(char));

    int nodeCount = 0;
    for (int i = 0; nodes[i] != nullptr; i++)
    {
        nodeCount++;
    }

    file.write((char*)(&nodeCount), sizeof(int));//写入一共有几种字符
    
    for (int i = 0; i < nodeCount; i++)//写入所有字符及其权重
    {
        Code cd;
        cd.value = nodes[i]->value;
        cd.priority = nodes[i]->priority;
        file.write((char*)(&cd), sizeof(Code));
    }

    int bsLen = bs.length() / 8 + 1;
    int lastCh = bs.length() % 8;
    file.write((char*)(&bsLen), sizeof(int));//用于在解码时计算进度
    file.write((char*)(&lastCh), sizeof(int));//用于解码时砍去二进制串最后不满一字节的多余部分

    unsigned char* outBS = new unsigned char[bsLen];//把二进制串每八位转换为一个uchar，然后写入

    for (int i = 0, count = 0; i < bsLen * 8;)
    {
        if (i + 8 < bs.length())
        {
            unsigned char sbs = 0;
            for (int j = 0; j < 8; j++)//取出八位，左高位右低位
            {
                if (bs[i + j] == '1') sbs += pow(2, 7 - j);//每一位若为1就加2的对应次方
            }
            outBS[count] = sbs;
            count++;
            i += 8;
        }
        else
        {
            unsigned char sbs = 0;
            for (int j = 0; j < lastCh; j++)//处理最后不满8位的字节
            {
                if (bs[i + j] == '1') sbs += pow(2, 7 - j);
            }
            outBS[count] = sbs;
            count++;
            i += 8;
        }
    }

    file.write((char*)outBS, bsLen * sizeof(unsigned char));//写入二进制串

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

/*
* 读取并解码文件
*/
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

    string fileIdentification = "";//检验标识符
    for (int i = 0; i < 3; i++)
    {
        char ch;
        file.read(&ch, sizeof(char));
        fileIdentification += ch;
    }
    if (fileIdentification != "HUF")
    {
        cout << "文件并非由该程序编码的文件" << endl;
        file.close();
        return;
    }

    cout << "正在解码" << fileDic << "，请稍候……" << endl;

    file.read((char*)(&codeCount), sizeof(int));

    Node** nodes = new Node * [codeCount + 1];//把存下来的字符和权重还原为结点
    for (int i = 0; i < codeCount + 1; i++)//防止脏数据
    {
        nodes[i] = nullptr;
    }
    for (int i = 0; i < codeCount; i++)
    {
        Code cd;
        file.read((char*)(&cd), sizeof(Code));
        nodes[i] = new Node(cd.priority, cd.value);
    }

    Heap heap;//重新生成哈夫曼编码树
    for (int i = 0; i < codeCount; i++)
    {
        heap.add(new HuffmanTree(nodes[i]));
    }

    HuffmanTree* tree = new HuffmanTree();
    tree->buildTree(heap);
    this->createHuffmanCode(tree);

    int bsLen = 0;
    int readLen = 0;
    int lastCh = 0;
    file.read((char*)(&bsLen), sizeof(int));
    file.read((char*)(&lastCh), sizeof(int));

    string bs = "";
    unsigned char uc = 0;

    while (file.read((char*)(&uc), sizeof(unsigned char)))//一字节一字节地读入
    {
        string shortS = "";//除基取余法，得到倒置的二进制串
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
        bs = bs + string(shortS.rbegin(), shortS.rend());//翻转倒置的二进制串
        readLen++;
        printf("\r已完成%.1lf%%  ", (double)readLen / (double)bsLen * 66);//这一步差不多占解码过程的2/3时间
    }

    bs = bs.substr(0, bs.length() - 8 + lastCh);//砍掉二进制串最后不满一字节的多余部分

    file.close();

    string text = decodeBinaryString(bs, nodes);//解码得到文本

    string newFile = fileDic.substr(0, fileDic.length() - 4);
    ofstream ofile;
    ofile.open(newFile, ios::out | ios::app);
    ofile.write(text.c_str(), text.size());
    ofile.close();
    cout << endl << "文件" << fileDic << "解码成功" << endl;
}
