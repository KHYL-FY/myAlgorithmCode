#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> a;

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        a.push_back(i);
    }

    list<int>::iterator pointer = a.begin();
    
    while (a.size() > 1)
    {
        for (int i = 1; i < m; i++)
        {
            pointer++;
            if (pointer == a.end())
            {
                pointer = a.begin();
            }
        }
        cout << *pointer << " ";
        pointer = a.erase(pointer);

        if (pointer == a.end())
        {
            pointer = a.begin();
        }
    }
    cout << a.front();
}