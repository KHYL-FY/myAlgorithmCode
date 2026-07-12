#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Point
{
    long long x, y;
    int id;

    bool operator<(const Point &p) const
    {
        if (x != p.x)
            return x < p.x;
        return y < p.y;
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Point> points(n);
    for (int i = 0; i < n; i++)
    {
        cin >> points[i].x >> points[i].y;
        points[i].id = i + 1;
    }

    sort(points.begin(), points.end());

    vector<int> a, b;

    for (int i = 0; i < 3; i++)
    {
        a.push_back(points[i].id);
    }

    for (int i = n - 3; i < n; i++)
    {
        b.push_back(points[i].id);
    }

    cout << a.size() << " " << b.size() << endl;
    for (int i = 0; i < a.size(); i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] << " ";
    }

    return 0;
}