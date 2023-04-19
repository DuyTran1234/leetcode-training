#include <vector>
#include <unordered_map>
using namespace std;

struct Index
{
    int index = -1;
};

class Solution
{
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k)
    {
        unordered_map<int, Index> umap;

        for (int i = 0; i < nums.size(); ++i)
        {
            if (umap[nums[i]].index != -1 && umap[nums[i]].index != i)
            {
                if (abs(umap[nums[i]].index - i) <= k)
                {
                    return true;
                }
                else
                {
                    umap[nums[i]].index = i;
                }
            }
            else
            {
                umap[nums[i]].index = i;
            }
        }
        return false;
    }
};