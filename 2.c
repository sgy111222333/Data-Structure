/*建立顺序表存储数据序列（10，20，30，40，50，60，70，80，90,100），要求：
（1）输出顺序表中的所有元素；
（2）输出顺序表中的最大值和最小值；
（3）键盘输入一个数x，如x在表中返回其在表中的位序，不在返回相应提示信息。
（4）删除顺序表中的第8个元素，并输出顺序表中的所有元素；
（5）在第5个元素后面插入新元素55，并输出顺序表中的所有元素；
（6）输出顺序表的长度。
（要求尽量将每一个操作模块化，建议将顺序表设置成全局。）*/
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

//更改数值，X为要改的数值，Y为修改后的数值
SqList change(SqList t, int X, int Y)
{
    int num = select(t, X);
    t.data[num - 1] = Y; //由于返回的是元素在顺序表中的位置，所以-1就是该元素在数组中的下标
    return t;
}

//输出最大值和最小值
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
    printf("最大值：%d\n", max);
    printf("最小值：%d\n", min);
}

//根据位置 删除元素 d为序号
SqList delete (SqList t, int d)
{
    if (d > t.length || d < 1)
    {
        printf("位置不对");
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

//插入数据 该数据将出现在第num个
SqList add(SqList t, int X, int num)
{
    if (num > t.length + 1 || num < 1)
    {
        printf("序号有误");
        exit(0);
    }
    if (t.length == MAX)
        printf("此表已满，上限为%d\n", MAX);
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
    } //添加10 20 30到100
    printf("顺序表中的所有元素：\n");
    display(t);
    printf("输出最大值和最小值：\n");
    minmax(t);
    int elem;
    printf("请输入要查找的数据：\n");
    scanf("%d", &elem);
    if (select(t, elem) == -1)
        printf("未找到\n");
    else
        printf("该数据在第%d个\n", select(t, elem));
    printf("删除第8个数据：\n");
    delete (t, 8);
    t.length--;
    display(t);
    printf("在第5个数后面添加55：\n");
    add(t, 55, 6);
    t.length++;
    display(t);
    printf("顺序表的长度：\n");
    printf("%d\n",t.length);
    return 0;
}