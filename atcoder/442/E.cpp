#include<iostream>

#define ll long long
const ll N = 2e5 + 10;
using namespace std;

struct monster{
    ll x, y;
    ll id;
};

monster mons[N];

bool cmp(monster a,monster b){
    ll dir = a.x * b.y - a.y * b.x;

    if(dir>0) 
}
int main(){
    ll n, q;
    cin >> n >> q;

    ll monx, mony;
    for (ll i = 1; i <= n;i++){
        cin >> mons[i].x >> mons[i].y;
        mons[i].id = i;
    }


}