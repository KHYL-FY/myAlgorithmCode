#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    float score, ans = 0;
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> score;
            ans += score;
            cout << fixed << setprecision(1) << score <<" ";
        }
        cout << fixed << setprecision(1) << ans << endl;
        ans = 0;
    }
}