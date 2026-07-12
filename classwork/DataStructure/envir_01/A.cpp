#include <iostream>
// 2541 王艺杰
using namespace std;

#define M 10001

#define ERROR -1
#define OK 0
#define OVERFLOW -2
#define NOTCREAT -3
#define FULL -4
#define NOTFOUND -5
#define EMPTY -6

class Sqlist
{
public:
    int InitList();
    int InputList(int n);
    int OutputList();
    int ListInsert(int p, int e);
    int ListDelete(int p);
    int GetElem(int p, int &e);
    int FindElem(int e, int &p);
    void OverList();

private:
    struct _list
    {
        int *elem = NULL;
        int length = 0;
    } L;
};

int Sqlist::InitList()
{
    L.elem = new int[M];

    if (!L.elem)
        return ERROR;

    L.length = 0;

    return OK;
}
int Sqlist::InputList(int n)
{
    if (!L.elem)
        return NOTCREAT;
    if (n < 0 || n > M)
        return ERROR;

    for (int i = 0; i < n; i++)
    {
        cin >> L.elem[L.length];
        L.length++;
    }
    return OK;
}
int Sqlist::OutputList()
{
    if (!L.elem)
        return NOTCREAT;
    for (int i = 0; i < L.length; i++)
    {
        cout << L.elem[i] << " ";
    }
    cout << endl;

    return OK;
}
int Sqlist::ListInsert(int p, int e)
{
    if (p <= 0 || p > L.length)
        return ERROR;
    if (!L.elem)
        return NOTCREAT;
    if (L.length == M - 1)
        return FULL;

    int i = L.length - 1;
    for (; i >= p - 1; i--)
        L.elem[i + 1] = L.elem[i];

    L.elem[i + 1] = e;

    L.length++;
    return OK;
}
int Sqlist::ListDelete(int p)
{
    if (p <= 0 || p > L.length)
        return ERROR;
    if (!L.elem)
        return NOTCREAT;
    if (L.length == 0)
        return EMPTY;

    for (int i = p; i <= L.length; i++)
        L.elem[i - 1] = L.elem[i];
    L.length--;

    return OK;
}
int Sqlist::GetElem(int p, int &e)
{
    if (p <= 0 || p > L.length)
        return ERROR;
    if (!L.elem)
        return NOTCREAT;

    e = L.elem[p - 1];

    return OK;
}
int Sqlist::FindElem(int e, int &p)
{
    if (!L.elem)
        return NOTCREAT;

    for (int i = 0; i < L.length; i++)
    {
        if (L.elem[i] == e)
        {
            p = i + 1;
            return OK;
        }
    }
    return NOTFOUND;
}
void Sqlist::OverList()
{
    if (L.elem)
        delete[] L.elem;

    return;
}

int main()
{
    Sqlist L;

    int command = 0;
    bool over = false;
    bool first_ = true;
    while (!over)
    {
        if (first_)
        {
            cout << "请输入要进行的操作" << endl
                 << "1.建立一个空顺序表" << endl
                 << "2.输入n个数据" << endl
                 << "3.输出所有元素" << endl
                 << "4.将元素插入到指定位置" << endl
                 << "5.删除指定位置的元素" << endl
                 << "6.访问指定位置的元素" << endl
                 << "7.查找指定元素的位置" << endl
                 << "8.退出" << endl;
            first_ = false;
        }

        cin >> command;
        int exit;
        int p, e;
        switch (command)
        {
        case 1:
            if (L.InitList() == OK)
                cout << "顺序表创建成功,最多可放入" << M - 1 << "个元素" << endl;
            else
                cout << "顺序表创建失败" << endl;

            break;
        case 2:
            int n;
            cout << "请输入放入的元素个数" << endl;
            cin >> n;
            cout << "请输入要放入的元素" << endl;
            exit = L.InputList(n);
            switch (exit)
            {
            case OK:
                cout << "元素放入成功" << endl;
                break;
            case NOTCREAT:
                cout << "请先创建顺序表" << endl;
                break;
            case ERROR:
                cout << "元素放入失败,请输入正确的个数" << endl;
                break;
            case FULL:
                cout << "空间已满" << endl;
                break;
            }

            break;
        case 3:
            exit = L.OutputList();
            if (exit == NOTCREAT)
                cout << "请先创建顺序表" << endl;

            break;
        case 4:
            cout << "请分别输入要插入的元素和位置" << endl;
            cin >> e >> p;
            exit = L.ListInsert(p, e);

            if (exit == OK)
                cout << "已成功将" << e << "插入到位置" << p << "中" << endl;
            else if (exit == NOTCREAT)
                cout << "请先创建顺序表" << endl;
            else if (exit == ERROR)
                cout << "请输入正确的位置" << endl;

            break;
        case 5:

            cout << "请输入要删除的位置" << endl;
            cin >> p;
            exit = L.ListDelete(p);
            switch (exit)
            {
            case OK:
                cout << "删除元素成功" << endl;
                break;
            case ERROR:
                cout << "请输入正确的元素位置" << endl;
                break;
            case NOTCREAT:
                cout << "请先创建顺序表" << endl;
                break;
            case EMPTY:
                cout << "当前顺序表为空,无法删除元素" << endl;
                break;
            }

            break;
        case 6:

            cout << "请输入要访问的元素位置" << endl;
            cin >> p;

            exit = L.GetElem(p, e);
            switch (exit)
            {
            case OK:
                cout << "第" << p << "个元素为" << e << endl;
                break;
            case ERROR:
                cout << "请输入正确的元素位置" << endl;
                break;
            case NOTCREAT:
                cout << "请先创建顺序表" << endl;
                break;
            }

            break;
        case 7:

            cout << "请输入要查找的元素" << endl;
            cin >> e;
            exit = L.FindElem(e, p);

            switch (exit)
            {
            case OK:
                cout << "最先出现" << e << "的元素位置为" << p << endl;
                break;
            case NOTCREAT:
                cout << "请先创建顺序表" << endl;
                break;
            case NOTFOUND:
                cout << "未找到该元素" << endl;
                break;
            }

            break;
        case 8:
            cout << "程序即将退出" << endl;
            over = true;
            L.OverList();
            break;
        default:
            cout << "请输入正确的指令编号" << endl;
            break;
        }
    }

    return 0;
}