#pragma once
#include"Node.h"
#include"CoorTrans.h"
#include<utility>

class Graph
{
public:

	const double infty_distance = -1;//�����ӵ��������

	Graph(int numVert) //���캯��������ڵ�������ʼ����;���
	{
		numVertex = numVert;
		numEdge = 0;
		mark = new Node[numVertex];
		adjMatrix = new double* [numVertex];
		for (int i = 0;i < numVertex; i++) {
			adjMatrix[i] = new double[numVertex];
		}
		for (int i = 0; i < numVertex; i++) {
			for (int j = 0; j < numVertex; j++) {
				adjMatrix[i][j] = infty_distance;
			}
		}
	}

	int getV();//���ʶ�����
	int getE();//���ʱ���
	int findFirst(int v);//�ҵ���һ�����ڵ�
	int findNext(int v1, int v2);//�ҵ���һ�����ڵ�
	void setName(int order,string inputName);//���ý������
	Node* getMark();//���ʱ�
	void addEdge(int edgeStart,int edgeEnd, double wgt);//���һ�������
	void delEdge(int edgeStart, int edgeEnd);//ɾ����
	int findV(string key);//����ص����ƣ�����ͼ�Ƿ�������ַ�����Ա
	double getDistance(double lo1, double la1, double lo2, double la2);//�������㾭γ�����꣬�õ�����ľ���
	void standardInit();//����ͼ��ʼ��
	pair<double, string> dijkstra(int location1, int location2);//ʹ�õϽ�˹�����㷨��������·��������ֵ�������·��

	~Graph()//����
	{
		delete[] mark;
		for (int i = 0; i < numVertex; i++) {
			delete[] adjMatrix[i];
		}
		delete[] adjMatrix;
	}

private:
	int numVertex;
	int numEdge;
	double** adjMatrix;
	Node* mark;
};