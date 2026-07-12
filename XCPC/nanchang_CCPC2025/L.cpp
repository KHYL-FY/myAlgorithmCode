#include <iostream>

using namespace std;

int main()
{
    string a = "Alice";
    string b = "Bob";
    int score1, score2;
    cin >> score1 >> score2;

    if (max(score1, score2) >= 21 && abs(score1 - score2) >= 2){
        if(score1>score2){
            cout << a;
        }
        else {
            cout << b;
        }
    }
    else if(score1 == 30||score2==30){
        if(score1 == 30){
            cout << a;
        }
        if(score2 == 30)
            cout << b;
    }
    else {
        cout << "Underway";
    }
}