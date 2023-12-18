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
	cout << "����������ѡ���ܣ�\n1.�г��ɹ����ҵĵص�\n2.�����������·��\n3.�˳�" << endl;
}

void function(Graph* graph1)//ʵ�ֲ˵�����
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
		cout << "������ص�1���ƣ�";
		cin >> input1;
		if (graph1->findV(input1) == -1)
			cout << "�Ƿ�����ص㣬������" << endl;
		else
		{
			cout << "������ص�2���ƣ�";
			cin >> input2;
			if(graph1->findV(input2) == -1)
				cout << "�Ƿ�����ص㣬������" << endl;
			else//��ȷ������������·�������
			{
				int location1 = graph1->findV(input1);
				int location2 = graph1->findV(input2);

				pair<double, string> result = graph1->dijkstra(location1, location2);
				cout << "���룺"; 
				printf("%.3lf", result.first / 1000);
				cout << "ǧ��" << endl << "·����" << result.second << endl;
				
			}
		}
	}
	else if (input == "3")
	{
		exit(0);
	}
	else
	{
		cout << "�Ƿ����룬������" << endl;
	}
}