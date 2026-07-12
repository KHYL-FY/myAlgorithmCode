#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, num, pointer, ans_num = 0;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> num;
        if(num>ans_num){
            ans_num = num;
            pointer = i;
        }
    }
    cout << pointer;
}