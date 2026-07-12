#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
//java jaav jvaa vjaa ajva ajav aajv vaja avja vaaj avaj aavj
int main()
{
    int n;
    string a;
    cin >> n;
    while (n)
    {
        n--;
        cin >> a;
        if (a == "JAVA" || a == "JAAV" || a == "JVAA" || a == "VJAA" || a == "AJVA" || a == "AJAV" || a == "AAJV" || a == "VAJA" || a == "AVJA" || a == "VAAJ" || a == "AVAJ" || a == "AAVJ")
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
}