
#include <iostream>

using namespace std;

int holes_cnt[26] = {1, 2, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                     0, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0};
int main()
{
    string a;
    cin >> a;
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < 26; i++)
    {
        sum = 0;
        for (int j = 0; j < (int)a.length(); j++)
        {
            int n = (a[j] - 'A' + i) % 26;

            sum += holes_cnt[n];
        }
        ans = max(sum, ans);
    }

    cout << ans;
}