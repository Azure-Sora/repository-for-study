#include<iostream>
#include "Graph.h"
using namespace std;

int Graph::getV()
{
	return numVertex;
}

int Graph::getE()
{
	return numEdge;
}

int Graph::findFirst(int v)
{
	for (int i = 0; i < numVertex; i++) {
		if (adjMatrix[v][i] != 0 && adjMatrix[v][i] != Graph::infty_distance)
			return i;
	}
	return -1;
}

int Graph::findNext(int v1, int v2)
{
	for (int i = v2 + 1; i < numVertex; i++) {
		if (adjMatrix[v1][i] != 0 && adjMatrix[v1][i] != Graph::infty_distance)
			return i;
	}
	return -1;
}

void Graph::setName(int order, string inputName)
{
	mark[order - 1].name = inputName;
}

Node* Graph::getMark()
{
	return mark;
}

void Graph::addEdge(int edgeStart, int edgeEnd, double wgt)
{
	if (wgt <= 0)
	{
		cout << "非法输入权值" << endl;
	}
	else if(adjMatrix[edgeStart - 1][edgeEnd - 1] != 0)
	{
		cout << "要添加的边已存在，权值为" << adjMatrix[edgeStart - 1][edgeEnd - 1] << endl;
	}
	else
	{
		adjMatrix[edgeStart - 1][edgeEnd - 1] = wgt;
		numEdge++;
	}
}

void Graph::delEdge(int edgeStart, int edgeEnd)
{
	adjMatrix[edgeStart - 1][edgeEnd - 1] = 0;
	numEdge--;
}

int Graph::findV(string key)
{
	for(int i = 0;i< numVertex;i++)
	{
		if (mark[i].name == key) return i;
	}
	return -1;
}

double Graph::getDistance(double lo1, double la1, double lo2, double la2)
{
	double x1, y1, x2, y2, distance;
	PrjPoint point1 = PrjPoint();
	PrjPoint point2 = PrjPoint();
	point1.SetLoLa(lo1, la1);
	point2.SetLoLa(lo2, la2);
	point1.Getxy(&x1, &y1);
	point2.Getxy(&x2, &y2);
	distance = sqrt((x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2));
	return distance;
}

void Graph::standardInit()
{
	if (numVertex < 30)
		cout << "结点数不足" << endl;
	else {
		mark[0].name = "文星";//103.997218,30.556315
		mark[1].name = "三元";//104.032516,30.587695
		mark[2].name = "高朋大道";//104.039926,30.623718
		mark[3].name = "春熙路";//104.086002,30.659204
		mark[4].name = "九兴大道";//104.045255,30.627609 
		mark[5].name = "神仙树";//104.054223,30.616046 
		mark[6].name = "火车南站";//104.073663,30.610881
		mark[7].name = "中医大省医院";//104.047256,30.672356
		mark[8].name = "高升桥";//104.048664,30.646067
		mark[9].name = "西北桥";//104.064075,30.691791
		mark[10].name = "北站西二路";//104.072587,30.700391 
		mark[11].name = "火车北站";//104.080354,30.701458 
		mark[12].name = "骡马市";//104.072169,30.672684
		mark[13].name = "天府广场";//104.072525,30.663485
		mark[14].name = "省体育馆";//104.072783,30.639472
		mark[15].name = "倪家桥";//104.072895,30.630932
		mark[16].name = "牛王庙";//104.100273,30.650562
		mark[17].name = "东大路";//104.119101,30.639263
		mark[18].name = "成都东客站";//104.147357,30.635151
		mark[19].name = "槐树店";//104.145913,30.65598
		mark[20].name = "市一医院";//104.056931,30.596074
		mark[21].name = "驷马桥";//104.100604,30.701188
		mark[22].name = "人民北路";//104.079208,30.691592
		mark[23].name = "前锋路";//104.099127,30.684027
		mark[24].name = "理工大学";//104.143066,30.679745
		mark[25].name = "市二医院";//104.091107,30.666393
		mark[26].name = "玉双路";//104.10515,30.659751
		mark[27].name = "双桥路";//104.119789,30.652251
		mark[28].name = "东光";//104.104556,30.625342
		mark[29].name = "琉璃场";//104.106408,30.613229

		adjMatrix[0][1] = getDistance(30.556315, 103.997218, 30.587695, 104.032516);
		adjMatrix[1][0] = adjMatrix[0][1];
		adjMatrix[1][2] = getDistance(30.587695, 104.032516, 30.623718, 104.039926);
		adjMatrix[2][1] = adjMatrix[1][2];
		adjMatrix[2][4] = getDistance(30.623718, 104.039926, 30.627609, 104.045255);
		adjMatrix[4][2] = adjMatrix[2][4];
		adjMatrix[2][5] = getDistance(30.623718, 104.039926, 30.616046, 104.054223);
		adjMatrix[5][2] = adjMatrix[2][5];
		adjMatrix[3][25] = getDistance(30.659204, 104.086002, 30.666393, 104.091107);
		adjMatrix[25][3] = adjMatrix[3][25];
		adjMatrix[3][13] = getDistance(30.659204, 104.086002, 30.663485, 104.072525);
		adjMatrix[13][3] = adjMatrix[3][13];
		adjMatrix[3][14] = getDistance(30.659204, 104.086002, 30.639472, 104.072783);
		adjMatrix[14][3] = adjMatrix[3][14];
		adjMatrix[3][16] = getDistance(30.659204, 104.086002, 30.650562, 104.100273);
		adjMatrix[16][3] = adjMatrix[3][16];
		adjMatrix[4][8] = getDistance(30.627609, 104.045255, 30.646067, 104.048664);
		adjMatrix[8][4] = adjMatrix[4][8];
		adjMatrix[4][15] = getDistance(30.627609, 104.045255, 30.630932, 104.072895);
		adjMatrix[15][4] = adjMatrix[4][15];
		adjMatrix[4][5] = getDistance(30.627609, 104.045255, 30.616046, 104.054223);
		adjMatrix[5][4] = adjMatrix[4][5];
		adjMatrix[5][20] = getDistance(30.616046, 104.054223, 30.596074, 104.056931);
		adjMatrix[20][5] = adjMatrix[5][20];
		adjMatrix[5][6] = getDistance(30.616046, 104.054223, 30.610881, 104.073663);
		adjMatrix[6][5] = adjMatrix[5][6];
		adjMatrix[6][15] = getDistance(30.610881, 104.073663, 30.630932, 104.072895);
		adjMatrix[15][6] = adjMatrix[6][15];
		adjMatrix[6][29] = getDistance(30.610881, 104.073663, 30.613229, 104.106408);
		adjMatrix[29][6] = adjMatrix[6][29];
		adjMatrix[7][9] = getDistance(30.672356, 104.047256, 30.691791, 104.064075);
		adjMatrix[9][7] = adjMatrix[7][9];
		adjMatrix[7][8] = getDistance(30.672356, 104.047256, 30.646067, 104.048664);
		adjMatrix[8][7] = adjMatrix[7][8];
		adjMatrix[7][13] = getDistance(30.672356, 104.047256, 30.663485, 104.072525);
		adjMatrix[13][7] = adjMatrix[7][13];
		adjMatrix[7][12] = getDistance(30.672356, 104.047256, 30.672684, 104.072169);
		adjMatrix[12][7] = adjMatrix[7][12];
		adjMatrix[8][14] = getDistance(30.646067, 104.048664, 30.639472, 104.072783);
		adjMatrix[14][8] = adjMatrix[8][14];
		adjMatrix[9][10] = getDistance(30.691791, 104.064075, 30.700391, 104.072587);
		adjMatrix[10][9] = adjMatrix[9][10];
		adjMatrix[9][22] = getDistance(30.691791, 104.064075, 30.691592, 104.079208);
		adjMatrix[22][9] = adjMatrix[9][22];
		adjMatrix[10][11] = getDistance(30.700391, 104.072587, 30.701458, 104.080354);
		adjMatrix[11][10] = adjMatrix[10][11];
		adjMatrix[11][22] = getDistance(30.701458, 104.080354, 30.691592, 104.079208);
		adjMatrix[22][11] = adjMatrix[11][22];
		adjMatrix[11][21] = getDistance(30.701458, 104.080354, 30.701188, 104.100604);
		adjMatrix[21][11] = adjMatrix[11][21];
		adjMatrix[12][22] = getDistance(30.672684, 104.072169, 30.691592, 104.079208);
		adjMatrix[22][12] = adjMatrix[12][22];
		adjMatrix[12][25] = getDistance(30.672684, 104.072169, 30.666393, 104.091107);
		adjMatrix[25][12] = adjMatrix[12][25];
		adjMatrix[12][13] = getDistance(30.672684, 104.072169, 30.663485, 104.072525);
		adjMatrix[13][12] = adjMatrix[12][13];
		adjMatrix[13][14] = getDistance(30.663485, 104.072525, 30.639472, 104.072783);
		adjMatrix[14][13] = adjMatrix[13][14];
		adjMatrix[14][15] = getDistance(30.639472, 104.072783, 30.630932, 104.072895);
		adjMatrix[15][14] = adjMatrix[14][15];
		adjMatrix[15][28] = getDistance(30.630932, 104.072895, 30.625342, 104.104556);
		adjMatrix[28][15] = adjMatrix[15][28];
		adjMatrix[16][26] = getDistance(30.650562, 104.100273, 30.659751, 104.10515);
		adjMatrix[26][16] = adjMatrix[16][26];
		adjMatrix[16][28] = getDistance(30.650562, 104.100273, 30.625342, 104.104556);
		adjMatrix[28][16] = adjMatrix[16][28];
		adjMatrix[16][17] = getDistance(30.650562, 104.100273, 30.639263, 104.119101);
		adjMatrix[17][16] = adjMatrix[16][17];
		adjMatrix[17][27] = getDistance(30.639263, 104.119101, 30.652251, 104.119789);
		adjMatrix[27][17] = adjMatrix[17][27];
		adjMatrix[17][28] = getDistance(30.639263, 104.119101, 30.625342, 104.104556);
		adjMatrix[28][17] = adjMatrix[17][28];
		adjMatrix[17][18] = getDistance(30.639263, 104.119101, 30.635151, 104.147357);
		adjMatrix[18][17] = adjMatrix[17][18];
		adjMatrix[18][29] = getDistance(30.635151, 104.147357, 30.613229, 104.106408);
		adjMatrix[29][18] = adjMatrix[18][29];
		adjMatrix[18][19] = getDistance(30.635151, 104.147357, 30.65598, 104.145913);
		adjMatrix[19][18] = adjMatrix[18][19];
		adjMatrix[19][24] = getDistance(30.65598, 104.145913, 30.679745, 104.143066);
		adjMatrix[24][19] = adjMatrix[19][24];
		adjMatrix[19][27] = getDistance(30.65598, 104.145913, 30.652251, 104.119789);
		adjMatrix[27][19] = adjMatrix[19][27];
		adjMatrix[21][23] = getDistance(30.701188, 104.100604, 30.684027, 104.099127);
		adjMatrix[23][21] = adjMatrix[21][23];
		adjMatrix[21][24] = getDistance(30.701188, 104.100604, 30.679745, 104.143066);
		adjMatrix[24][21] = adjMatrix[21][24];
		adjMatrix[22][23] = getDistance(30.691592, 104.079208, 30.684027, 104.099127);
		adjMatrix[23][22] = adjMatrix[22][23];
		adjMatrix[23][26] = getDistance(30.684027, 104.099127, 30.659751, 104.10515);
		adjMatrix[26][23] = adjMatrix[23][26];
		adjMatrix[23][25] = getDistance(30.684027, 104.099127, 30.666393, 104.091107);
		adjMatrix[25][23] = adjMatrix[23][25];
		adjMatrix[24][27] = getDistance(30.679745, 104.143066, 30.652251, 104.119789);
		adjMatrix[27][24] = adjMatrix[24][27];
		adjMatrix[25][26] = getDistance(30.666393, 104.091107, 30.659751, 104.10515);
		adjMatrix[26][25] = adjMatrix[25][26];
		adjMatrix[26][27] = getDistance(30.659751, 104.10515, 30.652251, 104.119789);
		adjMatrix[27][26] = adjMatrix[26][27];
		adjMatrix[28][29] = getDistance(30.625342, 104.104556, 30.613229, 104.106408);
		adjMatrix[29][28] = adjMatrix[28][29];

		numEdge = 100;
	}

}

pair<double, string> Graph::dijkstra(int location1, int location2)
{
	bool* isFinished = new bool[numVertex];
	double* distance = new double[numVertex];
	int* path = new int[numVertex];
	int nowOperating = location1;
	for (int i = 0; i < numVertex; i++)
	{
		isFinished[i] = false;
		distance[i] = Graph::infty_distance;
		path[i] = -1;
	}

	isFinished[location1] = true;
	distance[location1] = 0;

	while (!isFinished[location2])
	{
		int next = findFirst(nowOperating);
		while (next != -1)
		{
			if (!isFinished[next])
			{
				if(distance[next] == Graph::infty_distance || distance[nowOperating] + adjMatrix[nowOperating][next] < distance[next])
				distance[next] = distance[nowOperating] + adjMatrix[nowOperating][next];
				path[next] = nowOperating;
			}
			next = findNext(nowOperating, next);
		}
		int closest = 0;
		while (isFinished[closest] || distance[closest] == Graph::infty_distance) closest++;
		for (int j = 0; j < numVertex; j++)
		{
			if(!isFinished[j] && distance[j] != Graph::infty_distance && distance[j] < distance[closest])
			{
				closest = j;
			}
		}
		isFinished[closest] = true;
		nowOperating = closest;


	}

	string finalPath = "";
	finalPath.append(getMark()[location2].name);
	int pth = path[location2];
	while(pth != -1)
	{
		finalPath.append(" <= ");
		finalPath.append(getMark()[pth].name);
		pth = path[pth];
	}

	double finalDist = distance[location2];

	delete[] isFinished;
	delete[] distance;
	delete[] path;

	return pair<double, string>(finalDist, finalPath);
	
}
