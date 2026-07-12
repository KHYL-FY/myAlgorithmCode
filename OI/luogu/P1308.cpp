#include <iostream>
#include <string>
using namespace std;

int main()
{
    int location = 0, answer = 0;
    string word = "", sentence, aim_word;

    cin >> aim_word;
    for (size_t i = 0; i < aim_word.length(); i++)
    {
        aim_word[i] = tolower(aim_word[i]);
    }

    getchar();
    getline(cin, sentence);
    sentence += " ";

    for (size_t i = 0; i < sentence.length(); i++)
    {
        sentence[i] = tolower(sentence[i]);
    }
    for (size_t i = 0; i < sentence.length(); i++)
    {
        if (sentence[i] == ' ')
        {
            if (word == aim_word)
            {
                if (answer == 0)
                {
                    location = i - word.length();
                }
                answer++;
            }
            word = "";
        }
        else
        {
            word += sentence[i];
        }
    }
    if (answer == 0)
    {
        cout << "-1";
    }
    else
    {
        cout << answer << " " << location;
    }
    return 0;
}