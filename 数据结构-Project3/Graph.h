#pragma once
#include"Node.h"
#include"CoorTrans.h"
#include<utility>

class Graph
{
public:

	const double infty_distance = -1;

	Graph(int numVert) 
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

	int getV();
	int getE();
	int findFirst(int v);
	int findNext(int v1, int v2);
	void setName(int order,string inputName);
	Node* getMark();
	void addEdge(int edgeStart,int edgeEnd, double wgt);
	void delEdge(int edgeStart, int edgeEnd);
	int findV(string key);
	double getDistance(double lo1, double la1, double lo2, double la2);
	void standardInit();
	pair<double, string> dijkstra(int location1, int location2);

	~Graph()
	{
		//delete[] mark;
		//for (int i = 0; i < numVertex; i++) {
		//	delete[] adjMatrx[i];
		//}
		//delete[] adjMatrx;
	}

private:
	int numVertex;
	int numEdge;
	double** adjMatrix;
	Node* mark;
};