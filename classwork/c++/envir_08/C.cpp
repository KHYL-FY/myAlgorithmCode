#include <iostream>

using namespace std;

/****************************************************/

// 函数模板max_arr
template <typename maxArray>
maxArray max_arr(const maxArray a[], const int r)
{
    maxArray _max = a[0];

    for (int i = 1; i < r; i++)
        _max = max(_max, a[i]);

    return _max;
}

/****************************************************/

int main()
{

    int a[5], k;

    for (k = 0; k < 5; k++)

        cin >> a[k];

    cout << "max=" << max_arr<int>(a, 5) << endl;
}