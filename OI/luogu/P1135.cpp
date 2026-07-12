#include <iostream>
#include <queue>
using namespace std;

int skip[205];
bool use[205];

struct node
{
    int floor;
    int foot;
};
queue<node> lift;

int main()
{
    int n, a, b;
    cin >> n >> a >> b;

    for (int i = 1; i <= n; i++)
    {
        cin >> skip[i];
        use[i] = false;
    }

    lift.push({a, 0});
    use[a] = true;
    node next;
    while (lift.front().floor != b)
    {
        next.foot = lift.front().foot + 1;

        next.floor = lift.front().floor + skip[lift.front().floor];
        if (next.floor <= n && !use[next.floor])
        {
            lift.push(next);
            use[next.floor] = true;
        }

        next.floor = lift.front().floor - skip[lift.front().floor];
        if (next.floor > 0 && !use[next.floor])
        {
            lift.push(next);
            use[next.floor] = true;
        }

        lift.pop();
        if (lift.empty())
        {
            cout << -1;
            return 0;
        }
    }

    cout << lift.front().foot;
}