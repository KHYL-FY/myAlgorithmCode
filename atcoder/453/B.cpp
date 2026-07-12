#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int t, x;
    cin >> t >> x;
    vector<pair<int, int>> sensor;

    int A;
    cin >> A;
    sensor.push_back({0, A});
    auto it = sensor.end();
    for (int i = 1; i <= t; i++)
    {
        cin >> A;
        it = sensor.end();
        it--;
        if (abs((*it).second - A) >= x)
            sensor.push_back({i, A});
    }

    for (auto i = sensor.begin(); i != sensor.end(); i++)
    {
        cout << (*i).first << " " << (*i).second << endl;
    }

    return 0;
}