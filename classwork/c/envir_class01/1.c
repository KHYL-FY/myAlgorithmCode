#include <stdio.h>

int main()
{
    const double PI = 3.1415926;
    double r;
    scanf("%lf", &r);

    double s = PI * r * r, c = 2 * r * PI;

    printf("area is %f, perimeter is %f", s, c);
}