//��Ƴ����������С�ڵ���n��nΪһ������2��������������100����������Ҫ��
//��1��ÿ�����10����������2�������ܲ��ý����㷨��
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("����С�ڵ���N������");
    printf("���������1������N��");
    int N, s, i, j, sum;
    scanf("%d", &N);
    if (N <= 1)
    {
        printf("�������");
        exit(1);
    }
    for (i = 2; i <= N; i++)
    {
        s = sqrt(i);
        for (j = 2; j <= s; j++)
            if (i % j == 0)
                break;
        if (j == s + 1)
        {
            printf("%-4d ", i);
            sum++;
            if(sum%10==0)
                printf("\n");
        }
    }
    return 0;
}
