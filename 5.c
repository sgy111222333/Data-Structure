/*����Ԫ��洢����ʵ�־���ת�ã�Ҫ��
���ת��ǰ��������Ԫ��˳���
1 0 0 0 8           1  0  3        
0 0 0 0 4    -->    0  0  0  
3 0 0 0 0           0  0  0
                    0  0  0
                    8  4  0          */
#include <stdio.h>
#define number 4
typedef struct
{
    int i, j; //�б�,�б�
    int data; //Ԫ����ֵ
} triple;

typedef struct
{
    triple data[number];
    int n, m, num; //n:�� m:��
} TSMatrix;

void display(TSMatrix M);               //��ʾϡ�����
void show(TSMatrix M);                  //��ʾ��Ԫ��
TSMatrix trans(TSMatrix M, TSMatrix T); //ת��

int main()
{
    TSMatrix M;
    TSMatrix T;
    M.m = 5; //m��
    M.n = 3; //n��
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
    printf("ת��ǰ����:\n");
    display(M);
    printf("ת��ǰ��Ԫ��:\n");
    show(M);
    T = trans(M, T); //ת��
    printf("ת�ú����:\n");
    display(T);
    printf("ת�ú���Ԫ��:\n");
    show(T);
    return 0;
}

void show(TSMatrix M) //��ʾ��Ԫ��
{
    for (int x = 0; x < number; x++)
    {
        printf("(%d %d %d)\n", M.data[x].i, M.data[x].j, M.data[x].data);
    }
}

void display(TSMatrix M) //��ʾ����
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