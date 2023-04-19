#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> umap;
        vector<vector<string>> rs;
        for (int i = 0; i < strs.size(); ++i)
        {
            string clone = strs[i];
            sort(clone.begin(), clone.end());
            umap[clone].push_back(strs[i]);
        }
        for (auto it = umap.begin(); it != umap.end(); ++it)
        {
            rs.push_back((*it).second);
        }
        return rs;
    }
};