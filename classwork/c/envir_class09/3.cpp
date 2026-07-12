#include <iostream>

using namespace std;

int n;
void sort_(int a[])
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            if (a[i] < a[j])
            {
                swap(a[i], a[j]);
            }
        }
    }
}
int main()
{

    cin >> n;
    int score[n + 5];
    for (int i = 1; i <= n; i++)
    {
        cin >> score[i];
    }

    sort_(score);

    for (int i = 1; i <= n; i++)
    {
        cout << score[i] << " ";
    }
}