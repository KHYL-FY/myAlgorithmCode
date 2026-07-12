#include <iostream>
#include <map>
#include <string>

#define ll long long
using namespace std;

map<string, ll> stu;
ll stu_count = 0;
void insert_change()
{
    string name;
    ll score;
    cin >> name >> score;

    if (stu[name] > 0)
        stu[name] = score;

    else
    {
        stu[name] = score;
        stu_count++;
    }

    return;
}
void query()
{
    string name;
    cin >> name;
    if (stu[name] > 0)
        cout << stu[name]<<endl;

    else
        cout << "Not found" << endl;

    return;
}
void delete_()
{
    string name;
    cin >> name;

    if (stu[name] > 0)
    {
        cout << "Deleted successfully" << endl;
        stu[name] = 0;
        stu_count--;
    }
    else
        cout << "Not found" << endl;
}
int main()
{
    int n;
    cin >> n;
    int operation;
    for (int i = 1; i <= n; i++)
    {
        cin >> operation;
        switch (operation)
        {
        case 1:
            insert_change();
            cout << "OK" << endl;
            break;
        case 2:
            query();
            break;
        case 3:
            delete_();
            break;
        case 4:
            cout << stu_count << endl;
            break;
        }
    }
}