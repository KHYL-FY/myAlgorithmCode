#include <iostream>

using namespace std;
void copy(char a[], char b[])
{
    int i = 0;
    while (a[i] != '\0')
    {
        b[i] = a[i];
        i++;
    }
}
int main()
{
    char a[100], b[100];

    cin >> a;

    copy(a, b);

    int i = 0;
    cout << "复制后为"<<endl;
    while (b[i] != '\0')
    {
        cout << b[i];
        i++;
    }
}