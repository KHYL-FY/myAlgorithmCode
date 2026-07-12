#include <iostream>

using namespace std;

string a[100005] = {"-1", "-1", "1", "7", "4", "2", "6", "8",
                    "10", "18", "22", "20", "28", "68", "88",
                    "108", "188", "200", "208", "288", "688", "888"};
int main()
{
    int T;
    cin >> T;

    int n;
    for (int i = 1; i <= T; i++)
    {
        cin >> n;
        if (n <= 21)
        {
            cout << a[n] << endl;
        }
        else
        {
            int k = n / 7 - 2;
            a[n] = a[14 + (n % 7)];
            for (int j = 1; j <= k; j++)
            {
                a[n] = a[n] + "8";
            }

            cout << a[n] << endl;
        }
    }
}