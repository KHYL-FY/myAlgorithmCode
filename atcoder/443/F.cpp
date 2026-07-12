#include <iostream>
#include <cstring>

using namespace std;

string addition(string a, string b)
{
    int len_a = a.length();
    int len_b = b.length();

    for (int i = 0; i < len_a / 2; i++)
    {
        swap(a[i], a[len_a - 1 - i]);
    }
    for (int i = 0; i < len_b / 2; i++)
    {
        swap(b[i], b[len_b - 1 - i]);
    }

    if (len_a < len_b)
        a.insert(len_a, len_b - len_a, '0');
    else
        b.insert(len_b, len_a - len_b, '0');

    int result[10000] = {0};
    for (int i = 0; i < max(len_a, len_b); i++)
    {
        result[i] += (a[i] - '0') + (b[i] - '0');
        result[i + 1] += result[i] / 10;
        result[i] %= 10;
    }

    int len_result = max(len_a, len_b) + 1;
    while (len_result > 1 && result[len_result - 1] == 0)
        len_result--;

    string result_str;
    for (int i = len_result - 1; i >= 0; i--)
    {
        result_str += (result[i] + '0');
    }

    return result_str;
}
bool goodnum(string a)
{
    long long len_a = a.length();
    for (long long i = 0; i < len_a / 2; i++)
        swap(a[i], a[len_a - 1 - i]);
    for (long long i = 0; i < len_a - 1; i++)
        if (a[i] < a[i + 1])
            return false;

    return true;
}
int main()
{
    string a, b, c;
    long long num;

    cin >> num;
    
    return 0;
}