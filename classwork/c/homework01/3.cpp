#include<iostream>

using namespace std;

int main(){
    int taozi=1;

    for (int i = 1; i <= 9;i++)
    {
        taozi++;
        taozi *= 2;
    }

    cout << taozi;
}