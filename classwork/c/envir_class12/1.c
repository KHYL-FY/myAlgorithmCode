#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numbers[10];
    int read_numbers[10];
    FILE *fp;

    printf("请输入10个整数:\n");
    for (int i = 0; i < 10; i++)
    {
        scanf("%d", &numbers[i]);
    }

    fp = fopen("data.bin", "wb");
    if (fp == NULL)
    {
        printf("无法创建文件!\n");
        return 1;
    }

    fwrite(numbers, sizeof(int), 10, fp);

    fclose(fp);

    fp = fopen("data.bin", "rb");
    if (fp == NULL)
    {
        printf("无法打开文件进行读取!\n");
        return 1;
    }

    fread(read_numbers, sizeof(int), 10, fp);

    fclose(fp);

    printf("\n从文件读取的10个整数:\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", read_numbers[i]);
    }
    printf("\n");

    return 0;
}