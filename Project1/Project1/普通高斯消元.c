#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define MAX 10

double A[MAX][MAX];
double b[MAX];
double X[MAX];
int NUM;

void Input_Matrix()//输入矩阵
{
    int i, j;
    printf("系数矩阵A的阶数:\n");
    scanf("%d", &NUM);
    for (i = 1; i <= NUM; i++)
    {
        printf("系数矩阵A的第%d行元素:\n", i);
        for (j = 1; j <= NUM; j++)
            scanf("%lf", &A[i - 1][j - 1]);
    }
    printf("右端项b:\n");
    for (i = 1; i <= NUM; i++)
    {
        scanf("%lf", &b[i - 1]);
    }
    printf("输入的系数矩阵A:\n");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < NUM; j++)
            printf("%lf\t", A[i][j]);
        printf("\n");
    }
    printf("输入的右端项b:\n");
    printf("增广矩阵[A,b]:\n");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < NUM; j++)
            printf("%.4lf\t", A[i][j]);
        printf("%lf\t", b[i]);
        printf("\n");
    }
    printf("\n");
}

void Gauss()
{
    int i, j, k, column;
    double max, A_temp, b_temp, mik, sum;
    for (k = 0; k < NUM - 1; k++)
    {
        
        for (i = k + 1; i < NUM; i++)//消元过程
        {
            mik = A[i][k] / A[k][k];
            for (j = k; j < NUM; j++)
                A[i][j] -= mik * A[k][j];
            b[i] -= mik * b[k];
        }

    }
    printf("消元后的矩阵:\n");
    for (i = 0; i < NUM; i++)
    {
        for (j = 0; j < NUM; j++)
            printf("%lf\t", A[i][j]);
        printf("%lf\t", b[i]);
        printf("\n");
    }
    printf("\n");
    X[NUM - 1] = b[NUM - 1] / A[NUM - 1][NUM - 1];
    for (i = NUM - 2; i >= 0; i--)
    {
        sum = 0;
        for (j = i + 1; j < NUM; j++)
            sum += A[i][j] * X[j];
        X[i] = (b[i] - sum) / A[i][i];
    }

}

int main()
{
    Input_Matrix();
    clock_t begin, end;
	double cost;
	//开始记录
	begin = clock();

	  Gauss();
    
	//结束记录
	end = clock();
	cost = (double)(end - begin)/CLOCKS_PER_SEC;
	printf("time cost is: %lf ", cost);

    printf("结果X:\n");
    for (int i = 0; i < NUM; i++)
    {
        printf("%lf\n", X[i]);
    }
    return 0;
}
