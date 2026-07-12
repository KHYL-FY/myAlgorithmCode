#include <bits/stdc++.h>

using namespace std;

struct list_
{
    int data;
    list_ *next;
};

int main()
{
    int n, m;
    cin >> n >> m;

    list_ *p, *head, *r;

    head = new list_;
    r = head;

    for (int i = 1; i <= n; i++)
    {
        p = new list_;
        p->data = i;
        p->next = NULL;
        r->next = p;

        r = p;
    }

    r->next = head->next;
    p = head;

    while (n > 0)
    {
        for (int i = 1; i < m; i++)
        {
            p = p->next;
        }
        n--;
        cout << p->next->data << " ";
        p->next = p->next->next;
    }
    // while (p->next != NULL)
    // {
    //     cout << p->data << " ";
    //     p = p->next;
    // }
    // cout << p->data;
}