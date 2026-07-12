

#include <vector>
#include "Time.h"
#include <map>
#include "mineException.h"

struct info
{
    std::string startCity;
    std::string endCity;
    std::string transName;
    Time startTime;
    Time endTime;
    int cost;
};

class TransInfo
{
protected:
    virtual void add_Trans_Info() = 0;
    virtual void print_All_Info() = 0;
    virtual void erase_Trans_Info(int n) = 0;

public:
    virtual void addInfo() = 0;
    virtual void printInfo() = 0;
    virtual void eraseInfo() = 0;
};

class TrainInformation : public TransInfo
{
protected:
    void add_Trans_Info(std::string sc, std::string ec, std::string tn, Time st, Time et, int c);
    void print_All_Info();
    void erase_Trans_Info(int n);

public:

    std::vector<info> infoList;

    void addInfo(std::string &sc, std::string &ec, std::string &tn, Time &st, Time &et, int &c)
    {
        add_Trans_Info(sc, ec, tn, st, et, c);
        return;
    }
    void printInfo()
    {
        print_All_Info();

        return;
    }
    void eraseInfo(int n)
    {
        erase_Trans_Info(n);

        return;
    }
};

class PlaneInformation : public TransInfo
{
protected:
    void add_Trans_Info(std::string sc, std::string ec, std::string tn, Time st, Time et, int c);
    void print_All_Info();
    void erase_Trans_Info(int n);

public:
    // const Graph_AdjList &transNetwork;

    std::vector<info> infoList;

    void addInfo(std::string &sc, std::string &ec, std::string &tn, Time &st, Time &et, int &c)
    {
        add_Trans_Info(sc, ec, tn, st, et, c);
        return;
    }
    void printInfo()
    {
        print_All_Info();

        return;
    }
    void eraseInfo(int n)
    {
        erase_Trans_Info(n);

        return;
    }
};

class CityInformation
{
private:
    std::vector<std::string> cityList;
    std::map<std::string, bool> cityUsed;

    void add_City_Information(const std::string &cityName);
    void delete_City_Information(const int &n);
    void print_All_City_Information();

public:
    void addCity(const std::string &cityName)
    {
        add_City_Information(cityName);

        return;
    }
    void deleteCity(const int &n)
    {
        delete_City_Information(n);

        return;
    }
    void printCityList()
    {
        print_All_City_Information();

        return;
    }
};

void TrainInformation::add_Trans_Info(std::string sc, std::string ec, std::string tn, Time st, Time et, int c)
{
    infoList.push_back({sc, ec, tn, st, et, c});

    return;
}
void TrainInformation::print_All_Info()
{
    int p = 0;
    for (auto i = infoList.begin(); i != infoList.end(); i++)
    {
        p++;
        std::cout << p << ".";

        std::cout << "火车 ";

        std::cout << (*i).startCity << "--->" << (*i).endCity << "  ";
        std::cout << (*i).transName << " " << (*i).startTime.to_string() << " ";
        std::cout << "费用:" << (*i).cost << "元" << std::endl;
    }

    return;
}

void TrainInformation::erase_Trans_Info(int n)
{
    infoList.erase(infoList.begin() + n);
    return;
}


void PlaneInformation::add_Trans_Info(std::string sc, std::string ec, std::string tn, Time st, Time et, int c)
{
    infoList.push_back({sc, ec, tn, st, et, c});

    return;
}
void PlaneInformation::print_All_Info()
{
    int p = 0;
    for (auto i = infoList.begin(); i != infoList.end(); i++)
    {
        p++;
        std::cout << p << ".";

        std::cout << "飞机 ";

        std::cout << (*i).startCity << "--->" << (*i).endCity << "  ";
        std::cout << (*i).transName << " " << (*i).startTime.to_string() << " ";
        std::cout << "费用:" << (*i).cost << "元" << std::endl;
    }

    return;
}

void PlaneInformation::erase_Trans_Info(int n)
{
    infoList.erase(infoList.begin() + n);
    return;
}

void CityInformation::add_City_Information(const std::string &cityName)
{
    if (cityUsed[cityName])
    {
        exp::exit(beUsedCityName);
        return;
    }
    else
    {
        // 这里要在graph同步实现添加
        cityUsed[cityName] = true;
        cityList.push_back(cityName);
    }
}

void CityInformation::delete_City_Information(const int &n)
{
    // 这里要在graph同步实现删除
    cityUsed[cityList[n]] = false;
    cityList.erase(cityList.begin() + n);
}
void CityInformation::print_All_City_Information()
{
    if (cityList.empty())
    {
        exp::exit(cityListEmpty);
        return;
    }
    int p = 0;
    for (auto i = cityList.begin(); i != cityList.end(); i++)
    {
        p++;
        std::cout << p << ".";
        std::cout << *i << " " << std::endl;
    }
}