#include <iostream>

using namespace std;

int main()
{
    int cycle[10] = {1, 0, 0, 0, 1, 0, 1, 0, 2, 1};
    int n;
    int ans = 0;
    int a, b;
    int num;

    cin >> n;
    for (int i = 1; i <= n;i++){
        cin >> a >> b;
        for (int j = a; j <= b;j++){
            num = j;
            do{
                ans += cycle[num%10];
                num /= 10;
            } while (num!=0);
        }
        cout << ans << endl;
        ans = 0;
    }
}