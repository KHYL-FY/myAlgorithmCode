#include<iostream>

using namespace std;


void sort_(int a[]){
    int t;
    for (int i = 0; i <= 9; i++)
    {
        for (int j = 0; j <= 9; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
}
int main(){
    int a[10];

    for (int i = 0; i <= 9;i++){
        cin >> a[i];
    }

    cout<<"排序前"<<endl;
    for (int i = 0; i <= 9; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    
    sort_(a);

    cout << "排序后" << endl;

    for (int i = 0; i <= 9;i++){
        cout << a[i]<<" ";
    }
}