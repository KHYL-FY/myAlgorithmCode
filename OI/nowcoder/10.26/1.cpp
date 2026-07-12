#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
    string a;
    cin >> a;
    reverse(a.begin(), a.end());
    cout << a;
}