#include <iostream>

using namespace std;

int main()
{
    int x, y, z;
    cin >> x >> y >> z;
    int g = 0;
    g = min(min(x, y), z);

    while (g)
    {
        if (x % g==0 && y % g==0 && z % g==0){
            cout << g;
            return 0;
        }
        g--;
    }
}
