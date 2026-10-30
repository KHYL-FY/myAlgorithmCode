#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;

    vector<int> a(n + 1, 0);
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    for (int i = 1; i <= n; i++)
        cout << a[i] << " ";
    cout << endl;
    for (int i = 1; i <= n; i++)
        cout << sum[i] << " ";
}