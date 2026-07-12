#include <stdio.h>
#include <string.h>
struct stu
{
    char name[100];
    char id[100];
    char call[100];
};

struct stu stuInf[100];

int main()
{

    printf("输入学生个数:\n");
    int n;
    scanf("%d", &n);
    printf("分别输入这几名学生的学号姓名以及电话:\n");

    for (int i = 1; i <= n; i++)
    {
        scanf("%s%s%s", &stuInf[i].id, &stuInf[i].name, &stuInf[i].call);
    }

    int askAns = 0;
    char stuAsk[100];

    printf("输入要查询的学生名字:\n");
    scanf("%s", &stuAsk);

    int searchAns = 1;
    for (int i = 1; i <= n; i++)
    {
        searchAns = 1;

        for (int j = 0; stuAsk[j] != '\0'; j++)
        {
            if (stuAsk[j] != stuInf[i].name[j])
            {
                searchAns = 0;
                break;
            }
        }
        if (searchAns)
        {
            askAns = 1;
            printf("学号:");
            for (int q = 0; stuInf[i].id[q] != '\0'; q++)
            {
                printf("%c", stuInf[i].id[q]);
            }
            printf("\n");
            printf("电话:");
            for (int q = 0; stuInf[i].call[q] != '\0'; q++)
            {
                printf("%c", stuInf[i].calul[q]);
            }
            break;
        }
    }

    if (!askAns)
    {
        printf("未查询到该学生信息\n");
    }
}