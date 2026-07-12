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

class Time
{
public:
    struct
    {
        int month;
        int day;
        int dayOfHour;
        int dayOfMinute;

    } dayOfTime;

    int minutes = 0;

    std::string to_string()
    {
        return "";
    }
    // public:

#ifdef DEBUG

    void testout()
    {
        std::cout << "时刻:" << dayOfTime.dayOfHour << ":" << dayOfTime.dayOfMinute << std::endl;
        std::cout << "分钟:" << minutes << std::endl;
    }

#endif
};