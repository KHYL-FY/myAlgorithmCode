#ifndef MINEEXP
#define MINEEXP

#include <iostream>
#include <regex>

enum mineExp
{
    cityListEmpty,
    beUsedCityName,
    errorCityID,
    errorOperatorID,
    transEmpty,
    errorInfo,
    errorCityNotExist,
    errorCost,
    errorTime,
    errorTransNum
};

namespace exp
{
    void exit(mineExp e)
    {
        switch (e)
        {
        case cityListEmpty:
            std::cout << "[系统]: 城市列表为空!" << std::endl;
            break;
        case beUsedCityName:
            std::cout << "[系统]: 已有该城市!" << std::endl;
            break;
        case errorOperatorID:
            std::cout << "[系统]: 请输入正确的操作编号!" << std::endl;
            break;
        case errorCityID:
            std::cout << "[系统]: 请输入正确的城市编号!" << std::endl;
            break;
        case transEmpty:
            std::cout << "[系统]: 该城市交通信息列表为空!" << std::endl;
            break;
        case errorInfo:
            std::cout << "[系统]: 请输入正确信息!" << std::endl;
            break;
        case errorCityNotExist:
            std::cout << "[系统]: 该城市不存在!" << std::endl;
            break;
        case errorCost:
            std::cout << "[系统]: 请输入正确的费用(非负整数)!" << std::endl;
            break;
        case errorTime:
            std::cout << "[系统]: 请输入正确的时间格式!" << std::endl;
            break;
        case errorTransNum:
            std::cout << "[系统]: 请输入正确的交通编号!" << std::endl;
            break;
        }
    }
}

#endif