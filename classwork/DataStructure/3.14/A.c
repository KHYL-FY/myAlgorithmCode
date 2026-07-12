#include <stdio.h>
// 2541 王艺杰
struct dxs
{
    float xs;
    float zs;
};

void sort(struct dxs a[], int length)
{
    // 逆序
    struct dxs t;

    for (int i = 1; i < length; i++)
    {
        for (int j = i + 1; j <= length; j++)
        {
            if (a[i].zs > a[j].zs)
            {
                t = a[i];
                a[i] = a[j];
                a[j] = t;
            }
        }
    }
    return;
}
int cin(struct dxs n[])
{
    int nlen;
    printf("请输入多项式的项数:\n");
    scanf("%d", &nlen);

    printf("分别输入各项系数和指数:\n");
    for (int i = 1; i <= nlen; i++)
        scanf("%f%f", &n[i].xs, &n[i].zs);
    putchar('\n');

    return nlen;
}
void checkOut(struct dxs n[], int nlen)
{
    printf("该多项式的系数为:\n");
    for (int i = 1; i <= nlen; i++)
        printf("%-8.1f", n[i].xs);
    putchar('\n');

    printf("该多项式的指数为:\n");
    for (int i = 1; i <= nlen; i++)
        printf("%-8.1f", n[i].zs);
    putchar('\n');

    return;
}
void cout(struct dxs out[], int outlen)
{
    printf("计算后的结果为:\n");
    printf("系数: ");
    for (int i = 1; i <= outlen; i++)
        printf("%-8.1f", out[i].xs);
    putchar('\n');

    printf("指数: ");
    for (int i = 1; i <= outlen; i++)
        printf("%-8.1f", out[i].zs);

    return;
}
int main()
{
    // freopen("cin.txt", "r", stdin);

    struct dxs a[101], b[101], c[101];
    int alen, blen;

    alen = cin(a);
    sort(a, alen);
    checkOut(a, alen);
    putchar('\n');

    blen = cin(b);
    sort(b, blen);
    checkOut(b, blen);
    putchar('\n');

    int ap = 1, bp = 1, cp = 1;
    while (ap <= alen && bp <= blen)
    {
        if (a[ap].zs == b[bp].zs)
        {
            if (a[ap].xs + b[bp].xs == 0)
            {
                ap++, bp++;
                continue;
            }
            c[cp].zs = a[ap].zs;
            c[cp].xs = a[ap].xs + b[bp].xs;
            ap++, bp++, cp++;
        }
        else if (a[ap].zs < b[bp].zs)
        {
            c[cp] = a[ap];
            ap++, cp++;
        }
        else
        {
            c[cp] = b[bp];
            bp++, cp++;
        }
    }
    while (ap <= alen)
    {
        c[cp] = a[ap];
        ap++, cp++;
    }
    while (bp <= blen)
    {
        c[cp] = b[bp];
        bp++, cp++;
    }

    cout(c, cp - 1);

    return 0;
}