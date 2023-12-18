#include<iostream>
#include"Graph.h"
#include"CoorTrans.h"
void showMenu();
void function(Graph* graph1);

int main() 
{
	Graph* graph1 = new Graph(30);
	graph1->standardInit();
	while (true)
	{
		showMenu();
		function(graph1);
		system("pause");
		system("cls");
	}

	return 0;
}

void showMenu() 
{
	cout << "请输入数字选择功能：\n1.列出可供查找的地点\n2.查找两地最短路程\n3.退出" << endl;
}

void function(Graph* graph1)//实现菜单功能
{
	string input;
	cin >> input;
	if (input == "1")
	{
		for (int i = 0; i < graph1->getV(); i++)
		{
			if ((i + 1) % 5 == 0)
			{
				cout << graph1->getMark()[i].name << endl;
			}
			else
			{
				cout << graph1->getMark()[i].name << "  ";
			}
		}
	}
	else if (input == "2")
	{
		string input1, input2;
		double distance;
		cout << "请输入地点1名称：";
		cin >> input1;
		if (graph1->findV(input1) == -1)
			cout << "非法输入地点，请重试" << endl;
		else
		{
			cout << "请输入地点2名称：";
			cin >> input2;
			if(graph1->findV(input2) == -1)
				cout << "非法输入地点，请重试" << endl;
			else//正确输入两点后查找路径并输出
			{
				int location1 = graph1->findV(input1);
				int location2 = graph1->findV(input2);

				pair<double, string> result = graph1->dijkstra(location1, location2);
				cout << "距离："; 
				printf("%.3lf", result.first / 1000);
				cout << "千米" << endl << "路径：" << result.second << endl;
				
			}
		}
	}
	else if (input == "3")
	{
		exit(0);
	}
	else
	{
		cout << "非法输入，请重试" << endl;
	}
}