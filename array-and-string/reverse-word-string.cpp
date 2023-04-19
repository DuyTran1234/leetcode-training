#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string reverseWords(string s)
    {
        std::reverse(s.begin(), s.end());
        int check = false;
        int start = 0;
        int count = 0;
        for (int i = 0; i < s.size(); ++i)
        {
            if (s[i] != ' ')
            {
                check = true;
                ++count;
            }
            if (((i + 1) == s.size() || s[i + 1] == ' ') && check)
            {
                this->reverseSub(start, i, s);
                start = start + count + 1;
                count = 0;
                check = false;
            }
        }
        s.erase(start - 1);
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