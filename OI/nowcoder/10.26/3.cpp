#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    int n, a, k;
    string num;
    int mine_num;
    for (int i = 1; i <= t; i++)
    {
        cin >> n >> a >> k;
        mine_num = a + 1;
        for (; k >= 1; k--)
        {
            num = to_string(mine_num);

            if (num.find('7') != string::npos || mine_num % 7 == 0)
            {
                cout << "p ";
            }
            else
                cout << mine_num << " ";

            mine_num += n;
        }
        cout << endl;
    }
}