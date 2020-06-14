/*�����۰�����㷨ʵ������������{2,3,6,33,45,66,88,100}
  �ֱ���ҹؼ���6��89�Ľ�����ҵ����λ���Ҳ��������Ӧ��ʾ��Ϣ��*/
//�� 2.˳��� �Ļ������޸�
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

int binary_search(SqList t, int key)
{

    int low = 1;         //��ʼ״̬ low ָ��ָ���һ���ؼ���
    int high = t.length; //high ָ�����һ���ؼ���
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2; //int ����Ϊ���Σ����� mid ÿ��Ϊȡ��������
        if (t.data[mid] == key) //��� mid ָ���ͬҪ���ҵ���ȣ����� mid ��ָ���λ��
        {
            return mid;
        }
        else if (t.data[mid] > key) //���midָ��Ĺؼ��ֽϴ������ high ָ���λ��
        {
            high = mid - 1;
        }
        //��֮������� low ָ���λ��
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

int main()
{
    SqList t = init(); //˳����ʼ��
    int a[8] = {2, 3, 6, 33, 45, 66, 88, 100};
    //����������˳���
    for (int i = 0; i < 8; i++)
    {
        t.data[i] = a[i];
        t.length++;
    }

    printf("˳����е�����Ԫ�أ�\n");
    display(t);

    //˳�����,���ڼ�����ֲ���
    int elem;
    printf("������Ҫ˳����ҵ���ֵ��\n");
    scanf("%d", &elem);
    if (select(t, elem) == -1)
        printf("δ�ҵ�\n");
    else
        printf("�������ڵ�%d��\n", select(t, elem));

    //���ֲ���
    printf("������Ҫ���ֲ��ҵ���ֵ:");
    int k;
    scanf("%d", &k);
    printf("�������ڵ�%d��\n", binary_search(t, k) + 1);
    return 0;
}