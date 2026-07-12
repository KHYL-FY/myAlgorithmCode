#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    char site;
    cin >> site;

    bool use[6] = {0, 0, 0, 0, 0, 0};
    char in;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= 5; j++)
        {
            cin >> in;
            if (in == 'x')
                use[j] = use[j] || false;
            else
                use[j] = use[j] || true;
        }
    if (use[site - 'A' + 1])
        cout << "Yes";
    else
        cout << "No";
}