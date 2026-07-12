#include <iostream>
#include <cstring>

using namespace std;
#define ll long long

bool houmaxstring(string a, string b)

{
    ll alen = a.length(), blen = b.length();
    if (alen != blen)
    {
        return alen < blen;
    }
    else
    {
        ll i = 0;
        while (i < alen)
        {
            if (a[i] < b[i])
                return a[i] < b[i];
            else if (a[i] > b[i])
                return a[i] > b[i];

            i++;
        }
    }
    return false;
}

string subtraction(string a, string b)
{
    bool fu = false;
    if (houmaxstring(a, b))
    {
        swap(a, b);
        fu = true;
    }

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

    int result[10089] = {0};

    for (int i = 0; i < max(len_a, len_b); i++)
    {
        if ((a[i] - '0') - (b[i] - '0') < 0)
        {
            a[i + 1]--;
            a[i] += 10;
        }
        result[i] = result[i] + (a[i] - '0') - (b[i] - '0');
    }

    int len_result = max(len_a, len_b) + 1;
    while (len_result > 1 && result[len_result - 1] == 0)
        len_result--;

    string result_str;
    if (fu == true)
    {
        result_str += '-';
    }
    for (int i = len_result - 1; i >= 0; i--)
    {
        result_str += (result[i] + '0');
    }

    return result_str;
}

int main()
{
    string a, b, c;
    cin >> a >> b;

    c = subtraction(a, b);
    cout << c;
}