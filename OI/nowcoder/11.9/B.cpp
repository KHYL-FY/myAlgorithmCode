#include <bits/stdc++.h>

using namespace std;

int main()
{
    int l1, l2, r1, r2;
    int n;
    cin >> n;

    for (int i = 1; i <= n;i++){
        
        cin >> l1 >> r1 >> l2 >> r2;
        
        if((l2<l1&&r1<r2)||(l1<l2&&r2<r1)){
            cout << "A" << endl;
        }
        else if(r1<l2||l1>r2){
            cout << "B" << endl;
        }
        else{
            cout << "C" << endl;
        }
    }
}