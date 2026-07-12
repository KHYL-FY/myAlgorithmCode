#include <iostream>
#include <map>

using namespace std;

int main()
{
    long long n, target;
    long long ans = 0;
    cin >> n >> target;

    long long num[n + 5];
    map<long long, long long> m;

    for (size_t i = 0; i < n; i++)
    {
        cin >> num[i];
        m[num[i]]++;
        num[i] -= target;
    }

    for (size_t i = 0; i < n; i++)
    {
        ans += m[num[i]];
    }
    cout << ans;
}