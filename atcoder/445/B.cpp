#include <iostream>

using namespace std;

string str[105];
int main()
{
    int n;
    cin >> n;
    int maxlen = 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> str[i];
        int len = str[i].length();
        maxlen = max(maxlen, len);
    }

    int t;
    for (int i = 1; i <= n;i++){
        t = (maxlen - str[i].length())/2;
        for (int j = 1; j <= t;j++)
            cout << ".";
        cout << str[i];
        for (int j = 1; j <= t; j++)
            cout << ".";
        cout << endl;
    }

    return 0;
}