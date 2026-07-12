#include<iostream>
#define ll long long
#include <map>
using namespace std;

int main(){
    map<ll, ll> a;

    ll n;
    cin >> n;
    ll bottle;
    for (ll i = 1; i <= n;i++){
        cin >> bottle;
        a[bottle] = i;
    }

    ll q;
    ll hit;
    cin >> q;
    for (ll i = 1; i <= q;i++){
        cin >> hit;
        cout << a[hit]<<endl;
    }
}