#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    bool sushu = 1;
    int ans = 0, sum = 0;

    for (int i = 100; i <= 300; i++)
    {
        sushu = 1;
        for (int j = 2; j <= sqrt(i); j++)
        {
            if (i % j == 0)
            {
                sushu = 0;
                break;
            }
        }
        if (sushu == 1)
        {
            ans++;
            sum += i;
        }
    }

    cout << "个数为:" << ans << endl
         << "和为:" << sum;
}