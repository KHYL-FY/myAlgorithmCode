#include <iostream>

// using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution
{

public:
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        ListNode *i = (*head).next;
        ListNode *j = (*head).next;
        int p = 0;
        while (1)
        {
            p = 0;
            for (int x = 1; 2 * x <= k; x++)
            {
                p++;
                for (int y = 1; y <= k - x; y++)
                {
                    if ((*j).next == nullptr)
                    {
                        return head;
                    }
                    j = (*j).next;
                }
                int t = (*i).val;
                (*i).val = (*j).val;
                (*j).val = t;

                i = (*i).next;
            }
            while (p--)
            {
                i = (*i).next;
            }
        }
    }
};