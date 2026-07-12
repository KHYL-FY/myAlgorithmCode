#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<int, int> a;

    int n;
    cin >> n;

    int num;
    int maxNum = -1;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        a[num]++;
        maxNum = max(a[num], maxNum);
    }
    
    int yudui = n - maxNum;
    if (maxNum > yudui)
    {
        cout << maxNum - yudui;
    }
    if (maxNum <= yudui)
    {
        cout << (yudui - maxNum) % 2;
    }
}