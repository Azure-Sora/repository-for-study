#include <stdio.h>
#include <string.h>
void get_INfo(char(*str)[20], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("请输入第%d个人的名字：", i + 1);
        gets(str[i]);
    }
}
void sort_Array(char(*str)[20], int n)
{
    char temp[20];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (strcmp(str[j], str[j + 1]) > 0)
            {
                strcpy(temp, str[j]);
                strcpy(str[j], str[j + 1]);
                strcpy(str[j + 1], temp);
            }
        }
    }
}
int bin_Find(char(*str)[20], int n, char name[])
{
    int left, mid, right;
    left = 0;
    right = n - 1;
    mid = (left + right) / 2;
    while (left != right)
    {
        if (strcmp(str[mid], name) == 0)
        {
            return mid;
        }
        else if (strcmp(str[mid], name) > 0)
        {
            right = mid;
        }
        else if (strcmp(str[mid], name) < 0)
        {
            left = mid;
        }
        mid = (left + right) / 2;

    }
    return 999;
}
int main()
{
    char name[10][20];
    char lookfor[20];
    int index;
    get_INfo(name, 10);
    sort_Array(name, 10);
    printf("排序后：\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%s\n", name[i]);
    }
    printf("请输入要查找的名字：");
    gets(lookfor);
    index = bin_Find(name, 10, lookfor);
    printf("查找到名字：%s", name[index]);
    return 0;
}
