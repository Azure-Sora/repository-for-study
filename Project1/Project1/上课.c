#include<stdio.h>
#include<stdlib.h>
#include <time.h>

int main()
{
    srand(time(0));
    char c = 0;
    int times = 0;
    int number = 0;
    int result = 0;
    int input = 999;
    char play_again = 0;
    number = rand() % 11;
    while (times < 5)
    {
        if (result != 999)
        {
            times++;
        }
        input = 0;
        printf("������һ��0~10��������");
        scanf("%d", &input);
        if (input == number)
        {
            result = 0;
        }
        else if (input > number && input <= 10)
        {
            result = 1;
        }
        else if (input < number && input >= 0)
        {
            result = -1;
        }
        else
        {
            result = 999;
        }
        switch (result)
        {
        case 0 :
            printf("��ϲ������ˣ�\n");
            printf("��������%d�Ρ�\n", times);
            break;
        case 1:
            printf("���ˣ�\n");
            break;
        case -1:
            printf("С�ˣ�\n");
            break;
        default:
            printf("����ȷ����0~10��������\n");
        }
        if (result == 0)
        {
            while(1)
            {
                printf("��������һ����(Y/N)");
                scanf("%*c%c", &play_again);
                if (play_again == 'Y' || play_again == 'y')
                {
                    times = 0;
                    number = rand() % 11;
                    break;
                }
                else if (play_again == 'N' || play_again == 'n')
                {
                    printf("��л������档");
                    times = 999;
                    break;
                }
                else
                {
                    printf("����ȷ����Y/N��\n");
                    play_again = 0;
                }
            }
        }
        
    }
    if (result != 0)
    {
        printf("���ź������ѺĹ�5�λ��ᡣ");
    }
    return 0;
}  

