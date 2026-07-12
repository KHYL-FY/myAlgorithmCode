// 时间
/*

dayOfTime
    dayOfHour   时刻小时
    dayOfMinute 时刻分钟

minutes 分钟
创建时时刻自动转为分钟

int getTime() 获取分钟
int addTime() 加时间

*/
// #define DEBUG

#include <iostream>

class time
{
protected:
    
    void day_Time_To_Minutes()
    {
        minutes = dayOfTime.dayOfHour * 60 + dayOfTime.dayOfMinute;
        return;
    }
    struct
    {
        int month;
        int day;
        int dayOfHour;
        int dayOfMinute;

    } dayOfTime = {0, 0};

    int minutes = 0;

public:
    time(int h, int m) : dayOfTime{h, m}
    {
        day_Time_To_Minutes();
    }

    int getTime()
    {
        return minutes;
    }
    int addTime(int add)
    {
        minutes += add;
    }

#ifdef DEBUG

    void testout()
    {
        std::cout << "时刻:" << dayOfTime.dayOfHour << ":" << dayOfTime.dayOfMinute << std::endl;
        std::cout << "分钟:" << minutes << std::endl;
    }

#endif
};