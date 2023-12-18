#pragma once
#include"Node.h"
#include"CoorTrans.h"
#include<utility>

class Graph
{
public:

	const double infty_distance = -1;//无连接的两点距离

	Graph(int numVert) //构造函数，传入节点数，初始化表和矩阵
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

	int getV();//访问顶点数
	int getE();//访问边数
	int findFirst(int v);//找到第一个相邻点
	int findNext(int v1, int v2);//找到下一个相邻点
	void setName(int order,string inputName);//设置结点名称
	Node* getMark();//访问表
	void addEdge(int edgeStart,int edgeEnd, double wgt);//添加一条单向边
	void delEdge(int edgeStart, int edgeEnd);//删除边
	int findV(string key);//输入地点名称，查找图是否有这个字符串成员
	double getDistance(double lo1, double la1, double lo2, double la2);//输入两点经纬度坐标，得到两点的距离
	void standardInit();//将地图初始化
	pair<double, string> dijkstra(int location1, int location2);//使用迪杰斯特拉算法计算出最短路径，返回值：距离和路径

	~Graph()//析构
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