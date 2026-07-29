#include <iostream>

using namespace std;

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if ((i ^ j) <= k)
                cout << i << " " << j << " " << (i ^ j) << endl;
        }
    }
}