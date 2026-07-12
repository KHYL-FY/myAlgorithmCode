#ifndef MENU
#define MENU

#include <iostream>
#include <thread>
#include <chrono>

void loadMenu();     // 加载界面
void mainMenu();     // 主菜单
void exitSaveMenu(); // 退出界面
void exitMenu();     // 退出
void mainMenuHead()
{
    std::cout << "╔════════════════════════════════════════════════════════════════════════╗" << std::endl
              << "║                                                                        ║" << std::endl
              << "║                       ☆ 全国交通咨询模拟系统 ☆                         ║" << std::endl
              << "║                                                                        ║" << std::endl
              << "╚════════════════════════════════════════════════════════════════════════╝" << std::endl;
}
void mainMenuBody()
{
    std::cout << "                                                               " << std::endl
              << "      [城市管理]                                                " << std::endl
              << "        1.查看城市列表                                          " << std::endl
              << "        2.添加城市                                              " << std::endl
              << "        3.删除城市                                              " << std::endl
              << "                                                               " << std::endl
              << "      [交通数据管理]                                            " << std::endl
              << "        4.查看城市交通信息                                      " << std::endl
              << "        5.添加列车或航班信息                                    " << std::endl
              << "        6.删除交通信息                                          " << std::endl
              << "                                                               " << std::endl
              << "      [交通咨询]                                                " << std::endl
              << "        7.最快到达查询                                          " << std::endl
              << "        8.最省钱查询                                            " << std::endl
              << "        9.中转次数最少查询                                       " << std::endl
              << "                                                                " << std::endl
              << "      [系统功能]                                               " << std::endl
              << "        0.退出                                                 " << std::endl;
}
void mainMenuFoot()
{
    std::cout << "═══════════════════════════════════════════════════════════════════════════" << std::endl;
}
void mainMenu()
{
    mainMenuHead();
    mainMenuBody();
    mainMenuFoot();
}

void exitSaveMenu()
{
    system("cls");
    mainMenuHead();
    for (int i = 1; i <= 7; i++)
        std::cout << std::endl;
    std::cout << "                             exiting.....                            " << std::endl
              << std::endl;
    std::cout << "                         正在退出并保存相关文件                        " << std::endl;
    std::cout << "                             (请勿关闭)                               " << std::endl;
    for (int i = 1; i <= 7; i++)
        std::cout << std::endl;
    std::cout << "═══════════════════════════════════════════════════════════════════════════";
}
void exitMenu()
{
    system("cls");
    mainMenuHead();
    for (int i = 1; i <= 8; i++)
        std::cout << std::endl;
    std::cout << "                             successed!                               " << std::endl;
    std::cout << "                               已退出                                 " << std::endl;
    for (int i = 1; i <= 8; i++)
        std::cout << std::endl;
    std::cout << "═══════════════════════════════════════════════════════════════════════════";
}
void loadMenu()
{

    for (int x = 1; x <= 3; x++)
    {
        system("cls");
        mainMenuHead();
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        std::cout << "                             loading.....                                 " << std::endl;
        std::cout << "                           正在加载相关文件                                 " << std::endl;
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        mainMenuFoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        system("cls");
        mainMenuHead();
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        std::cout << "                             loading....                                  " << std::endl;
        std::cout << "                           正在加载相关文件                                 " << std::endl;
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        mainMenuFoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        system("cls");
        mainMenuHead();
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        std::cout << "                             loading...                                  " << std::endl;
        std::cout << "                           正在加载相关文件                                 " << std::endl;
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        mainMenuFoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        system("cls");
        mainMenuHead();
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        std::cout << "                             loading..                                  " << std::endl;
        std::cout << "                           正在加载相关文件                                 " << std::endl;
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        mainMenuFoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));

        system("cls");
        mainMenuHead();
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        std::cout << "                             loading.                                  " << std::endl;
        std::cout << "                           正在加载相关文件                                 " << std::endl;
        for (int i = 1; i <= 8; i++)
            std::cout << std::endl;
        mainMenuFoot();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}
#endif