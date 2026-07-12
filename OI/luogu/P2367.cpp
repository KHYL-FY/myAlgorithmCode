#include <iostream>

using namespace std;

int main()
{
    int n, p;
    scanf("%d%d", &n, &p);

    int score[n + 5];
    int min_score = 105;

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &score[i]);
    }

    int l, r, add_score;
    for (int i = 1; i <= p; i++)
    {
        scanf("%d%d%d", &l, &r, &add_score);
        for (int j = l; j <= r; j++)
        {
            score[j] += add_score;
        }
    }

    for (int i = 1; i <= n; i++)
    {
        min_score = min(min_score, score[i]);
    }

    printf("%d",min_score);
}