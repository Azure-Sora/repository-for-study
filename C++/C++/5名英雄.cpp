#include<iostream>
/*
设计一个英雄的结构体，包括成员姓名，年龄，性别;创建结构体数组，数组中存放5名英雄。
通过冒泡排序的算法，将数组中的英雄按照年龄进行升序排序，最终打印排序后的结果。
五名英雄信息如下：
    {"刘备",23,"男"},
    {"关羽",22,"男"},
    {"张飞",20,"男"},
    {"赵云",21,"男"},
    {"貂蝉",19,"女"},*/
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
        {"刘备",23,"男"},
        {"关羽",22,"男"},
        {"张飞",20,"男"},
        {"赵云",21,"男"},
        {"貂蝉",19,"女"}
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