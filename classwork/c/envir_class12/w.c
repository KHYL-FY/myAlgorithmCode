#include <stdio.h>

struct Student
{
    char id[20];
    char name[20];
    float score[3];
    float average;
};

int main()
{
    struct Student students[5];
    FILE *fp;

    printf("请输入5名学生的信息（学号、姓名、3门课成绩）:\n");
    for (int i = 0; i < 5; i++)
    {

        scanf("%s", students[i].id);
        scanf("%s", students[i].name);
        scanf("%f %f %f", &students[i].score[0], &students[i].score[1], &students[i].score[2]);

        students[i].average = (students[i].score[0] + students[i].score[1] + students[i].score[2]) / 3.0;
    }

    fp = fopen("stud.txt", "w");
    if (fp == NULL)
    {
        printf("无法创建文件!\n");
        return 1;
    }

    fprintf(fp, "学号\t姓名\t成绩1\t成绩2\t成绩3\t平均分\n");
    for (int i = 0; i < 5; i++)
    {
        fprintf(fp, "%s\t%s\t%.1f\t%.1f\t%.1f\t%.2f\n",
                students[i].id,
                students[i].name,
                students[i].score[0],
                students[i].score[1],
                students[i].score[2],
                students[i].average);
    }

    fclose(fp);

    printf("\n数据已保存到 stud.txt 文件\n");

    printf("\n文件内容预览:\n");
    printf("学号\t姓名\t成绩1\t成绩2\t成绩3\t平均分\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%s\t%s\t%.1f\t%.1f\t%.1f\t%.2f\n",
               students[i].id,
               students[i].name,
               students[i].score[0],
               students[i].score[1],
               students[i].score[2],
               students[i].average);
    }

    return 0;
}