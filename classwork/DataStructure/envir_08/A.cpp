#include <iostream>

using namespace std;

template <typename KeyType>
class _sort
{
#define MAXSIZE 101
private:
    KeyType SqList[MAXSIZE];
    int length = 0;

    void pushList(KeyType _num)
    {
        SqList[++length] = _num;

        return;
    }
    void printList()
    {
        for (int i = 1; i <= length; i++)
        {
            cout << SqList[i] << " ";
        }
        cout << endl;
        return;
    }

    void _insertSort()
    {
        int i, j;
        for (i = 2; i <= length; i++)
        {
            if (SqList[i] < SqList[i - 1])
            {
                SqList[0] = SqList[i];
                for (j = i - 1; SqList[0] < SqList[j]; j--)
                    SqList[j + 1] = SqList[j];

                SqList[j + 1] = SqList[0];
            }

            printList();
        }

        return;
    }
    void _bubbleSort()
    {
        int m = length - 1;
        bool flag = 1;
        while (m > 0 && flag)
        {
            flag = 0;
            for (int i = 1; i <= m; i++)
            {
                if (SqList[i] > SqList[i + 1])
                {
                    flag = 1;

                    SqList[0] = SqList[i];
                    SqList[i] = SqList[i + 1];
                    SqList[i + 1] = SqList[0];
                }
            }
            m--;
            printList();
        }

        return;
    }

    void _selectSort()
    {
        int i, j, k;
        for (int i = 1; i < length; i++)
        {
            k = i;
            for (j = i + 1; j <= length; j++)
            {
                if (SqList[j] < SqList[k])
                    k = j;
            }
            if (k != i)
            {
                SqList[0] = SqList[i];
                SqList[i] = SqList[k];
                SqList[k] = SqList[0];
            }
            printList();
        }
        return;
    }

public:
    void push(KeyType _num)
    {
        pushList(_num);
        return;
    }
    void print()
    {
        printList();
    }
    void insertSort()
    {
        _insertSort();
        return;
    }
    void bubbleSort()
    {
        _bubbleSort();
        return;
    }
    void selectSort()
    {
        _selectSort();
        return;
    }
};
int main()
{
    // 12 45 21 12 30 2 38 33
    // 2 12 12 21 30 33 38 45
    // 68 45 33 30 21 12 12 2

    int n, num;
    _sort<int> a;

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        a.push(num);
    }

    a.insertSort();
    // a.bubbleSort();
    // a.selectSort();

    a.print();
}