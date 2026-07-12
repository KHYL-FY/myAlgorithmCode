#include <iostream>
using namespace std;
int main()
{
    string ans[] = {
        "1204",          // 双引号中替换为 A 题的答案
        "1100325199.77", // 双引号中替换为 B 题的答案
    };
    char T;
    cin >> T;
    cout << ans[T - 'A'] << endl;
    return 0;
}
