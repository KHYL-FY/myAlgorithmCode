#include<iostream>

using namespace std;

int main(){
    string a;
    cin >> a;

    string &b = a;

    cout << "原字符串:" << a<<endl;

    cout << "引用字符串:" << b;
}