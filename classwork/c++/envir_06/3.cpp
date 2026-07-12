#include <iostream>

using namespace std;

class Time
{

public:
    Time(int h, int min, int s)
    {

        hours = h;

        minutes = min;

        seconds = s;
    }

    void display()
    {

        cout << "出生时间:" << hours << "时" << minutes << "分" << seconds << "秒" << endl;
    }

protected:
    int hours, minutes, seconds;
};

class Date
{

public:
    Date(int y, int mon, int d)
    {

        year = y;

        month = mon;

        day = d;
    }

    void display()
    {

        cout << "出生日期:" << year << "年" << month << "月" << day << "日" << endl;
    }

protected:
    int year, month, day;
};

class Birth : public Date, public Time
{
private:
    string childname;

public:
    Birth(string name, int y, int mon, int d, int h, int min, int s);

    void show();
};

/********************************************************************/
Birth::Birth(string name, int y, int mon, int d, int h, int min, int s) : Date(y, mon, d), Time(h, min, s), childname(name)
{
}
void Birth::show()
{
    cout << "姓名:" << childname << endl;
    Date::display();
    Time::display();
}
/********************************************************************/

int main()
{

    Birth birth("李雷", 2003, 7, 1, 13, 10, 10);

    birth.show();

    return 0;
}