#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> topKFrequent(vector<int> &nums, int k)
    {
        unordered_map<int, int> umap; // first: elements, second: frequent
        map<int, vector<int>> map;
        unordered_set<int> uset;

        for (int value : nums)
        {
            umap[value]++;
            map[umap[value]].push_back(value);
        }
        for (auto i = map.rbegin(); i != map.rend(); ++i)
        {
            bool flag = true;
            for (auto j = (*i).second.begin(); j != (*i).second.end(); ++j)
            {
                uset.insert((*j));
                if (uset.size() == k)
                {
                    flag = false;
                    break;
                }
            }
            if (!flag)
            {
                break;
            }
        }
        return vector<int>(uset.begin(), uset.end());
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> lst{1, 1, 1, 2, 2};
    sol->topKFrequent(lst, 2);
}