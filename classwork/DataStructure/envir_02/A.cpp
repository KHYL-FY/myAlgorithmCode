#include <iostream>

using namespace std;

#define ERROR -1
#define OK 0

class List
{
private:
    struct LNode
    {
        int data;
        LNode *next = NULL;
    } *LinkList, *p, *s, *q;

public:
    int CreatList_L(int n);
    int PrintList();
    int ListInstert_L(int i, int e);
    int ListDelete(int i, int &e);
    int GetElem_L(int i, int &e);
    ~List();
};

int List::CreatList_L(int n)
{
    if (n <= 0)
        return ERROR;
    LinkList = new LNode;
    LinkList->next = NULL;

    for (int i = n; i > 0; i--)
    {
        p = new LNode;
        cin >> p->data;
        p->next = LinkList->next;
        LinkList->next = p;
    }

    return OK;
}
int List::PrintList()
{
    if (LinkList->next == NULL)
        return ERROR;
    p = LinkList->next;
    do
    {
        cout << p->data << " ";
        p = p->next;
    } while (p != NULL);
    cout << endl;
    return OK;
}
int List::ListInstert_L(int i, int e)
{
    p = LinkList;
    int j = 0;
    while (p && j < i - 1)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i - 1)
        return ERROR;

    s = new LNode;
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
int List::ListDelete(int i, int &e)
{
    p = new LNode;
    p = LinkList;
    int j = 0;
    while (p->next && j < i - 1)
    {
        p = p->next;
        j++;
    }

    if (!(p->next) || j > i - 1)
        return ERROR;

    q = p->next;
    p->next = q->next;
    e = q->data;
    delete q;

    return OK;
}
int List::GetElem_L(int i, int &e)
{
    p = LinkList->next;
    int j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p || j > i)
        return ERROR;
    else
        e = p->data;

    return OK;
}
List::~List()
{
    p = new LNode;
    while (LinkList->next != NULL)
    {
        p = LinkList;
        LinkList = LinkList->next;
        delete p;
    }
}
int main()
{
    List L;
    bool first_ = true;
    int command = 0;
    while (1)
    {
        if (first_)
        {
            cout << "1.输入n个数据" << endl
                 << "2.输出所有元素" << endl
                 << "3.将元素插入到指定位置" << endl
                 << "4.删除指定位置的元素" << endl
                 << "5.访问指定位置的元素" << endl
                 << "6.退出" << endl;
            first_ = false;
        }
        cout << "请输入要进行的操作" << endl;
        cin >> command;
        int n, i, e, ReturnCode;
        switch (command)
        {
        case 1:
            cout << "输入要放入元素的个数" << endl;
            cin >> n;
            cout << "请输入要放入的数字" << endl;
            ReturnCode = L.CreatList_L(n);
            if (ReturnCode == ERROR)
                cout << "请输入正确的n" << endl;
            if (ReturnCode == OK)
                cout << "插入元素成功" << endl;

            break;
        case 2:
            ReturnCode = L.PrintList();
            if (ReturnCode == ERROR)
                cout << "链表为空无法输出" << endl;

            break;

        case 3:
            cout << "分别输入要插入的元素以及位置" << endl;
            cin >> e >> i;
            ReturnCode = L.ListInstert_L(i, e);
            if (ReturnCode == ERROR)
                cout << "请输入正确的位置" << endl;
            if (ReturnCode == OK)
                cout << "成功将" << e << "插入到" << i << "位置" << endl;

            break;
        case 4:
            cout << "分别输入要删除的元素位置" << endl;
            cin >> i;
            ReturnCode = L.ListDelete(i, e);
            if (ReturnCode == ERROR)
                cout << "请输入正确的位置" << endl;
            if (ReturnCode == OK)
                cout << "成功将" << i << "位置的" << e << "元素删除" << endl;

            break;

        case 5:
            cout << "请输入要获取元素的位置" << endl;
            cin >> i;
            ReturnCode = L.GetElem_L(i, e);
            if (ReturnCode == ERROR)
                cout << "请输入正确的位置" << endl;
            if (ReturnCode == OK)
                cout << "位置" << i << "元素为" << e << endl;

            break;
        case 6:
            cout << "程序即将退出" << endl;
            return 0;
            break;
        default:
            cout << "请输入正确的指令编号" << endl;
        }
    }
}