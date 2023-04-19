#include <string>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        int start = 0;
        int end = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i + 1] == ' ' || i + 1 == s.size())
            {
                this->reverseSub(start, i, s);
                start = i + 2;
            }
        }
        return s;
    }
    void reverseSub(int start, int end, string &s)
    {
        while (start < end)
        {
            std::swap(s[start++], s[end--]);
        }
    }
};