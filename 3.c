/*����������洢���ݣ�10��20��30��40��50��60��70��80��90,100����Ҫ��
��1��ͷ�巨��β�巨���������������������������Ԫ�أ�
��2������������е����ֵ����Сֵ��
��3����������һ��ֵx����������е�һ��ֵΪx��Ԫ�ص�λ��
��4����������һλ��ֵb���ڵ�b��Ԫ��֮ǰ����ֵΪ500��Ԫ�أ���������е��������ݣ�
��5����������λ��ֵm��ɾ��λ��Ϊm��Ԫ�أ���������е��������ݣ�
��6�����������ĳ��ȡ�
��Ҫ������ÿһ������ģ�黯�����齫����ͷָ�����ó�ȫ�ֱ�������*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          //������
    struct node *next; //ָ����
} LNode, *Linklist;

LNode *init()
{
    LNode *p = (LNode *)malloc(sizeof(LNode)); //����һ��ͷ���
    LNode *temp = p;                           //����һ��ָ��ָ��ͷ��㣬���ڱ�������
    //��������
    for (int i = 10; i <= 100; i += 10)
    {
        LNode *a = (LNode *)malloc(sizeof(LNode));
        a->data = i;
        a->next = NULL;
        //��temp�ڵ����½�����a�ڵ㽨���߼���ϵ
        temp->next = a;
        //ָ��tempÿ�ζ�ָ������������һ���ڵ㣬��ʵ����a�ڵ㣬�൱��temp=a
        temp = temp->next;
    }
    return p;
}

void Display(LNode *p)
{
    LNode *temp = p; //��tempָ������ָ��ͷ���
    //ֻҪtempָ��ָ��Ľ���next����Null����ִ�������䡣
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

//���� pΪԭ����,X��ʾ�µ�����Ԫ��,add��ʾ�����λ��
LNode *insert(LNode *p, int X, int b)
{
    LNode *temp = p; //������ʱ���temp
    //�����ҵ�Ҫ����λ�õ���һ�����
    for (int i = 1; i < b; i++)
    {
        if (temp == NULL)
        {
            printf("����λ����Ч\n");
            return p;
        }
        temp = temp->next;
    }
    //��������ڵ�c
    LNode *c = (LNode *)malloc(sizeof(LNode));
    c->data = X;
    //�������в�����
    c->next = temp->next;
    temp->next = c;
    return p;
}

//ɾ��λ��Ϊadd��Ԫ��
LNode *delete (LNode *p, int m)
{
    LNode *temp = p;
    //��������ɾ��������һ�����
    for (int i = 1; i < m; i++)
        temp = temp->next;
    //LNode * del=temp->next;//��������һ��ָ��ָ��ɾ����㣬�Է���ʧ
    temp->next = temp->next->next; //ɾ��ĳ�����ķ������Ǹ���ǰһ������ָ����
    //free(del);//�ֶ��ͷŸý�㣬��ֹ�ڴ�й©
    return p;
}

//�޸� ����n��Ԫ�ظ�ΪX
LNode *change(LNode *p, int n, int X)
{
    LNode *temp = p;
    temp = temp->next; //�ڱ���֮ǰ��tempָ����Ԫ���
    //��������ɾ�����
    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
    }
    temp->data = X;
    return p;
}

//����Ԫ������λ��
int select(LNode *p, int X)
{
    LNode *t = p;
    int i = 1;
    while (t->next)
    {
        t = t->next;
        if (t->data == X)
            return i;
        i++;
    }
    return -1;
}

//�������Сֵ
void minmax(LNode *p)
{
    LNode *temp = p;
    int min, max;
    max = min = temp->next->data;
    while (temp->next != NULL)
    {
        temp = temp->next;
        min = min > temp->data ? temp->data : min;
        max = max < temp->data ? temp->data : max;
    }
    printf("���ֵΪ%d\n��СֵΪ%d\n", max, min);
}

//���������
void length(LNode *p)
{
    LNode *temp = p;
    int num = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        num++;
    }
    printf("������:%d\n", num);
}

int main()
{
    int X, m, n;
    printf("��ʼ������Ϊ:\n");
    LNode *p = init();
    Display(p);

    minmax(p);

    printf("����X����λ��,������X:");
    scanf("%d", &X);
    int address = select(p, X);
    if (address == -1)
        printf("��Ԫ�ز�����\n");
    else
        printf("%d����λ��:%d\n", X, address);

    printf("��b��λ�ò���500,������b:");
    int b;
    scanf("%d", &b);
    p = insert(p, 500, b);
    printf("����������Ϊ:\n");
    Display(p);

    printf("ɾ����m��Ԫ��,������m:");
    scanf("%d", &m);
    p = delete (p, m);
    printf("ɾ���������Ϊ:\n");
    Display(p);

    printf("����n��Ԫ�ظ�ΪX,������n��X:");
    scanf("%d %d", &n, &X);
    p = change(p, n, X);
    printf("�޸ĺ������Ϊ:\n");
    Display(p);

    length(p);
    return 0;
}
