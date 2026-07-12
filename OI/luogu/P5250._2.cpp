#include <iostream>
#include <map>
#include <algorithm>
#define ll long long
// #define debug
using namespace std;

ll query[100005];
map<ll, ll> wood;
int main()
{
    int n;

    cin >> n;
    int q;
    ll length;
    ll count = 0;
    ll query_l = 0, query_r = 0;
    for (int i = 1; i <= n; i++)
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
                query[query_r] = length;
                count++;
                query_r++;
                sort(query + query_l, query + query_r);
            }

            break;
        case 2:
            cin >> length;
            if (count == 0)
                cout << "Empty" << endl;
            else
            {
                if (wood[length] != 0)
                {
                    cout << length << endl;
                    count--;
                    wood[length] = 0;
                    ll mid, l = query_l, r = query_r - 1;
                    while (l <= r)
                    {
                        mid = (l + r) / 2;
                        if (query[mid] < length)
                        {
                            l = mid + 1;
                        }
                        else
                        {
                            r = mid - 1;
                        }
                    }
                    query[l] = 0;
                    sort(query + query_l, query + query_r);
                    query_l++;
                    // #ifdef debug
                    //                     for (int i = query_l; i < query_r; i++)
                    //                         cout << query[i] << endl;
                    //                     cout << query_l << query_r << endl;
                    // #endif
                }
                else
                {
                    ll mid, l = query_l, r = query_r;
                    while (l <= r)
                    {
                        mid = (l + r) / 2;
                        if (query[mid] < length)
                        {
                            l = mid + 1;
                        }
                        else
                        {
                            r = mid - 1;
                        }
                    }
#ifdef debug
                    cout << endl;
                    for (int i = query_l; i < query_r; i++)
                        cout << query[i] << endl;
                    cout << query_l << query_r << endl;
#endif
                    if (length - query[r] == query[l] - length)
                    {
                        cout << query[r] << endl;
                        wood[query[r]] = 0;
                        query[r] = 0;
                    }
                    else
                    {
                        ll ans = 0;
                        if (length - query[r] < query[l] - length)
                        {
                            ans = query[r];
                            wood[ans] = 0;
                            query[r] = 0;
                        }
                        else
                        {
                            ans = query[l];
                            wood[ans] = 0;
                            query[l] = 0;
                        }
                        cout << ans << endl;
                    }

                    sort(query + query_l, query + query_r);
                    query_l++;
                    count--;
                    // #ifdef debug
                    //                     cout << endl;
                    //                     for (int i = query_l; i < query_r; i++)
                    //                         cout << query[i] << endl;
                    //                     cout << query_l << query_r << endl;
                    // #endif
                }
            }
            break;
        }
    }
}