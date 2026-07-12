#include <stdio.h>

struct stu
{
    char id[50];
    char name[50];
    int mathScore, englScore;
    double avage;
};

struct stu class_[6];

int main()
{
    printf("分别输入5位同学的学号,姓名,数学成绩,英语成绩,平均成绩:\n");
    for (int i = 1; i <= 5; i++)
    {
        scanf("%s%s%d%d%lf", &class_[i].id, &class_[i].name, &class_[i].mathScore, &class_[i].englScore, &class_[i].avage);
    }

    for (int i = 1; i <= 5; i++)
    {
        for (int j = i; j <= 5; j++)
        {
            if (class_[i].avage < class_[j].avage)
            {
                struct stu t = class_[j];
                class_[j] = class_[i];
                class_[i] = t;
            }
        }
    }
    printf("根据平均成绩排序后为:\n");
    for (int i = 1; i <= 5; i++)
    {
        printf("%s %s %d %d %.1lf\n", class_[i].id, class_[i].name, class_[i].mathScore, class_[i].englScore, class_[i].avage);
    }
}