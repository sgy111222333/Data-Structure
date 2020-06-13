/*用三元组存储矩阵并实现矩阵转置，要求：
输出转置前后矩阵的三元组顺序表。
1 0 0 0 8           1  0  3        
0 0 0 0 4    -->    0  0  0  
3 0 0 0 0           0  0  0
                    0  0  0
                    8  4  0          */
#include <stdio.h>
#define number 4
typedef struct
{
    int i, j; //行标,列标
    int data; //元素数值
} triple;

typedef struct
{
    triple data[number];
    int n, m, num; //n:行 m:列
} TSMatrix;

void display(TSMatrix M);               //显示稀疏矩阵
void show(TSMatrix M);                  //显示三元组
TSMatrix trans(TSMatrix M, TSMatrix T); //转置

int main()
{
    TSMatrix M;
    TSMatrix T;
    M.m = 5; //m列
    M.n = 3; //n行
    M.num = number;
    M.data[0].i = 1;
    M.data[0].j = 1;
    M.data[0].data = 1;
    M.data[1].i = 1;
    M.data[1].j = 5;
    M.data[1].data = 8;
    M.data[2].i = 2;
    M.data[2].j = 5;
    M.data[2].data = 4;
    M.data[3].i = 3;
    M.data[3].j = 1;
    M.data[3].data = 3;
    printf("转置前矩阵:\n");
    display(M);
    printf("转置前三元组:\n");
    show(M);
    T = trans(M, T); //转置
    printf("转置后矩阵:\n");
    display(T);
    printf("转置后三元组:\n");
    show(T);
    return 0;
}

void show(TSMatrix M) //显示三元组
{
    for (int x = 0; x < number; x++)
    {
        printf("(%d %d %d)\n", M.data[x].i, M.data[x].j, M.data[x].data);
    }
}

void display(TSMatrix M) //显示矩阵
{
    for (int i = 1; i <= M.n; i++)
    {
        for (int j = 1; j <= M.m; j++)
        {
            int value = 0;
            for (int k = 0; k < M.num; k++)
            {
                if (i == M.data[k].i && j == M.data[k].j)
                {
                    printf("%d ", M.data[k].data);
                    value = 1;
                    break;
                }
            }
            if (value == 0)
                printf("0 ");
        }
        printf("\n");
    }
}

TSMatrix trans(TSMatrix M, TSMatrix T)
{
    T.m = M.n;
    T.n = M.m;
    T.num = M.num;
    if (T.num)
    {
        int q = 0;
        for (int col = 1; col <= M.m; col++)
        {
            for (int p = 0; p < M.num; p++)
            {
                if (M.data[p].j == col)
                {
                    T.data[q].i = M.data[p].j;
                    T.data[q].j = M.data[p].i;
                    T.data[q].data = M.data[p].data;
                    q++;
                }
            }
        }
    }
    return T;
}