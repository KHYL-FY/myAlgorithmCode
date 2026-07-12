#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> seats(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> seats[i];
    }

    vector<bool> visited(n + 1, false);
    int swapCount = 0;

    for (int i = 1; i <= n; i++)
    {
        if (seats[i] != i && !visited[i])
        {
            int cycleSize = 0;
            int current = i;

            while (!visited[current])
            {
                visited[current] = true;
                current = seats[current];
                cycleSize++;
            }

            swapCount += (cycleSize - 1);
        }
    }

    cout << swapCount << endl;

    return 0;
}