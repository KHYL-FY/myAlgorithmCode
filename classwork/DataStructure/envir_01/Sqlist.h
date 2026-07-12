#include <iostream>

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
        cin >> L.elem[i];
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
