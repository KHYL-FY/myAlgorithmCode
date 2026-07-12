// 时间
#ifndef TIME
#define TIME
#include <iostream>

const int preDays[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};
const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
class Time
{
public:
    friend std::ostream &operator<<(std::ostream &cout, const Time &a)
    {
        cout << a.dayOfTime.month << "月" << a.dayOfTime.day << "日 ";

        if (a.dayOfTime.Hour < 10)
        {
            cout << "0";
            cout << a.dayOfTime.Hour;
        }
        else
            cout << a.dayOfTime.Hour;
        cout << ":";
        if (a.dayOfTime.minute < 10)
        {
            cout << "0";
            cout << a.dayOfTime.minute;
        }
        else
            cout << a.dayOfTime.minute;

        return cout;
    }
    friend std::istream &operator>>(std::istream &cin, Time &a)
    {
        cin >> a.dayOfTime.month >> a.dayOfTime.day;
        cin >> a.dayOfTime.Hour >> a.dayOfTime.minute;

        return cin;
    }
    friend bool operator<(const Time &a, const Time &b)
    {
        if (a.dayOfTime.month != b.dayOfTime.month)
            return a.dayOfTime.month < b.dayOfTime.month;
        if (a.dayOfTime.day != b.dayOfTime.day)
            return a.dayOfTime.day < b.dayOfTime.day;
        if (a.dayOfTime.Hour != b.dayOfTime.Hour)
            return a.dayOfTime.Hour < b.dayOfTime.Hour;
        return a.dayOfTime.minute < b.dayOfTime.minute;
    }
    friend bool operator!=(const Time &a, const Time &b)
    {
        return (a.dayOfTime.month != b.dayOfTime.month) || (a.dayOfTime.day != b.dayOfTime.day) || (a.dayOfTime.Hour != b.dayOfTime.Hour) || (a.dayOfTime.minute != b.dayOfTime.minute);
    }
    friend bool operator>=(const Time &a, const Time &b)
    {
        return !(a < b);
    }

    struct
    {
        int month;    //月份
        int day;      //日
        int Hour;     //小时  
        int minute;   // 分钟

    } dayOfTime;      

    int total = 0; //时间转分钟
    Time() {}
    Time(int minutes) : total(minutes) { toDayOfTime(); }

    int toMinutes()
    {
        int totalDays = preDays[dayOfTime.month] + (dayOfTime.day - 1);
        return totalDays * 24 * 60 + dayOfTime.Hour * 60 + dayOfTime.minute;
    }

    bool isValid()
    {
        if (dayOfTime.month < 1 || dayOfTime.month > 12)
            return false;
        if (dayOfTime.day < 1 || dayOfTime.day > days[dayOfTime.month])
            return false;
        if (dayOfTime.Hour < 0 || dayOfTime.Hour > 23)
            return false;
        if (dayOfTime.minute < 0 || dayOfTime.minute > 59)
            return false;
        return true;
    }

private:
    void toDayOfTime()
    {
        int totalDays = total / (24 * 60);
        dayOfTime.Hour = (total % (24 * 60)) / 60;
        dayOfTime.minute = total % 60;
        
        for (int m = 1; m <= 12; m++)
        {
            if (totalDays < preDays[m] + days[m])
            {
                dayOfTime.month = m;
                dayOfTime.day = totalDays - preDays[m] + 1;
                return;
            }
        }
    }
};

#endif