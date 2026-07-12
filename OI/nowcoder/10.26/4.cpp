#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int score, minScore = 101, maxScore = 0, totalScore = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> score;

        totalScore += score;
        minScore = min(score, minScore);
        maxScore = max(score, maxScore);
    }

    cout << maxScore << endl
         << minScore << endl;

    float avageScore = totalScore / (float)n * 100.0;

    avageScore = round(avageScore) / 100;

    cout << fixed << setprecision(2) << avageScore;
}
