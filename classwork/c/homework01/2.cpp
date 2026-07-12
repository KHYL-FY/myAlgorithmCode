#include <iostream>

using namespace std;

int main()
{
    for (int x = 0; x <= 20; x++)
    {
        for (int y = 0; y <= 33; y++)
        {
            for (int z = 0; z <= 100; z += 3)
            {
                if (x * 5 + y * 3 + z / 3 == 100 && x + y + z == 100)
                {
                    cout << "公鸡:" << x << " 母鸡:" << y << " 小鸡:" << z << endl;
                }
            }
        }
    }
}