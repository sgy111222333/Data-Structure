/*利用折半查找算法实现在数据序列{2,3,6,33,45,66,88,100}
  分别查找关键字6和89的结果，找到输出位序，找不到输出相应提示信息。*/
//在 2.顺序表 的基础上修改
#include <stdio.h>
#include <stdlib.h>
#define MAX 20

typedef struct xxb
{
    int *data;
    int length;

} SqList; // Sequential List 顺序表

//初始化
SqList init()
{
    SqList t;
    t.data = (int *)malloc(MAX * sizeof(int)); //构造一个空的顺序表，动态申请存储空间
    if (!t.data)                               //如果申请失败，作出提示并直接退出程序
    {
        printf("初始化失败");
        exit(0);
    }
    t.length = 0; //空表的长度初始化为0
    //t.max = MAX;  //空表的初始存储空间为Size
    return t;
}

//输出顺序表中的元素
void display(SqList t)
{
    for (int i = 0; i < t.length; i++)
    {
        printf("%d ", t.data[i]);
    }
    printf("\n");
}

//顺序查找，X表示要查找的值
int select(SqList t, int X)
{
    for (int i = 0; i < t.length; i++)
    {
        if (t.data[i] == X)
            return (i + 1); //返回该值的序号
    }
    return (-1); //查找失败
}

int binary_search(SqList t, int key)
{

    int low = 1;         //初始状态 low 指针指向第一个关键字
    int high = t.length; //high 指向最后一个关键字
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2; //int 本身为整形，所以 mid 每次为取整的整数
        if (t.data[mid] == key) //如果 mid 指向的同要查找的相等，返回 mid 所指向的位置
        {
            return mid;
        }
        else if (t.data[mid] > key) //如果mid指向的关键字较大，则更新 high 指针的位置
        {
            high = mid - 1;
        }
        //反之，则更新 low 指针的位置
        else
        {
            low = mid + 1;
        }
    }
    return 0;
}

int main()
{
    SqList t = init(); //顺序表初始化
    int a[8] = {2, 3, 6, 33, 45, 66, 88, 100};
    //将数组填入顺序表
    for (int i = 0; i < 8; i++)
    {
        t.data[i] = a[i];
        t.length++;
    }

    printf("顺序表中的所有元素：\n");
    display(t);

    //顺序查找,用于检验二分查找
    int elem;
    printf("请输入要顺序查找的数值：\n");
    scanf("%d", &elem);
    if (select(t, elem) == -1)
        printf("未找到\n");
    else
        printf("该数据在第%d个\n", select(t, elem));

    //二分查找
    printf("请输入要二分查找的数值:");
    int k;
    scanf("%d", &k);
    printf("该数据在第%d个\n", binary_search(t, k) + 1);
    return 0;
}