struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution
{
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB)
    {
        if (!headA || !headB)
        {
            return nullptr;
        }
        ListNode *pA = headA;
        ListNode *pB = headB;

        while (pA && pB && pA != pB)
        {
            pA = pA->next;
            pB = pB->next;
            if (pA == pB)
            {
                return pA;
            }

            if (pA == nullptr)
            {
                pA = headB;
            }
            if (pB == nullptr)
            {
                pB = headA;
            }
        }
        return pA;
    }
};