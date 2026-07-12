#include <iostream>
#include <fstream>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <vector>
#include <algorithm>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

// ==================== 数据结构定义 ====================

// 历史记录条目
struct HistoryItem
{
    string title;
    string url;
    string timestamp;
    int visitCount;

    HistoryItem() : visitCount(0) {}
    HistoryItem(string t, string u, string ts, int vc = 1)
        : title(t), url(u), timestamp(ts), visitCount(vc) {}
};

// 收藏夹条目
struct FavoriteItem
{
    string title;
    string url;
    string category;

    FavoriteItem() {}
    FavoriteItem(string t, string u, string c)
        : title(t), url(u), category(c) {}
};

// 哈希表节点（链地址法）
struct HashNode
{
    FavoriteItem data;
    HashNode *next;

    HashNode(const FavoriteItem &item) : data(item), next(nullptr) {}
};

// ==================== 哈希表类 ====================

class HashSet
{
private:
    vector<HashNode *> table;
    int size;
    int itemCount;
    static const int INITIAL_CAPACITY = 16;
    static const double LOAD_FACTOR_THRESHOLD;

    // 哈希函数
    int hashFunction(const string &key)
    {
        unsigned long hash = 0;
        for (char c : key)
        {
            hash = hash * 31 + c;
        }
        return hash % table.size();
    }

    // 扩容
    void resize()
    {
        int newCapacity = table.size() * 2;
        vector<HashNode *> newTable(newCapacity, nullptr);

        // 重新哈希所有元素
        for (auto head : table)
        {
            HashNode *curr = head;
            while (curr)
            {
                int newIndex = 0;
                unsigned long hash = 0;
                for (char c : curr->data.url)
                {
                    hash = hash * 31 + c;
                }
                newIndex = hash % newCapacity;

                HashNode *newNode = new HashNode(curr->data);
                newNode->next = newTable[newIndex];
                newTable[newIndex] = newNode;

                curr = curr->next;
            }
        }

        // 释放旧表
        for (auto head : table)
        {
            HashNode *curr = head;
            while (curr)
            {
                HashNode *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }

        table = move(newTable);
    }

public:
    HashSet() : size(INITIAL_CAPACITY), itemCount(0)
    {
        table.resize(size, nullptr);
    }

    ~HashSet()
    {
        for (auto head : table)
        {
            HashNode *curr = head;
            while (curr)
            {
                HashNode *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }

    // 插入
    bool insert(const FavoriteItem &item)
    {
        if (contains(item.url))
        {
            return false;
        }

        // 检查是否需要扩容
        if ((double)itemCount / table.size() > LOAD_FACTOR_THRESHOLD)
        {
            resize();
        }

        int index = hashFunction(item.url);
        HashNode *newNode = new HashNode(item);
        newNode->next = table[index];
        table[index] = newNode;
        itemCount++;
        return true;
    }

    // 查找（按URL精确查找）
    bool find(const string &url, FavoriteItem &result)
    {
        int index = hashFunction(url);
        HashNode *curr = table[index];
        while (curr)
        {
            if (curr->data.url == url)
            {
                result = curr->data;
                return true;
            }
            curr = curr->next;
        }
        return false;
    }

    // 删除
    bool remove(const string &url)
    {
        int index = hashFunction(url);
        HashNode *curr = table[index];
        HashNode *prev = nullptr;

        while (curr)
        {
            if (curr->data.url == url)
            {
                if (prev)
                {
                    prev->next = curr->next;
                }
                else
                {
                    table[index] = curr->next;
                }
                delete curr;
                itemCount--;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    // 修改
    bool update(const string &oldUrl, const FavoriteItem &newItem)
    {
        if (oldUrl != newItem.url && contains(newItem.url))
        {
            return false;
        }
        if (remove(oldUrl))
        {
            return insert(newItem);
        }
        return false;
    }

    // 检查是否包含
    bool contains(const string &url)
    {
        FavoriteItem dummy;
        return find(url, dummy);
    }

    // 按分类标签查找
    vector<FavoriteItem> findByCategory(const string &category)
    {
        vector<FavoriteItem> result;
        for (auto head : table)
        {
            HashNode *curr = head;
            while (curr)
            {
                if (curr->data.category == category)
                {
                    result.push_back(curr->data);
                }
                curr = curr->next;
            }
        }
        return result;
    }

    // 按关键词搜索（标题或URL包含）
    vector<FavoriteItem> searchByKeyword(const string &keyword)
    {
        vector<FavoriteItem> result;
        for (auto head : table)
        {
            HashNode *curr = head;
            while (curr)
            {
                if (curr->data.title.find(keyword) != string::npos ||
                    curr->data.url.find(keyword) != string::npos)
                {
                    result.push_back(curr->data);
                }
                curr = curr->next;
            }
        }
        return result;
    }

    // 获取所有条目
    vector<FavoriteItem> getAll()
    {
        vector<FavoriteItem> result;
        for (auto head : table)
        {
            HashNode *curr = head;
            while (curr)
            {
                result.push_back(curr->data);
                curr = curr->next;
            }
        }
        return result;
    }

    int getCount() { return itemCount; }

    void clear()
    {
        for (auto head : table)
        {
            HashNode *curr = head;
            while (curr)
            {
                HashNode *temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
        fill(table.begin(), table.end(), nullptr);
        itemCount = 0;
    }
};

const double HashSet::LOAD_FACTOR_THRESHOLD = 0.75;

// ==================== 浏览器管理器类 ====================

class BrowserManager
{
private:
    stack<HistoryItem> backStack;
    stack<HistoryItem> forwardStack;
    queue<HistoryItem> historyQueue;
    HashSet favorites;
    HistoryItem currentPage; // 当前显示的页面

    // 获取当前时间戳
    string getCurrentTimestamp()
    {
        time_t now = time(nullptr);
        tm *t = localtime(&now);
        stringstream ss;
        ss << put_time(t, "%Y-%m-%d %H:%M:%S");
        return ss.str();
    }

    // 从栈中删除指定URL的记录
    void removeFromStack(stack<HistoryItem> &st, const string &url, stack<HistoryItem> &temp)
    {
        while (!st.empty())
        {
            HistoryItem item = st.top();
            st.pop();
            if (item.url != url)
            {
                temp.push(item);
            }
        }
        while (!temp.empty())
        {
            st.push(temp.top());
            temp.pop();
        }
    }

    // 从队列中删除指定URL的记录
    void removeFromQueue(const string &url)
    {
        queue<HistoryItem> temp;
        while (!historyQueue.empty())
        {
            HistoryItem item = historyQueue.front();
            historyQueue.pop();
            if (item.url != url)
            {
                temp.push(item);
            }
        }
        historyQueue = temp;
    }

public:
    BrowserManager()
    {
        loadFromFile();
    }

    ~BrowserManager()
    {
        saveToFile();
    }

    // 访问新网页
    void visitNewPage()
    {
        string title, url;
        cout << "请输入页面标题: ";
        cin.ignore();
        getline(cin, title);
        cout << "请输入URL: ";
        getline(cin, url);

        // 创建历史记录
        HistoryItem newItem(title, url, getCurrentTimestamp(), 1);

        // 将当前页面压入后退栈
        if (currentPage.url != "")
        {
            backStack.push(currentPage);
        }

        // 清空前进栈
        while (!forwardStack.empty())
        {
            forwardStack.pop();
        }

        // 设置当前页面
        currentPage = newItem;

        // 加入历史队列
        historyQueue.push(newItem);
        if (historyQueue.size() > 50)
        {
            historyQueue.pop();
        }

        cout << "已访问: " << title << endl;
    }

    // 后退
    void goBack()
    {
        if (backStack.empty())
        {
            cout << "无法后退！已经是第一页了。" << endl;
            return;
        }

        // 将当前页面压入前进栈
        forwardStack.push(currentPage);

        // 后退到上一个页面
        currentPage = backStack.top();
        backStack.pop();

        // 更新访问次数
        updateVisitCount(currentPage.url);

        cout << "后退到: " << currentPage.title << endl;
    }

    // 前进
    void goForward()
    {
        if (forwardStack.empty())
        {
            cout << "无法前进！已经是最后一页了。" << endl;
            return;
        }

        // 将当前页面压入后退栈
        backStack.push(currentPage);

        // 前进到下一个页面
        currentPage = forwardStack.top();
        forwardStack.pop();

        // 更新访问次数
        updateVisitCount(currentPage.url);

        cout << "前进到: " << currentPage.title << endl;
    }

    // 更新访问次数
    void updateVisitCount(const string &url)
    {
        queue<HistoryItem> temp;
        while (!historyQueue.empty())
        {
            HistoryItem item = historyQueue.front();
            historyQueue.pop();
            if (item.url == url)
            {
                item.visitCount++;
            }
            temp.push(item);
        }
        historyQueue = temp;
    }

    // 查看历史
    void viewHistory()
    {
        if (historyQueue.empty())
        {
            cout << "暂无历史记录。" << endl;
            return;
        }

        cout << "\n=== 历史记录（按时间顺序）===" << endl;
        queue<HistoryItem> temp = historyQueue;
        int index = 1;
        while (!temp.empty())
        {
            HistoryItem item = temp.front();
            temp.pop();
            cout << index++ << ". 标题: " << item.title << endl;
            cout << "   URL: " << item.url << endl;
            cout << "   时间: " << item.timestamp << endl;
            cout << "   访问次数: " << item.visitCount << endl;
            cout << "   ---" << endl;
        }
    }

    // 搜索历史
    void searchHistory()
    {
        string keyword;
        cout << "请输入搜索关键词（标题或URL包含）: ";
        cin.ignore();
        getline(cin, keyword);

        queue<HistoryItem> temp = historyQueue;
        vector<HistoryItem> results;
        while (!temp.empty())
        {
            HistoryItem item = temp.front();
            temp.pop();
            if (item.title.find(keyword) != string::npos ||
                item.url.find(keyword) != string::npos)
            {
                results.push_back(item);
            }
        }

        if (results.empty())
        {
            cout << "未找到匹配的历史记录。" << endl;
            return;
        }

        cout << "\n=== 搜索结果 ===" << endl;
        for (size_t i = 0; i < results.size(); i++)
        {
            cout << i + 1 << ". 标题: " << results[i].title << endl;
            cout << "   URL: " << results[i].url << endl;
            cout << "   时间: " << results[i].timestamp << endl;
            cout << "   ---" << endl;
        }
    }

    // 删除历史记录
    void deleteHistory()
    {
        if (historyQueue.empty())
        {
            cout << "暂无历史记录可删除。" << endl;
            return;
        }

        string url;
        cout << "请输入要删除的历史记录的URL: ";
        cin.ignore();
        getline(cin, url);

        // 检查是否存在
        queue<HistoryItem> temp = historyQueue;
        bool found = false;
        while (!temp.empty())
        {
            if (temp.front().url == url)
            {
                found = true;
                break;
            }
            temp.pop();
        }

        if (!found)
        {
            cout << "未找到该历史记录。" << endl;
            return;
        }

        // 从后退栈删除
        stack<HistoryItem> tempStack;
        removeFromStack(backStack, url, tempStack);

        // 从前进栈删除
        removeFromStack(forwardStack, url, tempStack);

        // 从队列删除
        removeFromQueue(url);

        // 如果删除的是当前页面
        if (currentPage.url == url && !historyQueue.empty())
        {
            if (!backStack.empty())
            {
                currentPage = backStack.top();
                backStack.pop();
            }
            else if (!historyQueue.empty())
            {
                currentPage = historyQueue.back();
            }
        }

        cout << "已成功删除历史记录。" << endl;
    }

    // 修改历史记录标题
    void modifyHistory()
    {
        if (historyQueue.empty())
        {
            cout << "暂无历史记录可修改。" << endl;
            return;
        }

        string url, newTitle;
        cout << "请输入要修改的历史记录的URL: ";
        cin.ignore();
        getline(cin, url);

        queue<HistoryItem> temp;
        bool found = false;
        while (!historyQueue.empty())
        {
            HistoryItem item = historyQueue.front();
            historyQueue.pop();
            if (item.url == url)
            {
                found = true;
                cout << "请输入新标题: ";
                getline(cin, newTitle);
                item.title = newTitle;

                // 更新当前页面
                if (currentPage.url == url)
                {
                    currentPage.title = newTitle;
                }
            }
            temp.push(item);
        }
        historyQueue = temp;

        if (!found)
        {
            cout << "未找到该历史记录。" << endl;
        }
        else
        {
            cout << "标题修改成功！" << endl;
        }
    }

    // ==================== 收藏夹管理 ====================

    // 添加收藏
    void addFavorite()
    {
        string title, url, category;
        cout << "请输入收藏标题: ";
        cin.ignore();
        getline(cin, title);
        cout << "请输入URL: ";
        getline(cin, url);
        cout << "请输入分类标签（工作/学习/娱乐等）: ";
        getline(cin, category);

        FavoriteItem newFav(title, url, category);
        if (favorites.insert(newFav))
        {
            cout << "已添加到收藏夹！" << endl;
        }
        else
        {
            cout << "该URL已存在于收藏夹中！" << endl;
        }
    }

    // 删除收藏
    void deleteFavorite()
    {
        if (favorites.getCount() == 0)
        {
            cout << "收藏夹为空。" << endl;
            return;
        }

        string url;
        cout << "请输入要删除的收藏URL: ";
        cin.ignore();
        getline(cin, url);

        if (favorites.remove(url))
        {
            cout << "已从收藏夹中删除！" << endl;
        }
        else
        {
            cout << "未找到该收藏。" << endl;
        }
    }

    // 查找收藏
    void searchFavorite()
    {
        if (favorites.getCount() == 0)
        {
            cout << "收藏夹为空。" << endl;
            return;
        }

        cout << "\n=== 查找收藏夹 ===" << endl;
        cout << "1. 按分类标签列出" << endl;
        cout << "2. 按关键词搜索" << endl;
        cout << "3. 精确查找URL" << endl;
        cout << "请选择: ";

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            string category;
            cout << "请输入分类标签: ";
            cin.ignore();
            getline(cin, category);

            vector<FavoriteItem> results = favorites.findByCategory(category);
            if (results.empty())
            {
                cout << "未找到该分类的收藏。" << endl;
            }
            else
            {
                cout << "\n=== 分类「" << category << "」的收藏 ===" << endl;
                for (size_t i = 0; i < results.size(); i++)
                {
                    cout << i + 1 << ". 标题: " << results[i].title << endl;
                    cout << "   URL: " << results[i].url << endl;
                    cout << "   ---" << endl;
                }
            }
        }
        else if (choice == 2)
        {
            string keyword;
            cout << "请输入关键词: ";
            cin.ignore();
            getline(cin, keyword);

            vector<FavoriteItem> results = favorites.searchByKeyword(keyword);
            if (results.empty())
            {
                cout << "未找到匹配的收藏。" << endl;
            }
            else
            {
                cout << "\n=== 搜索结果 ===" << endl;
                for (size_t i = 0; i < results.size(); i++)
                {
                    cout << i + 1 << ". 标题: " << results[i].title << endl;
                    cout << "   URL: " << results[i].url << endl;
                    cout << "   分类: " << results[i].category << endl;
                    cout << "   ---" << endl;
                }
            }
        }
        else if (choice == 3)
        {
            string url;
            cout << "请输入URL: ";
            cin.ignore();
            getline(cin, url);

            FavoriteItem result;
            if (favorites.find(url, result))
            {
                cout << "\n=== 找到收藏 ===" << endl;
                cout << "标题: " << result.title << endl;
                cout << "URL: " << result.url << endl;
                cout << "分类: " << result.category << endl;
            }
            else
            {
                cout << "未找到该收藏。" << endl;
            }
        }
    }

    // 修改收藏
    void modifyFavorite()
    {
        if (favorites.getCount() == 0)
        {
            cout << "收藏夹为空。" << endl;
            return;
        }

        string oldUrl;
        cout << "请输入要修改的收藏URL: ";
        cin.ignore();
        getline(cin, oldUrl);

        FavoriteItem oldItem;
        if (!favorites.find(oldUrl, oldItem))
        {
            cout << "未找到该收藏。" << endl;
            return;
        }

        cout << "\n当前信息:" << endl;
        cout << "标题: " << oldItem.title << endl;
        cout << "URL: " << oldItem.url << endl;
        cout << "分类: " << oldItem.category << endl;

        cout << "\n请输入新信息（直接回车保留原值）:" << endl;

        string newTitle, newUrl, newCategory;
        cout << "新标题: ";
        getline(cin, newTitle);
        cout << "新URL: ";
        getline(cin, newUrl);
        cout << "新分类: ";
        getline(cin, newCategory);

        FavoriteItem newItem(
            newTitle.empty() ? oldItem.title : newTitle,
            newUrl.empty() ? oldItem.url : newUrl,
            newCategory.empty() ? oldItem.category : newCategory);

        if (favorites.update(oldUrl, newItem))
        {
            cout << "修改成功！" << endl;
        }
        else
        {
            cout << "修改失败！新URL可能已存在。" << endl;
        }
    }

    // 查看所有收藏
    void viewAllFavorites()
    {
        if (favorites.getCount() == 0)
        {
            cout << "收藏夹为空。" << endl;
            return;
        }

        vector<FavoriteItem> all = favorites.getAll();
        cout << "\n=== 我的收藏夹（共" << all.size() << "条）===" << endl;
        for (size_t i = 0; i < all.size(); i++)
        {
            cout << i + 1 << ". 标题: " << all[i].title << endl;
            cout << "   URL: " << all[i].url << endl;
            cout << "   分类: " << all[i].category << endl;
            cout << "   ---" << endl;
        }
    }

    // ==================== 扩展功能 ====================

    // 最常访问Top N
    void topNVisited()
    {
        if (historyQueue.empty())
        {
            cout << "暂无历史记录。" << endl;
            return;
        }

        int n;
        cout << "请输入要查看的Top N（例如10）: ";
        cin >> n;

        // 收集所有历史记录
        vector<HistoryItem> allHistory;
        queue<HistoryItem> temp = historyQueue;
        while (!temp.empty())
        {
            allHistory.push_back(temp.front());
            temp.pop();
        }

        // 按访问次数排序
        sort(allHistory.begin(), allHistory.end(),
             [](const HistoryItem &a, const HistoryItem &b)
             {
                 return a.visitCount > b.visitCount;
             });

        cout << "\n=== 最常访问的Top " << min(n, (int)allHistory.size()) << " ===" << endl;
        for (int i = 0; i < min(n, (int)allHistory.size()); i++)
        {
            cout << i + 1 << ". " << allHistory[i].title << endl;
            cout << "   URL: " << allHistory[i].url << endl;
            cout << "   访问次数: " << allHistory[i].visitCount << endl;
            cout << "   ---" << endl;
        }
    }

    // 清空所有历史
    void clearAllHistory()
    {
        char confirm;
        cout << "警告：这将清空所有历史记录（后退栈、前进栈、时间队列），是否继续？(y/n): ";
        cin >> confirm;

        if (confirm == 'y' || confirm == 'Y')
        {
            while (!backStack.empty())
                backStack.pop();
            while (!forwardStack.empty())
                forwardStack.pop();
            while (!historyQueue.empty())
                historyQueue.pop();

            // 重置当前页面
            if (!backStack.empty())
            {
                currentPage = backStack.top();
                backStack.pop();
            }
            else
            {
                currentPage = HistoryItem();
            }

            cout << "所有历史记录已清空！" << endl;
        }
        else
        {
            cout << "操作已取消。" << endl;
        }
    }

    // 导出收藏夹
    void exportFavorites()
    {
        string filename;
        cout << "请输入导出文件名（如 favorites.txt）: ";
        cin.ignore();
        getline(cin, filename);

        ofstream file(filename);
        if (!file.is_open())
        {
            cout << "无法创建文件！" << endl;
            return;
        }

        vector<FavoriteItem> all = favorites.getAll();
        for (const auto &item : all)
        {
            file << item.title << "|" << item.url << "|" << item.category << endl;
        }

        file.close();
        cout << "成功导出 " << all.size() << " 条收藏到 " << filename << endl;
    }

    // 导入收藏夹
    void importFavorites()
    {
        string filename;
        cout << "请输入要导入的文件名: ";
        cin.ignore();
        getline(cin, filename);

        ifstream file(filename);
        if (!file.is_open())
        {
            cout << "无法打开文件！" << endl;
            return;
        }

        cout << "导入模式:" << endl;
        cout << "1. 合并（保留原有收藏）" << endl;
        cout << "2. 覆盖（清空原有收藏）" << endl;
        cout << "请选择: ";

        int mode;
        cin >> mode;

        if (mode == 2)
        {
            favorites.clear();
        }

        string line;
        int count = 0;
        while (getline(file, line))
        {
            size_t pos1 = line.find('|');
            size_t pos2 = line.find('|', pos1 + 1);

            if (pos1 != string::npos && pos2 != string::npos)
            {
                FavoriteItem item;
                item.title = line.substr(0, pos1);
                item.url = line.substr(pos1 + 1, pos2 - pos1 - 1);
                item.category = line.substr(pos2 + 1);

                if (favorites.insert(item))
                {
                    count++;
                }
            }
        }

        file.close();
        cout << "成功导入 " << count << " 条收藏！" << endl;
    }

    // 自动补全（前缀搜索）
    void autoComplete()
    {
        string prefix;
        cout << "请输入前缀（标题或URL的开头）: ";
        cin.ignore();
        getline(cin, prefix);

        vector<HistoryItem> historyResults;
        queue<HistoryItem> temp = historyQueue;
        while (!temp.empty())
        {
            HistoryItem item = temp.front();
            temp.pop();
            if (item.title.find(prefix) == 0 || item.url.find(prefix) == 0)
            {
                historyResults.push_back(item);
            }
        }

        vector<FavoriteItem> favResults = favorites.searchByKeyword(prefix);
        // 过滤出前缀匹配的
        vector<FavoriteItem> filteredFav;
        for (const auto &item : favResults)
        {
            if (item.title.find(prefix) == 0 || item.url.find(prefix) == 0)
            {
                filteredFav.push_back(item);
            }
        }

        if (historyResults.empty() && filteredFav.empty())
        {
            cout << "未找到匹配的记录。" << endl;
            return;
        }

        cout << "\n=== 自动补全结果（前缀：「" << prefix << "」）===" << endl;

        if (!historyResults.empty())
        {
            cout << "\n【历史记录匹配】" << endl;
            for (size_t i = 0; i < historyResults.size(); i++)
            {
                cout << i + 1 << ". [历史] " << historyResults[i].title << endl;
                cout << "        URL: " << historyResults[i].url << endl;
                cout << "        时间: " << historyResults[i].timestamp << endl;
            }
        }

        if (!filteredFav.empty())
        {
            cout << "\n【收藏夹匹配】" << endl;
            for (size_t i = 0; i < filteredFav.size(); i++)
            {
                cout << i + 1 << ". [收藏] " << filteredFav[i].title << endl;
                cout << "        URL: " << filteredFav[i].url << endl;
                cout << "        分类: " << filteredFav[i].category << endl;
            }
        }

        cout << "\n共找到 " << historyResults.size() + filteredFav.size() << " 条匹配记录" << endl;
    }

    // ==================== 持久化 ====================

    void saveToFile()
    {
        // 保存历史记录
        ofstream historyFile("history.txt");
        if (historyFile.is_open())
        {
            queue<HistoryItem> temp = historyQueue;
            while (!temp.empty())
            {
                HistoryItem item = temp.front();
                temp.pop();
                historyFile << item.title << "|"
                            << item.url << "|"
                            << item.timestamp << "|"
                            << item.visitCount << endl;
            }
            historyFile.close();
        }

        // 保存收藏夹
        ofstream favFile("favorites.txt");
        if (favFile.is_open())
        {
            vector<FavoriteItem> all = favorites.getAll();
            for (const auto &item : all)
            {
                favFile << item.title << "|"
                        << item.url << "|"
                        << item.category << endl;
            }
            favFile.close();
        }

        // 保存当前页面和导航状态
        ofstream sessionFile("session.txt");
        if (sessionFile.is_open())
        {
            // 保存当前页面
            sessionFile << "CURRENT_PAGE" << endl;
            if (currentPage.url != "")
            {
                sessionFile << currentPage.title << "|"
                            << currentPage.url << "|"
                            << currentPage.timestamp << "|"
                            << currentPage.visitCount << endl;
            }
            else
            {
                sessionFile << "EMPTY" << endl;
            }

            // 保存后退栈（从栈底到栈顶）
            sessionFile << "BACK_STACK" << endl;
            stack<HistoryItem> tempBack = backStack;
            vector<HistoryItem> backVec;
            while (!tempBack.empty())
            {
                backVec.push_back(tempBack.top());
                tempBack.pop();
            }
            for (int i = backVec.size() - 1; i >= 0; i--)
            {
                sessionFile << backVec[i].title << "|"
                            << backVec[i].url << "|"
                            << backVec[i].timestamp << "|"
                            << backVec[i].visitCount << endl;
            }

            // 保存前进栈
            sessionFile << "FORWARD_STACK" << endl;
            stack<HistoryItem> tempForward = forwardStack;
            vector<HistoryItem> forwardVec;
            while (!tempForward.empty())
            {
                forwardVec.push_back(tempForward.top());
                tempForward.pop();
            }
            for (int i = forwardVec.size() - 1; i >= 0; i--)
            {
                sessionFile << forwardVec[i].title << "|"
                            << forwardVec[i].url << "|"
                            << forwardVec[i].timestamp << "|"
                            << forwardVec[i].visitCount << endl;
            }

            sessionFile.close();
        }

        cout << "数据已保存！" << endl;
    }

    void loadFromFile()
    {
        // 加载历史记录
        ifstream historyFile("history.txt");
        if (historyFile.is_open())
        {
            string line;
            while (getline(historyFile, line))
            {
                size_t pos1 = line.find('|');
                size_t pos2 = line.find('|', pos1 + 1);
                size_t pos3 = line.find('|', pos2 + 1);

                if (pos1 != string::npos && pos2 != string::npos && pos3 != string::npos)
                {
                    HistoryItem item;
                    item.title = line.substr(0, pos1);
                    item.url = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    item.timestamp = line.substr(pos2 + 1, pos3 - pos2 - 1);
                    item.visitCount = stoi(line.substr(pos3 + 1));

                    historyQueue.push(item);
                }
            }
            historyFile.close();
            cout << "加载了 " << historyQueue.size() << " 条历史记录" << endl;
        }

        // 加载收藏夹
        ifstream favFile("favorites.txt");
        if (favFile.is_open())
        {
            string line;
            while (getline(favFile, line))
            {
                size_t pos1 = line.find('|');
                size_t pos2 = line.find('|', pos1 + 1);

                if (pos1 != string::npos && pos2 != string::npos)
                {
                    FavoriteItem item;
                    item.title = line.substr(0, pos1);
                    item.url = line.substr(pos1 + 1, pos2 - pos1 - 1);
                    item.category = line.substr(pos2 + 1);

                    favorites.insert(item);
                }
            }
            favFile.close();
            cout << "加载了 " << favorites.getCount() << " 条收藏" << endl;
        }

        // 加载会话状态
        ifstream sessionFile("session.txt");
        if (sessionFile.is_open())
        {
            string line;
            string section;

            while (getline(sessionFile, line))
            {
                if (line == "CURRENT_PAGE")
                {
                    getline(sessionFile, line);
                    if (line != "EMPTY")
                    {
                        size_t pos1 = line.find('|');
                        size_t pos2 = line.find('|', pos1 + 1);
                        size_t pos3 = line.find('|', pos2 + 1);
                        if (pos1 != string::npos)
                        {
                            currentPage.title = line.substr(0, pos1);
                            currentPage.url = line.substr(pos1 + 1, pos2 - pos1 - 1);
                            currentPage.timestamp = line.substr(pos2 + 1, pos3 - pos2 - 1);
                            currentPage.visitCount = stoi(line.substr(pos3 + 1));
                        }
                    }
                }
                else if (line == "BACK_STACK")
                {
                    while (getline(sessionFile, line) && line != "FORWARD_STACK")
                    {
                        size_t pos1 = line.find('|');
                        size_t pos2 = line.find('|', pos1 + 1);
                        size_t pos3 = line.find('|', pos2 + 1);
                        if (pos1 != string::npos)
                        {
                            HistoryItem item;
                            item.title = line.substr(0, pos1);
                            item.url = line.substr(pos1 + 1, pos2 - pos1 - 1);
                            item.timestamp = line.substr(pos2 + 1, pos3 - pos2 - 1);
                            item.visitCount = stoi(line.substr(pos3 + 1));
                            backStack.push(item);
                        }
                    }
                }
                else if (line == "FORWARD_STACK")
                {
                    while (getline(sessionFile, line))
                    {
                        size_t pos1 = line.find('|');
                        size_t pos2 = line.find('|', pos1 + 1);
                        size_t pos3 = line.find('|', pos2 + 1);
                        if (pos1 != string::npos)
                        {
                            HistoryItem item;
                            item.title = line.substr(0, pos1);
                            item.url = line.substr(pos1 + 1, pos2 - pos1 - 1);
                            item.timestamp = line.substr(pos2 + 1, pos3 - pos2 - 1);
                            item.visitCount = stoi(line.substr(pos3 + 1));
                            forwardStack.push(item);
                        }
                    }
                }
            }
            sessionFile.close();
        }

        // 如果当前页面为空但后退栈不为空，从后退栈恢复
        if (currentPage.url == "" && !backStack.empty())
        {
            currentPage = backStack.top();
            backStack.pop();
        }
    }

    // 显示当前状态
    void showStatus()
    {
        cout << "\n=== 当前状态 ===" << endl;
        if (currentPage.url != "")
        {
            cout << "当前页面: " << currentPage.title << " (" << currentPage.url << ")" << endl;
        }
        else
        {
            cout << "当前页面: 无" << endl;
        }
        cout << "后退栈大小: " << backStack.size() << endl;
        cout << "前进栈大小: " << forwardStack.size() << endl;
        cout << "历史记录数: " << historyQueue.size() << endl;
        cout << "收藏夹数量: " << favorites.getCount() << endl;
    }

    // 显示主菜单
    void showMenu()
    {
        cout << "\n========== 浏览器管理系统 ==========" << endl;
        cout << "【基本功能】" << endl;
        cout << "1. 访问新网页" << endl;
        cout << "2. 后退" << endl;
        cout << "3. 前进" << endl;
        cout << "4. 查看历史记录" << endl;
        cout << "5. 搜索历史记录" << endl;
        cout << "6. 删除历史记录" << endl;
        cout << "7. 修改历史记录标题" << endl;
        cout << endl;
        cout << "【收藏夹管理】" << endl;
        cout << "8. 添加收藏" << endl;
        cout << "9. 删除收藏" << endl;
        cout << "10. 查找收藏" << endl;
        cout << "11. 修改收藏" << endl;
        cout << "12. 查看所有收藏" << endl;
        cout << endl;
        cout << "【扩展功能】" << endl;
        cout << "13. 最常访问Top N" << endl;
        cout << "14. 清空所有历史" << endl;
        cout << "15. 导出收藏夹" << endl;
        cout << "16. 导入收藏夹" << endl;
        cout << "17. 自动补全（前缀搜索）" << endl;
        cout << endl;
        cout << "18. 显示当前状态" << endl;
        cout << "0. 退出并保存" << endl;
        cout << "====================================" << endl;
        cout << "请选择操作: ";
    }
};

// ==================== 主函数 ====================

int main()
{
    BrowserManager manager;
    int choice;

    cout << "欢迎使用浏览器历史记录与收藏夹管理系统！" << endl;

    while (true)
    {
        manager.showMenu();
        cin >> choice;

        switch (choice)
        {
        case 1:
            manager.visitNewPage();
            break;
        case 2:
            manager.goBack();
            break;
        case 3:
            manager.goForward();
            break;
        case 4:
            manager.viewHistory();
            break;
        case 5:
            manager.searchHistory();
            break;
        case 6:
            manager.deleteHistory();
            break;
        case 7:
            manager.modifyHistory();
            break;
        case 8:
            manager.addFavorite();
            break;
        case 9:
            manager.deleteFavorite();
            break;
        case 10:
            manager.searchFavorite();
            break;
        case 11:
            manager.modifyFavorite();
            break;
        case 12:
            manager.viewAllFavorites();
            break;
        case 13:
            manager.topNVisited();
            break;
        case 14:
            manager.clearAllHistory();
            break;
        case 15:
            manager.exportFavorites();
            break;
        case 16:
            manager.importFavorites();
            break;
        case 17:
            manager.autoComplete();
            break;
        case 18:
            manager.showStatus();
            break;
        case 0:
            cout << "正在保存数据并退出..." << endl;
            return 0;
        default:
            cout << "无效输入，请重新选择！" << endl;
            break;
        }
    }

    return 0;
}