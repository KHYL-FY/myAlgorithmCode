#include <iostream>

using namespace std;

int main()
{
    int num;
    cin >> num;
    int ge = 0, shi = 0, bai = 0, qian = 0;

    ge = num % 10;
    num /= 10;
    shi = num % 10;
    num /= 10;
    bai = num % 10;
    num /= 10;
    qian = num % 10;

    if (qian == 0 && bai == 0 && shi == 0)
    {
        cout << "1位数" << endl
             << ge;
    }
    else if (qian == 0 && bai == 0)
    {
        cout << "2位数" << endl
             << shi << " " << ge;
    }
    else if (qian == 0)
    {
        cout << "3位数" << endl
             << bai << " " << shi << " " << ge;
    }
    else
    {
        cout << "4位数" << endl
             << qian << " " << bai << " " << shi << " " << ge;
    }
}