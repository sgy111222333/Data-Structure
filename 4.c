/*键盘输入目标串（主串）s、模式串（子串）t，编写程序，实现顺序串的BF模式匹配算法。
要求：匹配成功，输出位序，匹配不成功，显示相应提示信息。
例如：s=“aaaabcdcccc”，t=“abcd”。*/
#include <stdio.h>
#include <string.h>
//串普通模式匹配算法的实现函数，其中 B是伪主串，A是伪子串
int BFmate(char *B, char *A)
{
    int i = 0, j = 0;
    while (i < strlen(B) && j < strlen(A))
    {
        if (B[i] == A[j])
        {
            i++;
            j++;
        }
        else
        {
            i = i - j + 1;
            j = 0;
        }
    } 
    //跳出循环有两种可能:
    //i=strlen(B)说明已经遍历完主串，匹配失败；
    //j=strlen(A),说明子串遍历完成，在主串中成功匹配
    if (j == strlen(A))
    {
        return i - strlen(A) + 1;
    }
    //运行至此为i==strlen(B)
    return 0;
}

int main()
{
    char strB[20];
    char strA[20];
    printf("请输入主串:");
    scanf("%s",strB);
    printf("请输入子串:");
    scanf("%s",strA);
    int number=BFmate(strB,strA);
    if(number!=0)
        printf("匹配的第一个字符的下标为 %d\n", number);
    else
        printf("不匹配");
    return 0;
}

