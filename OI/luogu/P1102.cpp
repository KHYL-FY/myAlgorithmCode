//TLE 76
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int n, c, ans = 0;
    cin >> n >> c;
    int num[n + 5];

    for (int i = 1; i <= n; i++)
    {
        cin >> num[i];
    }
    sort(num + 1, num + n+1);
    reverse(num + 1, num + n+1);

    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (num[i]-num[j]==c){
                ans++;
            }
        }
    }

    cout << ans;
}