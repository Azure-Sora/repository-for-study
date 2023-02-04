#include<iostream>
/** �����ϵ�ˣ���ͨѶ¼��������ˣ���Ϣ�������������Ա����䡢��ϵ�绰����ͥסַ������¼1000��
* ��ʾ��ϵ�ˣ���ʾͨѶ¼��������ϵ����Ϣ
* ɾ����ϵ�ˣ�������������ɾ��ָ����ϵ��
* ������ϵ�ˣ����������鿴ָ����ϵ����Ϣ
* �޸���ϵ�ˣ��������������޸�ָ����ϵ��
* �����ϵ�ˣ����ͨѶ¼��������Ϣ
* �˳�ͨѶ¼���˳���ǰʹ�õ�ͨѶ¼*/
using namespace std;
struct information
{
	string name;
	string sex;
	int age;
	int tele;
	string adress;
};
void showmenu();
void addnew(information person[], int* person_count);
void showall(information person[], int* person_count);
void deleteone(information person[], int* person_count);
int oneexist(information person[], string lookfor, int* person_count);
void swaptwo(information person[], int a, int b);
void lookforone(information person[], int* person_count);
void editone(information person[], int* person_count);
void deleteall(int* person_count);
int main()
{
	information person[1000];
	int person_count = 0;
	bool goon = 1;
	while (goon)
	{
		system("cls");
		int selected_function = 0;
		showmenu();
		cin >> selected_function;
		system("cls");
		switch (selected_function)
		{
		case 1:
		{
			addnew(person, &person_count);
			break;
		}
		case 2:
		{
			showall(person, &person_count);
			break;
		}
		case 3:
		{
			deleteone(person, &person_count);
			break;
		}
		case 4:
		{
			lookforone(person, &person_count);
			break;
		}
		case 5:
		{
			editone(person, &person_count);
			break;
		}
		case 6:
		{
			deleteall(&person_count);
			break;
		}
		default:
		{
			goon = 0;
			break;
		}
		}
	}
	return 0;
}
void showmenu()
{
	cout << "***************************" << endl;
	cout << "*****  1�������ϵ��  *****" << endl;
	cout << "*****  2����ʾ��ϵ��  *****" << endl;
	cout << "*****  3��ɾ����ϵ��  *****" << endl;
	cout << "*****  4��������ϵ��  *****" << endl;
	cout << "*****  5���޸���ϵ��  *****" << endl;
	cout << "*****  6�������ϵ��  *****" << endl;
	cout << "*****  0���˳�ͨѶ¼  *****" << endl;
	cout << "***************************" << endl;
}
void addnew(information person[], int* person_count)
{
	cout << "���������û���Ϣ" << endl;
	cout << "������";
	cin >> person[*person_count].name;
	cout << "�Ա�";
	cin >> person[*person_count].sex;
	cout << "���䣺";
	cin >> person[*person_count].age;
	cout << "�绰��";
	cin >> person[*person_count].tele;
	cout << "��ַ��";
	cin >> person[*person_count].adress;
	cout << "�û� " << *person_count + 1 << " " << person[*person_count].name << " �Ѵ����ɹ���" << endl;
	(*person_count)++;
	system("pause");
	system("cls");
}
void showall(information person[], int* person_count)
{
	if (*person_count == 0)
	{
		cout << "��ǰ��¼Ϊ�ա�" << endl;
	}
	else
	{
		for (int i = 0; i < *person_count; i++)
		{
			cout << "�û�" << i + 1 << endl;
			cout << "������" << person[i].name << endl;
			cout << "�Ա�" << person[i].sex << endl;
			cout << "���䣺" << person[i].age << endl;
			cout << "�绰��" << person[i].tele << endl;
			cout << "��ַ��" << person[i].adress << endl;
		}
	}
	system("pause");
	system("cls");
}
int oneexist(information person[], string lookfor, int person_count)
{
	for (int i = 0; i < person_count; i++)
	{
		if (person[i].name == lookfor)
		{
			return i;
		}
	}
	return -1;
}
void swaptwo(information person[], int a, int b)
{
	information temp;
	temp.name = person[a].name;
	temp.sex = person[a].sex;
	temp.age = person[a].age;
	temp.tele = person[a].tele;
	temp.adress = person[a].adress;
	person[a].name = person[b].name;
	person[a].sex = person[b].sex;
	person[a].age = person[b].age;
	person[a].tele = person[b].tele;
	person[a].adress = person[b].adress;
	person[b].name = temp.name;
	person[b].sex = temp.sex;
	person[b].age = temp.age;
	person[b].tele = temp.tele;
	person[b].adress = temp.adress;
}
void deleteone(information person[], int* person_count)
{
	string todelete;
	cout << "������Ҫɾ������ϵ��������";
	cin >> todelete;
	int position = oneexist(person, todelete, *person_count);
	if (position != (-1))
	{
		cout << "��ɾ��" << todelete << "�ļ�¼" << endl;
		person[position] = { {},{},{},{},{} };
		for (int i = position; i < *person_count; i++)
		{
			swaptwo(person, i, i + 1);
		}
		(*person_count)--;
	}
	else
	{
		cout << "���޴��ˡ�" << endl;
	}
	system("pause");
	system("cls");
}
void lookforone(information person[], int* person_count)
{
	string lookfor;
	cout << "������Ҫ���ҵ���ϵ��������";
	cin >> lookfor;
	int position = oneexist(person, lookfor, *person_count);
	if (position != (-1))
	{
		cout << "�ҵ��û�" << position + 1 << endl;
		cout << "������" << person[position].name << endl;
		cout << "�Ա�" << person[position].sex << endl;
		cout << "���䣺" << person[position].age << endl;
		cout << "�绰��" << person[position].tele << endl;
		cout << "��ַ��" << person[position].adress << endl;
	}
	else
	{
		cout << "���޴��ˡ�" << endl;
	}
	system("pause");
	system("cls");
}
void editone(information person[], int* person_count)
{
	string edit;
	cout << "������Ҫ�޸ĵ���ϵ��������";
	cin >> edit;
	int position = oneexist(person, edit, *person_count);
	if (position != (-1))
	{
		cout << "���������û���Ϣ" << endl;
		cout << "������";
		cin >> person[position].name;
		cout << "�Ա�";
		cin >> person[position].sex;
		cout << "���䣺";
		cin >> person[position].age;
		cout << "�绰��";
		cin >> person[position].tele;
		cout << "��ַ��";
		cin >> person[position].adress;
		cout << "�û� " << position + 1 << " " << person[position].name << " ���޸ĳɹ���" << endl;
	}
	else
	{
		cout << "���޴��ˡ�" << endl;
	}
	system("pause");
	system("cls");
}
void deleteall(int* person_count)
{
	*person_count = 0;
	cout << "�����ȫ����¼��" << endl;
	system("pause");
	system("cls");
}