

#include "transInformation.h"
#include "menu.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <regex>
#include "mineException.h"

TransInformation infoList;
enum menuOperator
{
    printCityList = 1,
    addCity,
    deleteCity,

    printCityTransInfo,
    addTransInfo,
    deleteTransInfo,

    searchFastest,
    searchCheapest,
    searchLeastTransfer,
    exitCode = 0

};
std::regex isNumber(R"(\d+)");

void load();
void systemPrintCityList();
void next();
void save();

int main()
{
    // loadMenu();
    load();

    menuOperator userOperator;
    std::string inputStr;

    int input;

    while (1)
    {
        system("cls");
        mainMenu();
        std::cout << "[系统]: 输入要进行的操作 --->  ";
        std::cin >> inputStr;
        if (!regex_match(inputStr, isNumber))
        {
            exp::exit(errorOperatorID);
            next();
            continue;
        }
        else
        {
            input = stoi(inputStr);
            if (input < 0 || input > 9)
            {
                exp::exit(errorOperatorID);
                next();
                continue;
            }
        }

        userOperator = static_cast<menuOperator>(input);
        switch (userOperator)
        {
        case printCityList:
        {
            systemPrintCityList();
        }

        break;
        case addCity:
        {
            system("cls");
            mainMenu();

            std::cout << "[系统]: 请输入要添加的城市名称  --->  ";
            std::string cityName;
            std::cin >> cityName;
            if (infoList.addCity(cityName))
            {
                systemPrintCityList();

                std::cout << "[系统]: 添加成功" << std::endl;
            }
        }
        break;
        case deleteCity:
        {
            systemPrintCityList();

            std::cout << "[系统]: 输入要删除的城市对应的号码  --->  ";
            std::string nStr;
            std::cin >> nStr;
            if (infoList.deleteCity(nStr))
            {
                systemPrintCityList();
                std::cout << "[系统]: 删除成功" << std::endl;
            }
        }
        break;

        case addTransInfo:
        {
            system("cls");
            mainMenu();
            info a;
            std::string strcin;
            std::cout << "[系统]: 输入出行方式  --->  ";
            std::cin >> strcin;
            if (strcin != "火车" && strcin != "飞机")
            {
                exp::exit(errorInfo);
                next();
                continue;
            }
            a.way = strcin;

            std::cout << "[系统]: 输入起点和终点  --->  ";
            std::cin >> a.startCity >> a.endCity;
            if (!infoList.cityExists(a.startCity) || !infoList.cityExists(a.endCity))
            {
                exp::exit(errorCityNotExist);
                next();
                continue;
            }

            std::cout << "[系统]: 输入飞机班号或列车车次  --->  ";
            std::cin >> a.transName;

            std::cout << "[系统]: 输入起点的时间,24小时制,只需输入数字(X月X日 XX:XX)  --->  ";
            std::cin >> a.startTime;
            if (std::cin.fail() || !a.startTime.isValid())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                exp::exit(errorTime);
                next();
                continue;
            }

            std::cout << "[系统]: 输入终点的时间,24小时制,只需输入数字(X月X日 XX:XX)  --->  ";
            std::cin >> a.endTime;
            if (std::cin.fail() || !a.endTime.isValid())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                exp::exit(errorTime);
                next();
                continue;
            }

            std::cout << "[系统]: 输入费用  --->  ";
            std::cin >> a.cost;
            if (std::cin.fail() || a.cost < 0)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                exp::exit(errorCost);
                next();
                continue;
            }

            infoList.addTrans(a);
        }
        break;
        case printCityTransInfo:
        {
            systemPrintCityList();

            std::cout << "[系统]: 输入要输出的城市编号  --->  ";
            int n;
            std::cin >> n;
            if (std::cin.fail() || n <= 0 || n > infoList.getCityCount())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                exp::exit(errorCityID);
                next();
                continue;
            }

            system("cls");
            mainMenuHead();
            infoList.printTrans(n);
            mainMenuFoot();
        }
        break;
        case deleteTransInfo:
        {
            // 写异常
            systemPrintCityList();

            std::cout << "[系统]: 输入要删除的航班或车次起点所在城市编号  --->  ";
            int n;
            std::cin >> n;
            if (std::cin.fail() || n <= 0 || n > infoList.getCityCount())
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                exp::exit(errorCityID);
                next();
                continue;
            }

            system("cls");
            mainMenuHead();
            infoList.printTrans(n);
            mainMenuFoot();
            std::cout << "[系统]: 输入要删除的航班或车次的编号  --->  ";
            int m;
            std::cin >> m;
            if (std::cin.fail() || m <= 0)
            {
                std::cin.clear();
                std::cin.ignore(10000, '\n');
                exp::exit(errorTransNum);
                next();
                continue;
            }
            infoList.deleteTrans(n, m);
            std::cout << "[系统]: 删除成功" << std::endl;
        }
        break;
        case searchCheapest:
        {
            // 写异常
            systemPrintCityList();

            std::string start, end;
            std::cout << "[系统]: 输入要查询的两座城市  --->  ";
            std::cin >> start >> end;
            if (!infoList.cityExists(start) || !infoList.cityExists(end))
            {
                exp::exit(errorCityNotExist);
                next();
                continue;
            }
            std::cout << "[系统]:" << std::endl;
            infoList.searchCheapest(start, end);
        }
        break;
        case searchFastest:
        {
            systemPrintCityList();

            std::string start, end;
            std::cout << "[系统]: 输入要查询的两座城市  --->  ";
            std::cin >> start >> end;
            if (!infoList.cityExists(start) || !infoList.cityExists(end))
            {
                exp::exit(errorCityNotExist);
                next();
                continue;
            }
            std::cout << "[系统]:" << std::endl;
            infoList.searchFastest(start, end);
        }
        break;
        case searchLeastTransfer:
        {
            systemPrintCityList();

            std::string start, end;
            std::cout << "[系统]: 输入要查询的两座城市  --->  ";
            std::cin >> start >> end;
            if (!infoList.cityExists(start) || !infoList.cityExists(end))
            {
                exp::exit(errorCityNotExist);
                next();
                continue;
            }
            std::cout << "[系统]:" << std::endl;
            infoList.searchLeastTransfer(start, end);
        }
        break;
        case exitCode:
        {
            save();
            system("cls");
            exitMenu();
            return 0;
        }
        }

        next();
    }
}

void load()
{
    std::ifstream inFile("city.txt");
    if (inFile.is_open())
    {
        std::string cityName;
        while (getline(inFile, cityName))
        {
            infoList.addCity(cityName);
        }
    }
    else
    {
        std::cout << "城市信息文件打开失败" << std::endl;
    }

    std::ifstream inFile2("trans.txt");
    if (inFile2.is_open())
    {

        info a;
        while (inFile2 >> a)
        {
            infoList.addTrans(a);
        }
    }
    else
    {
        std::cout << "交通信息文件打开失败" << std::endl;
    }
    return;
}
void systemPrintCityList()
{
    system("cls");
    mainMenuHead();
    infoList.printCity();
    mainMenuFoot();
}
void next()
{

    std::string a;
    bool flag = false;
    while (!flag)
    {
        std::cout << "[系统]: 输入 0 返回 --->  ";
        std::cin >> a;
        if (regex_match(a, isNumber) && stoi(a) == 0)
        {
            flag = true;
            system("cls");
        }
        else
            exp::exit(errorOperatorID);
    }
}
void save()
{
    system("cls");
    exitSaveMenu();
    infoList.saveToFile();
    std::this_thread::sleep_for(std::chrono::seconds(1));
}