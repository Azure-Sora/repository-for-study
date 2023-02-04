#include<iostream>
/*学校正在做毕设项目，每名老师带领5个学生，总共有3名老师，需求如下
设计学生和老师的结构体，其中在老师的结构体中，有老师姓名和一个存放5名学生的数组作为成员
学生的成员有姓名、考试分数，创建数组存放3名老师，通过函数给每个老师及所带的学生赋值
最终打印出老师数据以及老师所带的学生数据。*/
using namespace std;
struct student
{
    string name;
    int score;
};
struct teacher
{
    string name;
    student stu[5];
};
int main() 
{
    teacher teach[3];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (j == 0)
            {
                cout << "请输入第" << i + 1 << "位老师的名称：";
                cin >> teach[i].name;
            }
            cout << "请输入第" << i + 1 << "位老师" << "第" << j + 1 << "位学生的名字：";
            cin >> teach[i].stu[j].name;
            cout << "请输入第" << i + 1 << "位老师" << "第" << j + 1 << "位学生的成绩：";
            cin >> teach[i].stu[j].score;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "老师" << teach[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "学生" << teach[i].stu[j].name << "成绩" << teach[i].stu[j].score << endl;
        }
    }
    return 0;
}