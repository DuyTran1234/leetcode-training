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
    ListNode *oddEvenList(ListNode *head)
    {
        if (!head || !head->next || !head->next->next)
        {
            return head;
        }

        ListNode *even = head;
        ListNode *odd = head->next;
        ListNode *oddNext = head->next;

        while (oddNext)
        {
            ListNode *evenNext = oddNext->next;
            if (!evenNext)
            {
                break;
            }
            oddNext->next = evenNext->next;
            oddNext = oddNext->next;
            even->next = evenNext;
            even = even->next;
            even->next = odd;
        }
        return head;
    }
};