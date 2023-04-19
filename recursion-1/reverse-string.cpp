#include <vector>
using namespace std;
class Solution
{
public:
    void reverseString(vector<char> &s)
    {
        recursionString(s, 0, s.size() - 1);
    }

    void recursionString(vector<char> &s, int i, int j)
    {
        if (i >= j)
        {
            return;
        }
        std::swap(s[i++], s[j--]);
        recursionString(s, i, j);
    }
};