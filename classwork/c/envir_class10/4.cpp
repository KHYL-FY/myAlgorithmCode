#include <iostream>

using namespace std;

void char_sort(char *p[])
{
    for (int i = 0; i <= 4; i++)
    {
        for (int j = i; j <= 4; j++)
        {
            if (*p[i] > *p[j])
            {
                char *t = p[i];
                p[i] = p[j];
                p[j] = t;
            }
        }
    }
}
int main()
{
    char *p[100];

    char a[105], b[105], c[105], d[105], e[105];

    cin >> a >> b >> c >> d >> e;

    p[0] = a, p[1] = b, p[2] = c, p[3] = d, p[4] = e;

    char_sort(p);

    cout << "排序后:" << endl;
    for (int i = 0; i <= 4; i++)
    {
        int j = 0;
        while (*(p[i] + j) != '\0')
        {
            cout << *(p[i] + j);
            j++;
        }
        cout << endl;
    }
}