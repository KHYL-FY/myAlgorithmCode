#include <iostream>
#include <map>

using namespace std;

int main()
{
    string a;
    map<char, int> cnt;
    char aim;

    getline(cin, a);
    cin >> aim;
    
    for (auto i : a)
    {
        cnt[i]++;
    }

    cout << cnt[aim];
}