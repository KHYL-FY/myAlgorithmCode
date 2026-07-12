#include <iostream>

using namespace std;
struct tree
{
    char left_child;
    char right_child;
};

tree a[150];

void tree_qianxu(char father)
{
    if (father == '*')
    {
        return;
    }

    cout << father;
    tree_qianxu(a[father].left_child);

    tree_qianxu(a[father].right_child);
}

int main()
{
    int n;
    cin >> n;
    char root, root_left, root_right;
    cin >> root;
    cin >> a[root].left_child >> a[root].right_child;

    char father;

    for (int i = 2; i <= n; i++)
    {
        cin >> father;
        cin >> a[father].left_child >> a[father].right_child;
    }

    tree_qianxu(root);
}