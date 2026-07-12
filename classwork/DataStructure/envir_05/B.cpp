#include <iostream>

using namespace std;

class LinkStack
{
#define ERROR -1
#define OK 0
    typedef char SqType;

private:
    struct StackNode
    {
        SqType data;
        StackNode *next;
    };
    StackNode *top;

public:
    LinkStack()
    {
        top = NULL;
    }

    int push(SqType e)
    {
        StackNode *s = new StackNode;
        if (!s)
            return ERROR;
        s->data = e;
        s->next = top;
        top = s;
        return OK;
    }

    int pop(SqType &e)
    {
        if (top == NULL)
            return ERROR;
        StackNode *p = top;
        e = top->data;
        top = top->next;
        delete p;
        return OK;
    }

    SqType GetElem()
    {
        if (top != NULL)
        {
            return top->data;
        }
        else
        {
            return ERROR;
        }
    }
    bool empty()
    {
        return top == NULL;
    }
    ~LinkStack()
    {
        StackNode *p;
        while (top != NULL)
        {
            p = top;
            top = top->next;
            delete p;
        }
    }
};

class BiTree
{
#define OVERFLOW -1
#define OK 1
    typedef char Elemtype;
    typedef int exceptType;
    char end_ = '#';

protected:
    struct node
    {
        Elemtype data;
        node *lchild, *rchild;
    };
    node *root;
    int depth = -1;
    int leafs = -1;
    int degree_2count = -1;

private:
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

class stkOrder_BiTree : public BiTree
{
private:
    LinkStack stk;

    void inOrderStack(node *t)
    {
        node *p = t;
        while (p != NULL || !stk.empty())
        {
            while (p != NULL)
            {
                stk.push(p->data);
                p = p->lchild;
            }
            char ch;
            stk.pop(ch);
            cout << ch;
            p = p->rchild;
        }
    }

public:
    void inOrderStk()
    {
        inOrderStack(root);
    }
};

int main()
{
    stkOrder_BiTree a;
    a.creatTree();

    cout << "非递归中序遍历:";
    a.inOrderStk();

    cout << endl;
    return 0;
}
