//2541班 王艺杰
#include <stdio.h>

int max(int a, int b)
{
    return a > b ? a : b;
}
int main()
{
    printf("案例一\n2541班 王艺杰\n");
    
    int a, b;

    printf("输入两个数:\n");
    scanf("%d%d", &a, &b);

    printf("%d", max(a, b));

    return 0;
}