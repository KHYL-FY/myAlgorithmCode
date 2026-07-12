#include <stdio.h>

int main()
{
    char a[5] = "hello";

    for (int i = 0; i < 5; i++)
    {
        a[i] += 6;
        printf("%c", a[i]);
    }
    
    printf("\n");

    for (int i = 0; i < 5; i++)
    {
        a[i] -= 6;
        printf("%c", a[i]);
    }
}