#include <iostream>
#include <list>
#include <string>
using namespace std;

struct Line
{
    int len = 0;
    string content;
};

list<Line> out;
char shiftNum[10] = {')', '!', '@', '#', '$', '%', '^', '&', '*', '('};

int main()
{
    string command;
    bool shift = false;
    cin >> command;
    out.push_back({0, ""});
    int py = 0;
    auto px = out.begin();

    for (int i = 0; i < (int)command.length(); i++)
    {
        // 处理字母
        if (command[i] >= 'a' && command[i] <= 'z')
        {
            if (shift)
            {
                (*px).content.insert(py, 1, (char)(command[i] - 32));
            }
            else
            {
                (*px).content.insert(py, 1, command[i]);
            }
            (*px).len++;
            py++;
            continue;
        }

        // 处理数字
        if (command[i] >= '0' && command[i] <= '9')
        {
            if (shift)
            {
                (*px).content.insert(py, 1, shiftNum[command[i] - '0']);
            }
            else
            {
                (*px).content.insert(py, 1, command[i]);
            }
            (*px).len++;
            py++;
            continue;
        }

        // 处理命令 - 使用字符串比较
        string sub = command.substr(i);

        if (sub.find("SHIFT") == 0)
        {
            shift = !shift;
            i += 4;
        }
        else if (sub.find("ENTER") == 0)
        {
            string afterCursor = (*px).content.substr(py);
            (*px).content = (*px).content.substr(0, py);
            (*px).len = py;

            Line newLine;
            newLine.content = afterCursor;
            newLine.len = afterCursor.length();

            auto nextPos = next(px);
            out.insert(nextPos, newLine);
            px++;
            py = 0;
            i += 4;
        }
        else if (sub.find("BACKSPACE") == 0)
        {
            if (py > 0)
            {
                (*px).content.erase(py - 1, 1);
                (*px).len--;
                py--;
            }
            else if (px != out.begin())
            {
                auto prevLine = prev(px);
                int prevLen = (*prevLine).len;
                (*prevLine).content += (*px).content;
                (*prevLine).len += (*px).len;
                px = out.erase(px);
                px--;
                py = prevLen;
            }
            i += 8;
        }
        else if (sub.find("DEL") == 0)
        {
            if (py < (*px).len)
            {
                (*px).content.erase(py, 1);
                (*px).len--;
            }
            else if (next(px) != out.end())
            {
                auto nextLine = next(px);
                int currentLen = (*px).len;
                (*px).content += (*nextLine).content;
                (*px).len += (*nextLine).len;
                out.erase(nextLine);
                py = currentLen;
            }
            i += 2;
        }
        else if (sub.find("LEFT") == 0)
        {
            if (py > 0)
            {
                py--;
            }
            else if (px != out.begin())
            {
                px--;
                py = (*px).len;
            }
            i += 3;
        }
        else if (sub.find("RIGHT") == 0)
        {
            if (py < (*px).len)
            {
                py++;
            }
            else if (next(px) != out.end())
            {
                px++;
                py = 0;
            }
            i += 4;
        }
        else if (sub.find("UP") == 0)
        {
            if (px != out.begin())
            {
                auto prevLine = prev(px);
                int prevLen = (*prevLine).len;
                px--;
                if (py > prevLen)
                {
                    py = prevLen;
                }
            }
            i += 1;
        }
        else if (sub.find("DOWN") == 0)
        {
            if (next(px) != out.end())
            {
                auto nextLine = next(px);
                int nextLen = (*nextLine).len;
                px++;
                if (py > nextLen)
                {
                    py = nextLen;
                }
            }
            i += 3;
        }
        else if (sub.find("HOME") == 0)
        {
            py = 0;
            i += 3;
        }
        else if (sub.find("END") == 0)
        {
            py = (*px).len;
            i += 2;
        }
    }

    for (auto &line : out)
    {
        cout << line.content << endl;
    }

    return 0;
}