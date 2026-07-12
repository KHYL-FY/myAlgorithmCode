#include <iostream>

using namespace std;

int jiecheng(int n)
{
    int num = 1;
    for (int i = 1; i <= n; i++)
    {
        num *= i;
    }
    return num;
}
int main()
{
    int c;
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            c = jiecheng(i) / (jiecheng(j) * jiecheng(i - j));
            printf("%-4d", c);
        }
        printf("\n");
    }
}