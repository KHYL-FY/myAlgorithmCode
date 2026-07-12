#include <iostream>

using namespace std;

int main()
{
    int h, w;
    cin >> h >> w;

    for (int i = 1; i <= w; i++)
    {
        cout << "#";
    }
    cout << endl;
    for (int i = 1; i <= h - 2; i++)
    {
        cout << "#";
        for (int j = 1; j <= w - 2; j++)
        {
            cout << ".";
        }
        cout << "#" << endl;
    }
    for (int i = 1; i <= w; i++)
    {
        cout << "#";
    }
}