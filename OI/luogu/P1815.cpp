#include <iostream>
#include <deque>
using namespace std;

deque<pair<int, int>> worm;
bool mapp[55][55];
bool ifitself(char dir, char head, int i)
{
    switch (dir)
    {
    case 'E':
        if (head == 'W')
        {
            cout << "The worm ran into itself on move " << i << "." << endl;
            return true;
        }
        break;
    case 'W':
        if (head == 'E')
        {
            cout << "The worm ran into itself on move " << i << "." << endl;
            return true;
        }
        break;
    case 'S':
        if (head == 'N')
        {
            cout << "The worm ran into itself on move " << i << "." << endl;
            return true;
        }
        break;
    case 'N':
        if (head == 'S')
        {
            cout << "The worm ran into itself on move " << i << "." << endl;
            return true;
        }
        break;
    }

    return false;
}
int main()
{
    int n;
    cin >> n;
    char head = 'E';
    string dir;
    while (n != 0)
    {
        head = 'E';
        worm.clear();
        for (int i = 1; i <= 50; i++)
            for (int j = 1; j <= 50; j++)
                mapp[i][j] = false;
        for (int i = 30; i >= 11; i--)
        {
            worm.push_back({25, i});
            mapp[25][i] = true;
        }
        cin >> dir;
        for (int i = 0; i < n; i++)
        {
            if (ifitself(dir[i], head, i + 1))
                break;

            auto next = worm.front();

            // cout << next.first << " " << next.second << endl;
            switch (dir[i])
            {
            case 'E':
                next.second++;
                head = 'E';
                break;
            case 'W':
                next.second--;
                head = 'W';
                break;
            case 'S':
                next.first++;
                head = 'S';
                break;
            case 'N':
                next.first--;
                head = 'N';
                break;
            }

            // for (int x = 1; x <= 50; x++)
            // {
            //     for (int y = 1; y <= 50; y++)
            //     {
            //         cout << mapp[x][y] << " ";
            //     }
            //     cout << endl;
            // }

            if (next.first >= 1 && next.first <= 50 && next.second >= 1 && next.second <= 50)
            {

                auto last = worm.back();
                worm.pop_back();
                mapp[last.first][last.second] = false;
                worm.push_front(next);
            }
            else
            {
                cout << "The worm ran off the board on move " << i + 1 << "." << endl;
                break;
            }
            if (mapp[next.first][next.second])
            {
                cout << "The worm ran into itself on move " << i + 1 << "." << endl;
                break;
            }
            mapp[next.first][next.second] = true;

            // if(i==10){

            //     for (int x = 1; x <= 50; x++)
            //     {
            //         for (int y = 1; y <= 50; y++)
            //         {
            //             cout << mapp[x][y] << " ";
            //         }
            //         cout << endl;
            //     }
            // }

            if (i == n - 1)
            {
                cout << "The worm successfully made all " << i + 1 << " moves." << endl;
            }
        }

        cin >> n;
    }
}