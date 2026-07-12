#include <iostream>
#include <cmath>
using namespace std;

int main(){
    double r = sqrt(233 * 233 + 666 * 666);

    long long ans = asin(666 / r)*r + r;

    cout << ans;
}