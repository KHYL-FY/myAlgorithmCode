#include <iostream>

#include <iomanip>

using namespace std;

class Matrix
{

private:
    int a[2][2];

    friend istream &operator>>(istream &is, Matrix &_m);

    friend ostream &operator<<(ostream &os, Matrix &_m);

    friend Matrix operator+(const Matrix &mat1, const Matrix &mat2);
};

ostream &operator<<(ostream &os, Matrix &_m)
{

    // 每个数4列 setw(4)

    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 2; j++)

            os << setw(4) << _m.a[i][j];

        os << endl;
    }

    return os;
}

/****************************************************/
istream &operator>>(istream &is, Matrix &_m)
{
    for (int i = 0; i < 2; i++)
    {

        for (int j = 0; j < 2; j++)

            is >> _m.a[i][j];
    }

    return is;
}
Matrix operator+(const Matrix &mat1, const Matrix &mat2)
{
    Matrix ans;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            ans.a[i][j] = mat1.a[i][j] + mat2.a[i][j];
        }
    }

    return ans;
}
/****************************************************/

int main()
{

    Matrix m1, m2, m;

    cout << "input matrix m1:" << endl;

    cin >> m1;

    cout << "input matrix m2:" << endl;

    cin >> m2;

    m = m1 + m2;

    cout << "output matrix m:" << endl;

    cout << m;

    return 0;
}