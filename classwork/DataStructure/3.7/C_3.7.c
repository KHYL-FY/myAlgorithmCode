// 2541班 王艺杰
#include <stdio.h>

void sort(int a[], int lenth)
{
    int t;
    for (int i = 0; i < lenth - 1; i++)
    {
        for (int j = 0; j < lenth - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
int main()
{
    printf("案例三\n2541班 王艺杰\n");
    int a[101];
    char c;
    
    printf("请输入不超过100个整数\n");

    int len = 0;
    do
    {
        scanf("%d", &a[len]);
        len++;
    } while ((c = getchar()) != '\n');

    sort(a, len);

    for (int i = 0; i < len; i++)
        printf("%d ", a[i]);

    return 0;
}