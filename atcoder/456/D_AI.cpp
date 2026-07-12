#include <iostream>
#include <string>
using namespace std;

const int MOD = 998244353;

int main()
{
    string S;
    cin >> S;

    long long dp_a = 0, dp_b = 0, dp_c = 0;

    for (char ch : S)
    {
        if (ch == 'a')
        {
            long long new_a = (1 + dp_b + dp_c) % MOD;
            dp_a = (dp_a + new_a) % MOD;
        }
        else if (ch == 'b')
        {
            long long new_b = (1 + dp_a + dp_c) % MOD;
            dp_b = (dp_b + new_b) % MOD;
        }
        else
        { 
            long long new_c = (1 + dp_a + dp_b) % MOD;
            dp_c = (dp_c + new_c) % MOD;
        }
    }

    long long ans = (dp_a + dp_b + dp_c) % MOD;
    cout << ans << endl;

    return 0;
}