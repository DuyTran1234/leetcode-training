#include <string>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    bool isIsomorphic(string s, string t)
    {
        unordered_map<char, char> umap;
        unordered_map<char, bool> mapCheck;
        int n = s.size();
        for (int i = 0; i < n; ++i)
        {
            if (umap.find(s[i]) == umap.end() && mapCheck[t[i]] == false)
            {
                umap[s[i]] = t[i];
                mapCheck[t[i]] = true;
            }
            else if (umap.find(s[i]) != umap.end() && umap[s[i]] == t[i])
            {
                continue;
            }
            else
            {
                return false;
            }
        }
        return true;
    }
};