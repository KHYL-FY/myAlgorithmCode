#include <iostream>
#include <algorithm>
using namespace std;
struct people
{
    string name;
    int days;
    int id;
};

people classmates[150];

bool sort_(people a, people b)
{

    if (a.days == b.days)
    {
        return a.id > b.id;
    }
    else
        return a.days > b.days;
}
int main()
{
    int n, year, month, day;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> classmates[i].name >> year >> month >> day;
        classmates[i].id = i;
        classmates[i].days = (2020 - year) * 365 + (12 - month) * 30 + (31 - day);
    }

    sort(classmates + 1, classmates + 1 + n, sort_);

    for (int i = 1; i <= n; i++)
    {
        cout << classmates[i].name << endl;
    }
}