#include <iostream>
using namespace std;
const int N = 200010;
long long shu[N];
long long sum;
int main()
{
    int t;
    cin >> t;
    int summ = t;
    while (t--)
    {
        int x;
        cin >> x;
        shu[x]++;
    }
    for (int i = 1; i <= N - 5; i++)
    {
        if (shu[i] >= 2)
        {
            sum += shu[i] * (shu[i] - 1) / 2 * (summ - shu[i]);
        }
    }
    cout << sum;
}