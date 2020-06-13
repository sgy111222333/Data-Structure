/*建立单链表存储数据（10，20，30，40，50，60，70，80，90,100），要求：
（1）头插法或尾插法建立单链表，并输出单链表中所有元素；
（2）输出单链表中的最大值和最小值；
（3）键盘输入一个值x，输出链表中第一个值为x的元素的位序；
（4）键盘输入一位序值b，在第b个元素之前插入值为500的元素，输出链表中的所有数据；
（5）键盘输入位序值m，删除位序为m的元素，输出链表中的所有数据；
（6）输出单链表的长度。
（要求尽量将每一个操作模块化，建议将链表头指针设置成全局变量。）*/
#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int data;          //数据域
    struct node *next; //指针域
} LNode, *Linklist;

LNode *init()
{
    LNode *p = (LNode *)malloc(sizeof(LNode)); //创建一个头结点
    LNode *temp = p;                           //声明一个指针指向头结点，用于遍历链表
    //生成链表
    for (int i = 10; i <= 100; i += 10)
    {
        LNode *a = (LNode *)malloc(sizeof(LNode));
        a->data = i;
        a->next = NULL;
        //将temp节点与新建立的a节点建立逻辑关系
        temp->next = a;
        //指针temp每次都指向新链表的最后一个节点，其实就是a节点，相当于temp=a
        temp = temp->next;
    }
    return p;
}

void Display(LNode *p)
{
    LNode *temp = p; //将temp指针重新指向头结点
    //只要temp指针指向的结点的next不是Null，就执行输出语句。
    while (temp->next)
    {
        temp = temp->next;
        printf("%d ", temp->data);
    }
    printf("\n");
}

//插入 p为原链表,X表示新的数据元素,add表示插入的位置
LNode *insert(LNode *p, int X, int b)
{
    LNode *temp = p; //创建临时结点temp
    //首先找到要插入位置的上一个结点
    for (int i = 1; i < b; i++)
    {
        if (temp == NULL)
        {
            printf("插入位置无效\n");
            return p;
        }
        temp = temp->next;
    }
    //创建插入节点c
    LNode *c = (LNode *)malloc(sizeof(LNode));
    c->data = X;
    //向链表中插入结点
    c->next = temp->next;
    temp->next = c;
    return p;
}

//删除位置为add的元素
LNode *delete (LNode *p, int m)
{
    LNode *temp = p;
    //遍历到被删除结点的上一个结点
    for (int i = 1; i < m; i++)
        temp = temp->next;
    //LNode * del=temp->next;//单独设置一个指针指向被删除结点，以防丢失
    temp->next = temp->next->next; //删除某个结点的方法就是更改前一个结点的指针域
    //free(del);//手动释放该结点，防止内存泄漏
    return p;
}

//修改 将第n个元素改为X
LNode *change(LNode *p, int n, int X)
{
    LNode *temp = p;
    temp = temp->next; //在遍历之前，temp指向首元结点
    //遍历到被删除结点
    for (int i = 1; i < n; i++)
    {
        temp = temp->next;
    }
    temp->data = X;
    return p;
}

//查找元素所在位置
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

//求最大最小值
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
    printf("最大值为%d\n最小值为%d\n", max, min);
}

//输出链表长度
void length(LNode *p)
{
    LNode *temp = p;
    int num = 0;
    while (temp->next != NULL)
    {
        temp = temp->next;
        num++;
    }
    printf("链表长度:%d\n", num);
}

int main()
{
    int X, m, n;
    printf("初始化链表为:\n");
    LNode *p = init();
    Display(p);

    minmax(p);

    printf("查找X所在位置,请输入X:");
    scanf("%d", &X);
    int address = select(p, X);
    if (address == -1)
        printf("该元素不存在\n");
    else
        printf("%d所在位置:%d\n", X, address);

    printf("在b的位置插入500,请输入b:");
    int b;
    scanf("%d", &b);
    p = insert(p, 500, b);
    printf("插入后的链表为:\n");
    Display(p);

    printf("删除第m个元素,请输入m:");
    scanf("%d", &m);
    p = delete (p, m);
    printf("删除后的链表为:\n");
    Display(p);

    printf("将第n个元素改为X,请输入n和X:");
    scanf("%d %d", &n, &X);
    p = change(p, n, X);
    printf("修改后的链表为:\n");
    Display(p);

    length(p);
    return 0;
}
