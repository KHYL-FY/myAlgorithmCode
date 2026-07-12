#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct tree
{
    string eval;
    int id;
};
tree version[100005];

bool cmp(tree a, tree b)
{
    if (a.eval == b.eval)
    {
        return a.id < b.id;
    }
    else
    {
        return a.eval < b.eval;
    }
}
int main()
{
    int t;
    cin >> t;
    int n, pre;
    char a;
    while (t--)
    {
        cin >> n;
        version[1].eval = "";
        version[1].id = 1;
        for (int i = 2; i <= n; i++)
        {
            cin >> pre >> a;
            if (version[pre].eval != "")
                version[i].eval += version[pre].eval;
            version[i].eval += a;
            version[i].id = i;
        }

        sort(version + 2, version + n + 1, cmp);

        for (int i = 1; i <= n;i++){
            //cout << version[i].eval << " ";
            cout << version[i].id<<" ";
        }
        cout << endl;

        // for (int i = 1; i <= n; i++)
        // {
        //     cout << version[i].eval << " " << version[i].id << endl;
        // }
        for (int i = 1; i <= n; i++)
        {
            version[i].eval.clear();
        }
    }
}