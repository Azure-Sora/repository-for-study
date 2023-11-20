#include "Coder.h"
#include"Node.h"
#include"HuffmanTree.h"
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

std::string Coder::readUncodedFile(std::string fileDic)//��Դ�ļ����������ݶ���һ��string��
{
    string out = "";
    ifstream file;
    file.open(fileDic, ios::in);
    if (!file.is_open())
    {
        cout << "�ļ���ʧ��" << endl;
        return out;
    }

    string temp;
    getline(file, out);
    while (getline(file, temp))//����һ���ֶ����һ�����з�
    {
        out = out + '\n' + temp;
    }
    file.close();
    return out;
}

void Coder::encodeFile(std::string file)//���ڱ����ļ���������
{
    string text = this->readUncodedFile(file);
    if (text == "") return;

    cout << "���ڱ���" << file << "�����Ժ򡭡�" << endl;
    Heap heap;
    Node** nodeArr;
    heap.init(this->createNodes(text, nodeArr));//���ı����ַ�����Ȩ�س�ʼ��������

    HuffmanTree* tree = new HuffmanTree();
    tree->buildTree(heap);//������������
    this->createHuffmanCode(tree);//��������������

    string bs = encodeToBinaryString(text, nodeArr);//���ı�ת��Ϊ�����ƴ�

    saveCodedFile(bs, nodeArr, file);//д�����õ��ļ�
}

/*
* ȡ���ַ���㼰Ȩ��ֵ
* text Դ�ı�
* nodeArr ���ڰ����б������¼������������ƻ���ʱ����
* return ��һ��һ������Լ���Ϊ����ɭ�ֺ��ܽ����
*/
std::pair<HuffmanTree**, int> Coder::createNodes(std::string text, Node**& nodeArr)
{
    Node** nodes;
    int nodesVolume = 0;
    int nodesCount = 0;
    
    auto expandNodes = [&]() {//��չ���ɽ������������
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
    bool exist;//��¼һ���ַ��Ƿ��Ѵ���
    for (int i = 0; i < text.length(); i++)
    {
        char ch = text[i];
        exist = false;
        for (int j = 0; j < nodesCount; j++)//�����еĽ����Ѱ��ȡ�����ַ����о�����Ȩ��
        {
            if (nodes[j]->value == ch)
            {
                nodes[j]->priority++;
                exist = true;
                break;
            }
        }
        if (!exist)//û�о��������
        {
            if (nodesCount + 1 >= nodesVolume) expandNodes();
            nodes[nodesCount] = new Node(1, ch);
            nodesCount++;
        }
    }

    HuffmanTree** forest = new HuffmanTree * [nodesCount];//�ѽ�㻯Ϊɭ��
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
* ʹ�õݹ�ķ�ʽ������룬���ڵ����Ϊ�ա�ÿ�ε�������ڵ�ı���Ϊ�Լ�+"0"���ҽڵ�Ϊ�Լ�+"1"���ٷֱ�Բ���Ҷ�ӽ������Һ��ӵ���
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
* ����Դ�ı�����ÿһ���ַ�ת��Ϊ���õĹ������룬��ȫ������һ�𷵻�
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
* �������Ķ����ƴ�������Դ�ı�
*/
std::string Coder::decodeBinaryString(std::string bs, Node** nodes)
{
    string out = "";
    for (int i = 0; i < bs.length();)//�ȼ������ֻ��һλ������Ѱ���Ƿ��ж�Ӧ���ַ���û����ѱ��볤�ȼ�һλ���ٴ�Ѱ���ַ���ֱ���ҵ��ַ���i+=���α��볤��
    {
        bool find = false;
        int len = 1;//����ı��볤��
        while (!find)
        {
            string temps = "";
            for (int j = 0; j < len; j++)//ȡ�����μ���ı���
            {
                temps += bs[i + j];
            }
            for (int k = 0; nodes[k] != nullptr; k++)//Ѱ�Ҷ�Ӧ�ַ�
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
        printf("\r�����%.1lf%%  ", (double)i / (double)bs.length() * 34 + 66);
    }

    return out;
}

/*
* �ѱ���õĶ����ƴ����ϸ�����Ϣ�󱣴����ļ���
*/
void Coder::saveCodedFile(std::string bs, Node** nodes, std::string fileName)
{
    struct Code //���ڼ�¼�ַ�����Ȩ�صĽṹ��
    {
        char value;
        int priority;
    };

    ofstream file;
    file.open(fileName + ".huf", ios::out | ios::binary | ios::app);//д������ļ�

    string fileIdentification = "HUF";//���ڱ���ļ�Ϊ�ó�����룬�ڽ���ʱ��֤
    file.write(fileIdentification.c_str(), 3 * sizeof(char));

    int nodeCount = 0;
    for (int i = 0; nodes[i] != nullptr; i++)
    {
        nodeCount++;
    }

    file.write((char*)(&nodeCount), sizeof(int));//д��һ���м����ַ�
    
    for (int i = 0; i < nodeCount; i++)//д�������ַ�����Ȩ��
    {
        Code cd;
        cd.value = nodes[i]->value;
        cd.priority = nodes[i]->priority;
        file.write((char*)(&cd), sizeof(Code));
    }

    int bsLen = bs.length() / 8 + 1;
    int lastCh = bs.length() % 8;
    file.write((char*)(&bsLen), sizeof(int));//�����ڽ���ʱ�������
    file.write((char*)(&lastCh), sizeof(int));//���ڽ���ʱ��ȥ�����ƴ������һ�ֽڵĶ��ಿ��

    unsigned char* outBS = new unsigned char[bsLen];//�Ѷ����ƴ�ÿ��λת��Ϊһ��uchar��Ȼ��д��

    for (int i = 0, count = 0; i < bsLen * 8;)
    {
        if (i + 8 < bs.length())
        {
            unsigned char sbs = 0;
            for (int j = 0; j < 8; j++)//ȡ����λ�����λ�ҵ�λ
            {
                if (bs[i + j] == '1') sbs += pow(2, 7 - j);//ÿһλ��Ϊ1�ͼ�2�Ķ�Ӧ�η�
            }
            outBS[count] = sbs;
            count++;
            i += 8;
        }
        else
        {
            unsigned char sbs = 0;
            for (int j = 0; j < lastCh; j++)//���������8λ���ֽ�
            {
                if (bs[i + j] == '1') sbs += pow(2, 7 - j);
            }
            outBS[count] = sbs;
            count++;
            i += 8;
        }
    }

    file.write((char*)outBS, bsLen * sizeof(unsigned char));//д������ƴ�

    int codedSize = file.tellp() / 1024;

    file.close();

    ifstream srcFile;
    srcFile.open(fileName, ios::in);
    srcFile.seekg(0, ios::end);
    int uncodedSize = srcFile.tellg() / 1024;
    srcFile.close();

    cout << "�ļ��ɹ�����Ϊ" << fileName + ".huf" << endl;
    cout << "Դ�ļ���С" << uncodedSize << "KB�������ļ���С��" << codedSize << "KB��ѹ���ʣ�" << ((double)codedSize / (double)uncodedSize) * 100 << "%" << endl;
}

/*
* ��ȡ�������ļ�
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
        cout << "�ļ���ʧ��" << endl;
        return;
    }

    string fileIdentification = "";//�����ʶ��
    for (int i = 0; i < 3; i++)
    {
        char ch;
        file.read(&ch, sizeof(char));
        fileIdentification += ch;
    }
    if (fileIdentification != "HUF")
    {
        cout << "�ļ������ɸó��������ļ�" << endl;
        file.close();
        return;
    }

    cout << "���ڽ���" << fileDic << "�����Ժ򡭡�" << endl;

    file.read((char*)(&codeCount), sizeof(int));

    Node** nodes = new Node * [codeCount + 1];//�Ѵ��������ַ���Ȩ�ػ�ԭΪ���
    for (int i = 0; i < codeCount + 1; i++)//��ֹ������
    {
        nodes[i] = nullptr;
    }
    for (int i = 0; i < codeCount; i++)
    {
        Code cd;
        file.read((char*)(&cd), sizeof(Code));
        nodes[i] = new Node(cd.priority, cd.value);
    }

    Heap heap;//�������ɹ�����������
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

    while (file.read((char*)(&uc), sizeof(unsigned char)))//һ�ֽ�һ�ֽڵض���
    {
        string shortS = "";//����ȡ�෨���õ����õĶ����ƴ�
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
        bs = bs + string(shortS.rbegin(), shortS.rend());//��ת���õĶ����ƴ�
        readLen++;
        printf("\r�����%.1lf%%  ", (double)readLen / (double)bsLen * 66);//��һ�����ռ������̵�2/3ʱ��
    }

    bs = bs.substr(0, bs.length() - 8 + lastCh);//���������ƴ������һ�ֽڵĶ��ಿ��

    file.close();

    string text = decodeBinaryString(bs, nodes);//����õ��ı�

    string newFile = fileDic.substr(0, fileDic.length() - 4);
    ofstream ofile;
    ofile.open(newFile, ios::out | ios::app);
    ofile.write(text.c_str(), text.size());
    ofile.close();
    cout << endl << "�ļ�" << fileDic << "����ɹ�" << endl;
}
