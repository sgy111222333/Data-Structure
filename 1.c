//设计程序，输出所有小于等于n（n为一个大于2的正整数，比如100）的素数，要求：
//（1）每行输出10个素数；（2）尽可能采用较优算法。
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int main()
{
    printf("计算小于等于N的素数");
    printf("请输入大于1的整数N：");
    int N, s, i, j, sum;
    scanf("%d", &N);
    if (N <= 1)
    {
        printf("输入错误");
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
