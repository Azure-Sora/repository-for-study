#include<iostream>
/** 添加联系人：向通讯录中添加新人，信息包括（姓名、性别、年龄、联系电话、家庭住址）最多记录1000人
* 显示联系人：显示通讯录中所有联系人信息
* 删除联系人：按照姓名进行删除指定联系人
* 查找联系人：按照姓名查看指定联系人信息
* 修改联系人：按照姓名重新修改指定联系人
* 清空联系人：清空通讯录中所有信息
* 退出通讯录：退出当前使用的通讯录*/
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
	cout << "*****  1、添加联系人  *****" << endl;
	cout << "*****  2、显示联系人  *****" << endl;
	cout << "*****  3、删除联系人  *****" << endl;
	cout << "*****  4、查找联系人  *****" << endl;
	cout << "*****  5、修改联系人  *****" << endl;
	cout << "*****  6、清空联系人  *****" << endl;
	cout << "*****  0、退出通讯录  *****" << endl;
	cout << "***************************" << endl;
}
void addnew(information person[], int* person_count)
{
	cout << "请输入新用户信息" << endl;
	cout << "姓名：";
	cin >> person[*person_count].name;
	cout << "性别：";
	cin >> person[*person_count].sex;
	cout << "年龄：";
	cin >> person[*person_count].age;
	cout << "电话：";
	cin >> person[*person_count].tele;
	cout << "地址：";
	cin >> person[*person_count].adress;
	cout << "用户 " << *person_count + 1 << " " << person[*person_count].name << " 已创建成功。" << endl;
	(*person_count)++;
	system("pause");
	system("cls");
}
void showall(information person[], int* person_count)
{
	if (*person_count == 0)
	{
		cout << "当前记录为空。" << endl;
	}
	else
	{
		for (int i = 0; i < *person_count; i++)
		{
			cout << "用户" << i + 1 << endl;
			cout << "姓名：" << person[i].name << endl;
			cout << "性别：" << person[i].sex << endl;
			cout << "年龄：" << person[i].age << endl;
			cout << "电话：" << person[i].tele << endl;
			cout << "地址：" << person[i].adress << endl;
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
	cout << "请输入要删除的联系人姓名：";
	cin >> todelete;
	int position = oneexist(person, todelete, *person_count);
	if (position != (-1))
	{
		cout << "已删除" << todelete << "的记录" << endl;
		person[position] = { {},{},{},{},{} };
		for (int i = position; i < *person_count; i++)
		{
			swaptwo(person, i, i + 1);
		}
		(*person_count)--;
	}
	else
	{
		cout << "查无此人。" << endl;
	}
	system("pause");
	system("cls");
}
void lookforone(information person[], int* person_count)
{
	string lookfor;
	cout << "请输入要查找的联系人姓名：";
	cin >> lookfor;
	int position = oneexist(person, lookfor, *person_count);
	if (position != (-1))
	{
		cout << "找到用户" << position + 1 << endl;
		cout << "姓名：" << person[position].name << endl;
		cout << "性别：" << person[position].sex << endl;
		cout << "年龄：" << person[position].age << endl;
		cout << "电话：" << person[position].tele << endl;
		cout << "地址：" << person[position].adress << endl;
	}
	else
	{
		cout << "查无此人。" << endl;
	}
	system("pause");
	system("cls");
}
void editone(information person[], int* person_count)
{
	string edit;
	cout << "请输入要修改的联系人姓名：";
	cin >> edit;
	int position = oneexist(person, edit, *person_count);
	if (position != (-1))
	{
		cout << "请输入新用户信息" << endl;
		cout << "姓名：";
		cin >> person[position].name;
		cout << "性别：";
		cin >> person[position].sex;
		cout << "年龄：";
		cin >> person[position].age;
		cout << "电话：";
		cin >> person[position].tele;
		cout << "地址：";
		cin >> person[position].adress;
		cout << "用户 " << position + 1 << " " << person[position].name << " 已修改成功。" << endl;
	}
	else
	{
		cout << "查无此人。" << endl;
	}
	system("pause");
	system("cls");
}
void deleteall(int* person_count)
{
	*person_count = 0;
	cout << "已清空全部记录！" << endl;
	system("pause");
	system("cls");
}