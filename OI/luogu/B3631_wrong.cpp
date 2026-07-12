#include <bits/stdc++.h>

using namespace std;

struct list_
{
    int data;
    list_ *next;
};

list_ *head, *p, *r, *a;
void list_insert(int x, int y)
{
    p = head->next;
    while (p->data != x)
        p = p->next;
    a = new list_;
    a->data = y;
    a->next = p->next;
    p->next = a;
}
void question(int x)
{
    p = head->next;
    if (p->next == NULL)
    {
        cout << "0" << endl;
        return;
    }
    while (p->data != x)
    {
        if (p->next == NULL)
        {
            cout << "0" << endl;
            return;
        }
        p = p->next;
    }
    cout << p->next->data << endl;
}
void list_delete(int x)
{
    p = head->next;
    while (p->data != x)
        p = p->next;

    p->next = p->next->next;
}
int main()
{
    int n;
    cin >> n;

    int caozuo;

    head = new list_;
    r = head;

    p = new list_;
    p->next = NULL;
    p->data = 1;

    r->next = p;
    r = p;

    int x, y;
    
    for (int i = 1; i <= n; i++)
    {
        cin >> caozuo;
        switch (caozuo)
        {
        case 1:
            cin >> x >> y;
            list_insert(x, y);
            break;
        case 2:
            cin >> x;
            question(x);
            break;
        case 3:
            cin >> x;
            list_delete(x);
            break;
        default:
            break;
        }
    }
}