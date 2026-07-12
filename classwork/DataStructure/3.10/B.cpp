#include <iostream>

using namespace std;

int main()
{
    // 2541王艺杰
    freopen("file.txt", "r", stdin);
    int sum = 0;
    int num;

    while (scanf("%d", &num) != EOF)
        sum += num;

    cout << sum;

    return 0;
}