#include <iostream>
using namespace std;

typedef int KeyType;
typedef struct
{
    KeyType key;
} ElemType;

// 二叉排序树结点结构
typedef struct BSTNode
{
    ElemType data;
    struct BSTNode *lchild, *rchild;
} BSTNode, *BSTree;

// 插入结点（递归）
void InsertBST(BSTree &T, ElemType e)
{
    if (!T)
    {
        BSTree S = new BSTNode;
        S->data = e;
        S->lchild = S->rchild = NULL;
        T = S;
    }
    else if (e.key < T->data.key)
        InsertBST(T->lchild, e);
    else if (e.key > T->data.key)
        InsertBST(T->rchild, e);
}

// 创建二叉排序树
void CreateBST(BSTree &T, int arr[], int n)
{
    T = NULL;
    ElemType e;
    for (int i = 0; i < n; i++)
    {
        e.key = arr[i];
        InsertBST(T, e);
    }
}

// 中序遍历（二叉排序树中序有序）
void InOrder(BSTree T)
{
    if (T)
    {
        InOrder(T->lchild);
        cout << T->data.key << " ";
        InOrder(T->rchild);
    }
}

// 删除指定关键字结点
void DeleteBST(BSTree &T, int key)
{
    BSTree p = T, f = NULL;
    BSTree q, s;

    // 查找待删结点 p，f为p的双亲
    while (p)
    {
        if (p->data.key == key)
            break;
        f = p;
        if (key < p->data.key)
            p = p->lchild;
        else
            p = p->rchild;
    }
    if (!p)
        return; // 未找到结点

    // 情况1：左右子树都不为空（双支结点）
    if (p->lchild && p->rchild)
    {
        q = p;
        s = p->lchild;
        // 找左子树最右下结点（前驱）
        while (s->rchild)
        {
            q = s;
            s = s->rchild;
        }
        p->data = s->data;
        if (q != p)
            q->rchild = s->lchild;
        else
            q->lchild = s->lchild;
        delete s;
    }
    // 情况2：单支/叶子结点
    else
    {
        q = p;
        if (!p->rchild) // 无右孩子
            p = p->lchild;
        else // 无左孩子
            p = p->rchild;

        // 修改双亲指针
        if (!f)
            T = p;
        else if (q == f->lchild)
            f->lchild = p;
        else
            f->rchild = p;
        delete q;
    }
}

int main()
{
    // 班级姓名
    cout << "===== 班级：XXX 姓名：XXX 二叉排序树实验 =====" << endl;
    BSTree T;
    // 原始序列：45,24,53,12,37,93
    int arr[] = {45, 24, 53, 12, 37, 93};
    int n = sizeof(arr) / sizeof(arr[0]);

    // 1. 创建二叉排序树，输出中序
    CreateBST(T, arr, n);
    cout << "初始二叉排序树 中序遍历：";
    InOrder(T);
    cout << endl;

    // 2. 插入 13，输出中序
    ElemType e;
    e.key = 13;
    InsertBST(T, e);
    cout << "插入 13 后中序遍历：";
    InOrder(T);
    cout << endl;

    // 3. 删除 53，输出中序
    DeleteBST(T, 53);
    cout << "删除 53 后中序遍历：";
    InOrder(T);
    cout << endl;

    // 4. 删除 24，输出中序
    DeleteBST(T, 24);
    cout << "删除 24 后中序遍历：";
    InOrder(T);
    cout << endl;

    return 0;
}