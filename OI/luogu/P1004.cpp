#include<iostream>

using namespace std;

int main(){
    int n ;
    cin >> n;

    int a[15][15][15];
    int b[15][15][15];
    int x, y, num;

    for (int i = 1; i <= n;i++){
        cin >> x >> y >> num;
        a[x][y] = num;
        b[x][y] = num;
    }
}