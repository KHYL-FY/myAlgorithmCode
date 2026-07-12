//月份天数的前缀和

const int preDays[] = {0, 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

//所有月份对应的天数

const int days[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

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