#include<iostream>
/*ѧУ������������Ŀ��ÿ����ʦ����5��ѧ�����ܹ���3����ʦ����������
���ѧ������ʦ�Ľṹ�壬��������ʦ�Ľṹ���У�����ʦ������һ�����5��ѧ����������Ϊ��Ա
ѧ���ĳ�Ա�����������Է���������������3����ʦ��ͨ��������ÿ����ʦ��������ѧ����ֵ
���մ�ӡ����ʦ�����Լ���ʦ������ѧ�����ݡ�*/
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
                cout << "�������" << i + 1 << "λ��ʦ�����ƣ�";
                cin >> teach[i].name;
            }
            cout << "�������" << i + 1 << "λ��ʦ" << "��" << j + 1 << "λѧ�������֣�";
            cin >> teach[i].stu[j].name;
            cout << "�������" << i + 1 << "λ��ʦ" << "��" << j + 1 << "λѧ���ĳɼ���";
            cin >> teach[i].stu[j].score;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        cout << "��ʦ" << teach[i].name << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "ѧ��" << teach[i].stu[j].name << "�ɼ�" << teach[i].stu[j].score << endl;
        }
    }
    return 0;
}