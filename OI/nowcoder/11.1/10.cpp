#include <bits/stdc++.h>

using namespace std;

int main()
{

    int zimu[30] = {0};
    for (int i = 1; i <= 30; i++){
        zimu[i] = 0;
    }
        int jishu = 0;

    string a;

    cin >> a;
    for (int i = 0; i < a.length(); i++)
    {
        zimu[a[i] - 'a' + 1]++;
    }

    for (int i = 1; i <= 26; i++)
    {
        if (zimu[i] % 2 != 0)
        {
            jishu++;
        }
    }
    if(jishu == 0){
        cout << "1";
        return 0;
    }
    cout << jishu;
}