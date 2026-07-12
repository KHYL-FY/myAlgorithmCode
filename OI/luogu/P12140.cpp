#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    int n, score = 0;
    cin >> n;

    int lun1[1002], lun2[1002], lun3[1002];
    for (int i = 1; i <= n; i++)
        cin >> lun1[i];
    for (int i = 1; i <= n; i++)
        cin >> lun2[i];
    for (int i = 1; i <= n; i++)
        cin >> lun3[i];

    int m;
    cin >> m;

    int x1, x2, x3;
    int locate1 = 1, locate2 = 1, locate3 = 1;
    int num[4];
    for (int i = 1; i <= m; i++)
    {
        cin >> x1 >> x2 >> x3;
        locate1 = (locate1 + x1) % n;
        locate2 = (locate2 + x2) % n;
        locate3 = (locate3 + x3) % n;
        if (locate1 == 0)
            locate1 = n;
        if (locate2 == 0)
            locate2 = n;
        if (locate3 == 0)
            locate3 = n;
        if (lun1[locate1] == lun2[locate2] && lun3[locate3] == lun2[locate2])
        {
            score += 200;
            continue;
        }

        if (lun1[locate1] + 1 == lun2[locate2] && lun2[locate2] + 1 == lun3[locate3])
        {
            score += 200;
            continue;
        }

        if (lun1[locate1] == lun2[locate2] || lun1[locate1] == lun3[locate3] || lun2[locate2] == lun3[locate3])
        {
            score += 100;
            continue;
        }

        num[1] = lun1[locate1];
        num[2] = lun2[locate2];
        num[3] = lun3[locate3];
        sort(num + 1, num + 4);
        if (num[1] + 1 == num[2] && num[2] + 1 == num[3])
        {
            score += 100;
            continue;
        }
    }

    cout << score;
}