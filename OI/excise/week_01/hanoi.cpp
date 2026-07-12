#include <iostream>

using namespace std;
int step = 0;
int n, m;
void hanoi(int n, char a, char b, char c)
{

    if (n == 1)
    {
        step++;
        if (step == m)
        {
            cout << "#" << n << ": " << a << "->" << c << endl;
        }
    }
    else
    {
        hanoi(n - 1, a, c, b);
        step++;
        if (step == m)
        {
            cout << "#" << n << ": " << a << "->" << c << endl;
        }

        hanoi(n - 1, b, a, c);
        // cout << "#" << step << ":" << a << "->" << c << endl;
        // step++;
    }
}
int main()
{
    cin >> n >> m;
    hanoi(n, 'A', 'B', 'C');

    cout << step;
}