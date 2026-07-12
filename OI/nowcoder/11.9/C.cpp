#include <bits/stdc++.h>

using namespace std;

string a;
int ans = 10000;
int len = 0;
int ll;
void huiwen(int i)
{
    int l = i, r = i + 1;
    len = 0;
    while (a[l] == a[r])
    {
        if (l < 0 || r >= ll)
        {
            break;
        }
        len += 2;
        ans = min(len, ans);
        l--;
        r++;
        }
}
void huiwen2(int i)
{
    int l = i - 1, r = i + 1;
    len = 1;
    while (a[l] == a[r])
    {
        if (l < 0 || r >= ll)
        {
            break;
        }
        len += 2;
        ans = min(len, ans);
        l--;
        r++;
    }
}
int main()
{
    cin >> a;
    ll = a.length();

    for (int i = 0; i < ll; i++)
    {
        huiwen2(i);

        huiwen(i);
    }

    if(ans==10000){
        cout << "-1";
        return 0;
    }
    cout << ans;
}