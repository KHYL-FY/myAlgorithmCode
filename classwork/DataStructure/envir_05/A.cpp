#include <iostream>

using namespace std;

class BiTree
{
#define OVERFLOW -1
#define OK 1
    typedef char Elemtype;
    typedef int exceptType;
    char end_ = '#';

    struct node
    {
        Elemtype data;
        node *lchild, *rchild;
    };

private:
    node *root;
    int depth = -1;
    int leafs = -1;
    int degree_2count = -1;
    // void exit(exceptType type)
    // {
    // }

    void creat(node *&t)
    {
        char ch;
        cin >> ch;
        if (ch == end_)
        {
            t = NULL;
        }
        else
        {
            if (!(t = new node))
            {
                // exit(OVERFLOW);
                return;
            }
            t->data = ch;
            creat(t->lchild);
            creat(t->rchild);
        }
    }
    void inOrder(node *t)
    {
        if (t == NULL)
            return;
        if (t)
        {

            inOrder(t->lchild);
            cout << t->data;
            inOrder(t->rchild);
        }
    }
    void postOrder(node *t)
    {
        if (t == NULL)
            return;
        if (t)
        {

            postOrder(t->lchild);
            postOrder(t->rchild);
            cout << t->data;
        }
    }
    int deep_(node *t, int d = 0)
    {
        if (t == NULL)
            return d;
        else
        {
            // depth = max(deep_(t->lchild, d + 1), depth);
            // depth = max(deep_(t->rchild, d + 1), depth);

            return max(deep_(t->lchild, d + 1), deep_(t->rchild, d + 1));
        }
    }
    int _LeafCount(node *t)
    {
        if (t == NULL)
            return 0;

        if (t->lchild == NULL && t->rchild == NULL)
            return 1;

        else
            return _LeafCount(t->lchild) + _LeafCount(t->rchild);
    }
    int DegreeTwoCount(node *t)
    {
        if (t == NULL)
            return 0;

        if (t->lchild != NULL && t->rchild != NULL)
            return DegreeTwoCount(t->lchild) + DegreeTwoCount(t->rchild) + 1;
        else
            return DegreeTwoCount(t->lchild) + DegreeTwoCount(t->rchild);
    }

    void destroy(node *t)
    {
        if (t != NULL)
        {
            destroy(t->lchild);
            destroy(t->rchild);
            delete t;
        }
    }

public:
    void creatTree()
    {
        creat(root);
    }
    void inTraverse()
    {
        inOrder(root);
    }
    void postTraverse()
    {
        postOrder(root);
    }
    int deep()
    {
        if (depth == -1)
            depth = deep_(root);
        return depth;
    }
    int leafCount()
    {
        if (leafs == -1)
            leafs = _LeafCount(root);

        return leafs;
    }
    int degree_2()
    {
        if (degree_2count == -1)
            degree_2count = DegreeTwoCount(root);
        return degree_2count;
    }
    ~BiTree()
    {
        destroy(root);
    }
};
int main()
{
    // ABC##DE#G##F###
    BiTree a;

    a.creatTree();

    cout << "中序遍历" << endl;
    a.inTraverse(); // 中序
    cout << endl;

    cout << "后序遍历" << endl;
    a.postTraverse(); // 后序
    cout << endl;

    cout << "深度为" << endl;
    cout << a.deep() << endl; // 深度

    cout << "叶子结点数为" << endl;
    cout << a.leafCount() << endl; // 叶子结点数

    cout << "结点度数为2的个数" << endl;
    cout << a.degree_2() << endl; // 结点度数为2的个数;
}