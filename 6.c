/*   建立二叉树并输出下列二叉树的：
（1）结点个数；（2）叶子结点个数；
（3）深度；（4）先序序列、中序序列和后序序列。
            50
        30      80
    20              90
10     25              
     23                                  */
#include <stdio.h>
#include <stdlib.h>
#define TElemType int

typedef struct BTNode
{
    TElemType data;              //数据域
    struct BTNode *left, *right; //左右孩子指针
} BTNode, *BTree;

void CreateBTree(BTree *T)
{
    *T = (BTNode *)malloc(sizeof(BTNode)); //第1层
    (*T)->data = 50;

    (*T)->left = (BTNode *)malloc(sizeof(BTNode)); //第2层
    (*T)->left->data = 30;
    (*T)->right = (BTNode *)malloc(sizeof(BTNode));
    (*T)->right->data = 80;
    (*T)->right->left = NULL;
    (*T)->left->right = NULL;

    (*T)->right->right = (BTNode *)malloc(sizeof(BTNode)); //第3层
    (*T)->right->right->data = 90;
    (*T)->right->right->right = NULL;
    (*T)->right->right->left = NULL;
    (*T)->left->left = (BTNode *)malloc(sizeof(BTNode));
    (*T)->left->left->data = 20;

    (*T)->left->left->left = (BTNode *)malloc(sizeof(BTNode)); //第4层
    (*T)->left->left->left->data = 10;
    (*T)->left->left->left->left = NULL;
    (*T)->left->left->left->right = NULL;
    (*T)->left->left->right = (BTNode *)malloc(sizeof(BTNode));
    (*T)->left->left->right->data = 25;
    (*T)->left->left->right->right = NULL;

    (*T)->left->left->right->left = (BTNode *)malloc(sizeof(BTNode)); //第5层
    (*T)->left->left->right->left->data = 23;
    (*T)->left->left->right->left->right = NULL;
    (*T)->left->left->right->left->left = NULL;
}

//结点个数；
int Node(BTree T)
{
    if (T == NULL)
        return 0;
    int l = Node(T->left);
    int r = Node(T->right);
    return 1 + l + r;
}

//叶子结点个数；
int Leaf(BTree T)
{
    int cnt = 0;
    if (T == NULL)
    {
        return 0;
    }
    if (T->left == NULL && T->right == NULL)
    {
        cnt++;
    }
    Leaf(T->left);
    Leaf(T->right);
    return cnt;
}

//深度
int Height(BTree T)
{
    int hlchild = 0, hrchild = 0;
    if (T == NULL)
        return 0;
    else
    {
        hlchild = Height(T->left);
        hrchild = Height(T->right);
        return (hlchild > hrchild) ? (hlchild + 1) : (hrchild + 1);
    }
}

//模拟操作结点元素的函数，输出结点本身的数值
void display(BTNode *elem)
{
    printf("%d ", elem->data);
}

//先序遍历
void PreOrderTraverse(BTree T)
{
    if (T)
    {
        display(T);                 //调用操作结点数据的函数方法
        PreOrderTraverse(T->left);  //访问该结点的左孩子
        PreOrderTraverse(T->right); //访问该结点的右孩子
    }
    //如果结点为空，返回上一层
    return;
}

//中序遍历
void INOrderTraverse(BTree T)
{
    if (T)
    {
        INOrderTraverse(T->left);  //遍历左孩子
        display(T);                //调用操作结点数据的函数方法
        INOrderTraverse(T->right); //遍历右孩子
    }
    //如果结点为空，返回上一层
    return;
}

//后序遍历
void PostOrderTraverse(BTree T)
{
    if (T)
    {
        PostOrderTraverse(T->left);  //遍历左孩子
        PostOrderTraverse(T->right); //遍历右孩子
        display(T);                  //调用操作结点数据的函数方法
    }
    //如果结点为空，返回上一层
    return;
}

int main()
{
    BTree T;
    CreateBTree(&T);
    printf("%d\n", T->left->data);

    int size = Node(T);
    printf("节点个数:%d\n", size);

    int leaf = Leaf(T); //有误
    printf("叶子节点个数:%d\n", leaf);

    int height = Height(T);
    printf("深度:%d\n", height);

    printf("先序遍历:");
    PreOrderTraverse(T);

    printf("\n中序遍历:");
    INOrderTraverse(T);

    printf("\n后序遍历:");
    PostOrderTraverse(T);

    return 0;
}