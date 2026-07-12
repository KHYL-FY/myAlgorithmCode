#include <iostream>
using namespace std;

int a[10][10];
int ans = 0;
bool ifwin()
{
    int num = 0;
    for (int i = 1; i <= 5; i++)
    {
        num = a[i][1] + a[i][2] + a[i][3] + a[i][4] + a[i][5];
        if (num == 5 || num == 10)
            return false;
    }
    for (int i = 1; i <= 5; i++)
    {
        num = a[1][i] + a[2][i] + a[3][i] + a[4][i] + a[5][i];
        if (num == 5 || num == 10)
            return false;
    }
    num = a[1][1] + a[2][2] + a[3][3] + a[4][4] + a[5][5];
    if (num == 5 || num == 10)
        return false;
    num = a[1][5] + a[2][4] + a[3][3] + a[4][2] + a[5][1];
    if (num == 5 || num == 10)
        return false;

    return true;
}
void dfs(int p)
{
    if (p == 25)
    {
        if(ifwin()){
            ans++;
        }

        return;
    }

    for (int i = 1; i <= 5; i++)
        for (int j = 1; j <= 5; j++)
        if(i*j==p){
            a[i][j] = 1;
            dfs(p + 1);
            a[i][j] = 2;
            dfs(p + 1);
        }
}
int main(){
    cout << 3126376;
}