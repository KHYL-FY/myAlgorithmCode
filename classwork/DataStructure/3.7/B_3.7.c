// 2541班 王艺杰
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    printf("案例二\n2541班 王艺杰\n");

    int a;
    int maxNum = 0;
    char c;

    do
    {
        scanf("%d", &a);
        maxNum = max(a, maxNum);
    } while ((c = getchar()) != '\n');


    printf("最大数为\n%d", maxNum);

    return 0;
}