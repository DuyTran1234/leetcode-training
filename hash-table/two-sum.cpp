#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &nums, int target)
    {
        unordered_map<int, int> umap;
        vector<int> rs;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (umap.find(target - nums[i]) != umap.end() && i != umap[target - nums[i]])
            {
                rs.push_back(i);
                rs.push_back(umap[target - nums[i]]);
                break;
            }
            else
            {
                umap[nums[i]] = i;
            }
        }
        return rs;
    }
};