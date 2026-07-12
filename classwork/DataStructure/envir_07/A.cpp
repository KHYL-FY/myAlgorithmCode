#include <iostream>
using namespace std;

// 自定义类型
typedef int KeyType;
typedef struct
{
    KeyType key;
} ElemType;

#define MAXSIZE 100
typedef struct
{
    ElemType R[MAXSIZE];
    int length;
} SSTable;

// 折半查找 非递归算法
int Search_Bin(SSTable ST, KeyType kval)
{
    int low = 1;
    int high = ST.length;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (kval == ST.R[mid].key)
            return mid; // 查找成功，返回位置
        else if (kval < ST.R[mid].key)
            high = mid - 1; // 在前半区查找
        else
            low = mid + 1; // 在后半区查找
    }
    return 0; // 查找失败
}

int main()
{
    // 班级姓名
    cout << "===== 班级：XXX 姓名：XXX 折半查找实验 =====" << endl;
    SSTable ST;
    int arr[8] = {5, 14, 18, 21, 23, 29, 31, 35};
    ST.length = 8;

    // 存入顺序表，下标从1开始（符合实验代码习惯）
    for (int i = 1; i <= 8; i++)
    {
        ST.R[i].key = arr[i - 1];
    }

    // 输出原始序列
    cout << "原始关键字序列：";
    for (int i = 1; i <= ST.length; i++)
    {
        cout << ST.R[i].key << " ";
    }
    cout << endl;

    // 查找 key=21
    int key1 = 21;
    int pos = Search_Bin(ST, key1);
    if (pos != 0)
        cout << "查找 " << key1 << " 成功，位置：" << pos << endl;
    else
        cout << "查找 " << key1 << " 失败" << endl;

    // 查找 key=25
    int key2 = 25;
    pos = Search_Bin(ST, key2);
    if (pos != 0)
        cout << "查找 " << key2 << " 成功，位置：" << pos << endl;
    else
        cout << "查找 " << key2 << " 失败" << endl;

    return 0;
}