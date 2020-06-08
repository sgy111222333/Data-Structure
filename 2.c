/*����˳���洢�������У�10��20��30��40��50��60��70��80��90,100����Ҫ��
��1�����˳����е�����Ԫ�أ�
��2�����˳����е����ֵ����Сֵ��
��3����������һ����x����x�ڱ��з������ڱ��е�λ�򣬲��ڷ�����Ӧ��ʾ��Ϣ��
��4��ɾ��˳����еĵ�8��Ԫ�أ������˳����е�����Ԫ�أ�
��5���ڵ�5��Ԫ�غ��������Ԫ��55�������˳����е�����Ԫ�أ�
��6�����˳���ĳ��ȡ�
��Ҫ������ÿһ������ģ�黯�����齫˳������ó�ȫ�֡���*/
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct xxb
{
    int *data;
    int length;

} SqList; // Sequential List ˳���

//��ʼ��
SqList init()
{
    SqList t;
    t.data = (int *)malloc(MAX * sizeof(int)); //����һ���յ�˳�����̬����洢�ռ�
    if (!t.data)                               //�������ʧ�ܣ�������ʾ��ֱ���˳�����
    {
        printf("��ʼ��ʧ��");
        exit(0);
    }
    t.length = 0; //�ձ�ĳ��ȳ�ʼ��Ϊ0
    //t.max = MAX;  //�ձ�ĳ�ʼ�洢�ռ�ΪSize
    return t;
}

//���˳����е�Ԫ��
void display(SqList t)
{
    for (int i = 0; i < t.length; i++)
    {
        printf("%d ", t.data[i]);
    }
    printf("\n");
}

//˳����ң�X��ʾҪ���ҵ�ֵ
int select(SqList t, int X)
{
    for (int i = 0; i < t.length; i++)
    {
        if (t.data[i] == X)
            return (i + 1); //���ظ�ֵ�����
    }
    return (-1); //����ʧ��
}

//������ֵ��XΪҪ�ĵ���ֵ��YΪ�޸ĺ����ֵ
SqList change(SqList t, int X, int Y)
{
    int num = select(t, X);
    t.data[num - 1] = Y; //���ڷ��ص���Ԫ����˳����е�λ�ã�����-1���Ǹ�Ԫ���������е��±�
    return t;
}

//������ֵ����Сֵ
SqList minmax(SqList t)
{
    int min = t.data[0];
    for (int i = 0; i < t.length; i++)
    {
        if (min > t.data[i])
            min = t.data[i];
    }
    int max = t.data[0];
    for (int j = 0; j < t.length; j++)
    {
        if (max < t.data[j])
            max = t.data[j];
    }
    printf("���ֵ��%d\n", max);
    printf("��Сֵ��%d\n", min);
}

//����λ�� ɾ��Ԫ�� dΪ���
SqList delete (SqList t, int d)
{
    if (d > t.length || d < 1)
    {
        printf("λ�ò���");
        exit(0);
    }
    for (int i = d; i < t.length; i++)
    {
        t.data[i - 1] = t.data[i];
    }
    t.length--;
    // printf("%d\n",t.length);
    return t;
}

//�������� �����ݽ������ڵ�num��
SqList add(SqList t, int X, int num)
{
    if (num > t.length + 1 || num < 1)
    {
        printf("�������");
        exit(0);
    }
    if (t.length == MAX)
        printf("�˱�����������Ϊ%d\n", MAX);
    for (int i = t.length - 1; i >= num - 1; i--)
        t.data[i + 1] = t.data[i];
    t.data[num - 1] = X;
    //t.length++; 
    return t;
}

int main()
{
    SqList t = init();
    for (int i = 1; i <= 10; i++)
    {
        t.data[i - 1] = 10 * i;
        t.length++;
    } //���10 20 30��100
    printf("˳����е�����Ԫ�أ�\n");
    display(t);
    printf("������ֵ����Сֵ��\n");
    minmax(t);
    int elem;
    printf("������Ҫ���ҵ����ݣ�\n");
    scanf("%d", &elem);
    if (select(t, elem) == -1)
        printf("δ�ҵ�\n");
    else
        printf("�������ڵ�%d��\n", select(t, elem));
    printf("ɾ����8�����ݣ�\n");
    delete (t, 8);
    t.length--;
    display(t);
    printf("�ڵ�5�����������55��\n");
    add(t, 55, 6);
    t.length++;
    display(t);
    printf("˳���ĳ��ȣ�\n");
    printf("%d\n",t.length);
    return 0;
}