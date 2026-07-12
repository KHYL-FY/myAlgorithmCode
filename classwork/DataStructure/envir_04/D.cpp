#include <iostream>
#include <cstdlib>
using namespace std;

#define OK 1
#define ERROR -1

class MonkeyQueue
{
private:
    struct QNode
    {
        int data;
        QNode *next;
    };
    QNode *head;
    QNode *tail;

public:
    MonkeyQueue()
    {
        head = tail = nullptr;
    }

    void push(int x)
    {
        QNode *s = new QNode;
        s->data = x;
        s->next = nullptr;
        if (!head)
        {
            head = tail = s;
        }
        else
        {
            tail->next = s;
            tail = s;
        }
    }

    int findKing(int n, int k)
    {
        for (int i = 1; i <= n; i++)
            push(i);

        while (head != tail)
        {
            for (int i = 1; i < k; i++)
            {
                QNode *tmp = head;
                head = head->next;
                tail->next = tmp;
                tail = tmp;
                tail->next = nullptr;
            }
            QNode *del = head;
            head = head->next;
            delete del;
        }
        int res = head->data;
        delete head;
        return res;
    }
};

int main()
{
    MonkeyQueue q;
    int n, k;
    cout << "请输入猴子数量 n 和报数 k：";
    cin >> n >> k;
    cout << "猴王编号：" << q.findKing(n, k) << endl;
    return 0;
}