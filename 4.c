/*��������Ŀ�괮��������s��ģʽ�����Ӵ���t����д����ʵ��˳�򴮵�BFģʽƥ���㷨��
Ҫ��ƥ��ɹ������λ��ƥ�䲻�ɹ�����ʾ��Ӧ��ʾ��Ϣ��
���磺s=��aaaabcdcccc����t=��abcd����*/
#include <stdio.h>
#include <string.h>
//����ͨģʽƥ���㷨��ʵ�ֺ��������� B��α������A��α�Ӵ�
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
    //����ѭ�������ֿ���:
    //i=strlen(B)˵���Ѿ�������������ƥ��ʧ�ܣ�
    //j=strlen(A),˵���Ӵ�������ɣ��������гɹ�ƥ��
    if (j == strlen(A))
    {
        return i - strlen(A) + 1;
    }
    //��������Ϊi==strlen(B)
    return 0;
}

int main()
{
    char strB[20];
    char strA[20];
    printf("����������:");
    scanf("%s",strB);
    printf("�������Ӵ�:");
    scanf("%s",strA);
    int number=BFmate(strB,strA);
    if(number!=0)
        printf("ƥ��ĵ�һ���ַ����±�Ϊ %d\n", number);
    else
        printf("��ƥ��");
    return 0;
}

