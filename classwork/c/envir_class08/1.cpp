#include <iostream>

using namespace std;

int main()
{
    int score[15][6];
    int maxscore[6];
    int minscore[6];
    for (int i = 1; i <= 5; i++)
    {
        maxscore[i] = -1;
        minscore[i] = 1e9;
    }
    cout << "请分别输入10个学生的计算机基础,C语言程序设计,英语,高数,体育成绩" << endl;

    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 5; j++)
        {
            cin >> score[i][j];
        }
    }
    for (int i = 1; i <= 5; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            if (minscore[i] > score[j][i])
            {
                minscore[i] = score[j][i];
            }
            if (maxscore[i] < score[j][i])
            {
                maxscore[i] = score[j][i];
            }
        }
    }
    cout << "五门课最高分最低分分别是" << endl;

    for (int i = 1; i <= 5;i++){
        cout << maxscore[i] << " " << minscore[i]<<endl;
    }
}