#include<iostream>
/*
���һ��Ӣ�۵Ľṹ�壬������Ա���������䣬�Ա�;�����ṹ�����飬�����д��5��Ӣ�ۡ�
ͨ��ð��������㷨���������е�Ӣ�۰���������������������մ�ӡ�����Ľ����
����Ӣ����Ϣ���£�
    {"����",23,"��"},
    {"����",22,"��"},
    {"�ŷ�",20,"��"},
    {"����",21,"��"},
    {"����",19,"Ů"},*/
using namespace std;
struct id
{
    string name;
    int age;
    string sex;
};
void swap(id* a, id* b)
{
    id temp;
    temp.name = a->name;
    temp.age = a->age;
    temp.sex = a->sex;
    a->name = b->name;
    a->age = b->age;
    a->sex = b->sex;
    b->name = temp.name;
    b->age = temp.age;
    b->sex = temp.sex;
}
int main()
{
    id hero[5] =
    {
        {"����",23,"��"},
        {"����",22,"��"},
        {"�ŷ�",20,"��"},
        {"����",21,"��"},
        {"����",19,"Ů"}
    };
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4 - i; j++)
        {
            if (hero[j].age > hero[j + 1].age)
            {
                swap(&hero[j], &hero[j + 1]);
            }
        }
    }
    for(int i=0;i<5;i++)
    {
        cout << hero[i].name << hero[i].age << hero[i].sex << endl;
    }
	return 0;
}