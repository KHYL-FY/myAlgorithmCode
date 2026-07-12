#include <iostream>
#include <map>
#include <algorithm>
#include <vector>

#define ll long long
using namespace std;

map<ll, bool> wood;
vector<ll> query;

int main()
{
    ll n, q;

    cin >> n;

    ll length;

    for (ll i = 1; i <= n; i++)
    {
        cin >> q;
        switch (q)
        {
        case 1:
            cin >> length;
            if (wood[length] != 0)
                cout << "Already Exist" << endl;
            else
            {
                wood[length] = 1;
                query.push_back(length);
                sort(query.begin(), query.end());
            }

            break;
        case 2:
            cin >> length;
            if (query.empty())
                cout << "Empty" << endl;
            else
            {
                auto it = lower_bound(query.begin(), query.end(), length);

                if (it != query.end() && *it == length)
                {
                    cout << *it << endl;
                    wood[length] = 0;
                    query.erase(it);
                }
                else
                {
                    if (it == query.end())
                    {
                        cout << *(it - 1) << endl;
                        wood[*(it - 1)] = 0;
                        query.erase(it - 1);
                    }
                    else if (it == query.begin())
                    {
                        cout << *it << endl;
                        wood[*it] = 0;
                        query.erase(it);
                    }
                    else
                    {
                        if (length - *(it - 1) <= *it - length)
                        {
                            cout << *(it - 1) << endl;
                            wood[*(it - 1)] = 0;
                            query.erase(it - 1);
                        }
                        else
                        {
                            cout << *it << endl;
                            wood[*it] = 0;
                            query.erase(it);
                        }
                    }
                }
            }

            break;
        }
    }
}