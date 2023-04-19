#include <string>
#include <unordered_map>

using namespace std;

class Solution
{
public:
    int firstUniqChar(string s)
    {
        unordered_map<char, pair<int, int>> umap; // first: index, second: number appear
        int min = __INT_MAX__;
        for (int i = 0; i < s.size(); ++i)
        {
            umap[s[i]].first = i;
            umap[s[i]].second++;
        }
        for (auto i = umap.begin(); i != umap.end(); ++i)
        {
            if ((*i).second.second == 1)
            {
                if ((*i).second.first < min)
                {
                    min = (*i).second.first;
                }
            }
        }
        return min == __INT_MAX__ ? -1 : min;
    }
};