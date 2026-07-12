#include<iostream>

using namespace std;

int main(){
    int a[5] = {1, 3, 5, 7, 9};
    int b[5];
    for (int i = 0; i <= 4;i++){
        b[i] = a[i];
    }

    for (int i = 0; i <= 4;i++){
        cout << b[i]<<" ";
    }
}