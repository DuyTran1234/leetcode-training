#include <unordered_map>
using namespace std;
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};
class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
        {
            return nullptr;
        }
        unordered_map<Node *, Node *> umap;
        for (Node *i = head; i != nullptr; i = i->next)
        {
            umap[i] = new Node(i->val);
        }

        Node *clone = umap[head];
        Node *newRand = head->random ? umap[head->random] : nullptr;
        clone->random = newRand;
        Node *current = clone;

        for (Node *i = head->next; i != nullptr; i = i->next)
        {
            Node *newNode = umap[i];
            Node *rand = i->random ? umap[i->random] : nullptr;
            newNode->random = rand;
            current->next = newNode;
            current = current->next;
        }
        return clone;
    }
};