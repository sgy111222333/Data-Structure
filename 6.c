/*   ������������������ж������ģ�
��1������������2��Ҷ�ӽ�������
��3����ȣ���4���������С��������кͺ������С�
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
    TElemType data;              //������
    struct BTNode *left, *right; //���Һ���ָ��
} BTNode, *BTree;

void CreateBTree(BTree *T)
{
    *T = (BTNode *)malloc(sizeof(BTNode)); //��1��
    (*T)->data = 50;

    (*T)->left = (BTNode *)malloc(sizeof(BTNode)); //��2��
    (*T)->left->data = 30;
    (*T)->right = (BTNode *)malloc(sizeof(BTNode));
    (*T)->right->data = 80;
    (*T)->right->left = NULL;
    (*T)->left->right = NULL;

    (*T)->right->right = (BTNode *)malloc(sizeof(BTNode)); //��3��
    (*T)->right->right->data = 90;
    (*T)->right->right->right = NULL;
    (*T)->right->right->left = NULL;
    (*T)->left->left = (BTNode *)malloc(sizeof(BTNode));
    (*T)->left->left->data = 20;

    (*T)->left->left->left = (BTNode *)malloc(sizeof(BTNode)); //��4��
    (*T)->left->left->left->data = 10;
    (*T)->left->left->left->left = NULL;
    (*T)->left->left->left->right = NULL;
    (*T)->left->left->right = (BTNode *)malloc(sizeof(BTNode));
    (*T)->left->left->right->data = 25;
    (*T)->left->left->right->right = NULL;

    (*T)->left->left->right->left = (BTNode *)malloc(sizeof(BTNode)); //��5��
    (*T)->left->left->right->left->data = 23;
    (*T)->left->left->right->left->right = NULL;
    (*T)->left->left->right->left->left = NULL;
}

//��������
int Node(BTree T)
{
    if (T == NULL)
        return 0;
    int l = Node(T->left);
    int r = Node(T->right);
    return 1 + l + r;
}

//Ҷ�ӽ�������
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

//���
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

//ģ��������Ԫ�صĺ����������㱾�����ֵ
void display(BTNode *elem)
{
    printf("%d ", elem->data);
}

//�������
void PreOrderTraverse(BTree T)
{
    if (T)
    {
        display(T);                 //���ò���������ݵĺ�������
        PreOrderTraverse(T->left);  //���ʸý�������
        PreOrderTraverse(T->right); //���ʸý����Һ���
    }
    //������Ϊ�գ�������һ��
    return;
}

//�������
void INOrderTraverse(BTree T)
{
    if (T)
    {
        INOrderTraverse(T->left);  //��������
        display(T);                //���ò���������ݵĺ�������
        INOrderTraverse(T->right); //�����Һ���
    }
    //������Ϊ�գ�������һ��
    return;
}

//�������
void PostOrderTraverse(BTree T)
{
    if (T)
    {
        PostOrderTraverse(T->left);  //��������
        PostOrderTraverse(T->right); //�����Һ���
        display(T);                  //���ò���������ݵĺ�������
    }
    //������Ϊ�գ�������һ��
    return;
}

int main()
{
    BTree T;
    CreateBTree(&T);
    printf("%d\n", T->left->data);

    int size = Node(T);
    printf("�ڵ����:%d\n", size);

    int leaf = Leaf(T); //����
    printf("Ҷ�ӽڵ����:%d\n", leaf);

    int height = Height(T);
    printf("���:%d\n", height);

    printf("�������:");
    PreOrderTraverse(T);

    printf("\n�������:");
    INOrderTraverse(T);

    printf("\n�������:");
    PostOrderTraverse(T);

    return 0;
}