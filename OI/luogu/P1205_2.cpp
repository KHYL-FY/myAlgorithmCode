#include <iostream>
using namespace std;
int n;
char square_begin[11][11];
char square_end[11][11];

bool ans1()
{
    for (int i = 1, u = 1; i <= n; i++, u++)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                return false;
            }
        }
    }
    return true;
}

bool ans2(){
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[u][v])
            {
                return false;
            }
        }
    }
    return true;
}
bool ans3(){
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = 1; j <= n; j++, v++)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                return false;
            }
        }
    }
    return true;
}
bool ans4(){
    for (int i = 1, u = 1; i <= n; i++, u++)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[u][v])
            {
                return false;
            }
        }
    }
    return true;
}
bool ans5_1(){
    for (int i = 1, u = 1; i <= n; i++, u++)
    {
        for (int j = 1, v = 1; j <= n; j++, v++)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                return false;
            }
        }
    }
    return true;
}
bool ans5_2()
{
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = 1; j <= n; j++, v++)
        {
            if (square_end[i][j] != square_begin[u][v])
            {
                return false;
                break;
            }
        }
    }
    return true;
}
bool ans5_3()
{
    for (int i = 1, u = n; i <= n; i++, u--)
    {
        for (int j = 1, v = n; j <= n; j++, v--)
        {
            if (square_end[i][j] != square_begin[v][u])
            {
                return false;
            }
        }
    }
    return true;
}

bool ans6(){
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (square_end[i][j] != square_begin[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> square_begin[i][j];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            cin >> square_end[i][j];


    if(ans1()){
        cout <<"1";
        return 0;
    }
    if(ans2()){
        cout << "2";
        return 0;
    }
    if(ans3()){
        cout <<"3";
        return 0;
    }
    if(ans4()){
        cout<<"4";
        return 0;
    }
    if (ans5_1() || ans5_2() || ans5_3())
    {
        cout << "5";
        return 0;
    }
    if (ans6())
    {
        cout << "6";
        return 0;
    }
    cout << "7";
    return 0;
}