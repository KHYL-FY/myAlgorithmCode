#include <iostream>
#include <stack>
using namespace std;

#define ll long long

bool ifnum(char x)
{
    if (x <= '9' && x >= '0')
        return true;
    else
        return false;
}

int main()
{
    string a;
    cin >> a;

    stack<ll> num;

    ll t = 0;
    ll ans = 0;
    for (ll i = 0; a[i]!='@'; i++)
    {
        if (ifnum(a[i])){
            t = t * 10 + (a[i] - '0');
            continue;
        }
        if (a[i] == '.'){
            num.push(t);
            t = 0;
            continue;
        }  
        if(a[i]=='+'){
            ans = num.top();
            num.pop();
            ans = num.top() + ans;
            num.pop();
            num.push(ans);
            continue;
        }
        if (a[i] == '-')
        {
            ans = num.top();
            num.pop();
            ans = num.top() - ans;
            num.pop();
            num.push(ans);
            continue;
        }
        if (a[i] == '*')
        {
            ans = num.top();
            num.pop();
            ans = num.top() * ans;
            num.pop();
            num.push(ans);
            continue;
        }
        if (a[i] == '/')
        {
            ans = num.top();
            num.pop();
            ans = num.top() / ans;
            num.pop();
            num.push(ans);
            continue;
        }
    }

    cout << num.top();
}