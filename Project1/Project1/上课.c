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
        printf("请输入一个0~10的整数：");
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
            printf("恭喜你猜中了！\n");
            printf("这次你猜了%d次。\n", times);
            break;
        case 1:
            printf("大了！\n");
            break;
        case -1:
            printf("小了！\n");
            break;
        default:
            printf("请正确输入0~10的整数！\n");
        }
        if (result == 0)
        {
            while(1)
            {
                printf("还想再玩一次吗？(Y/N)");
                scanf("%*c%c", &play_again);
                if (play_again == 'Y' || play_again == 'y')
                {
                    times = 0;
                    number = rand() % 11;
                    break;
                }
                else if (play_again == 'N' || play_again == 'n')
                {
                    printf("感谢你的游玩。");
                    times = 999;
                    break;
                }
                else
                {
                    printf("请正确输入Y/N！\n");
                    play_again = 0;
                }
            }
        }
        
    }
    if (result != 0)
    {
        printf("很遗憾，你已耗光5次机会。");
    }
    return 0;
}  

