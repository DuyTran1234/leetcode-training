#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution
{
public:
    bool containsDuplicate(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return false;
        }
        std::sort(nums.begin(), nums.end());
        for (int i = 1; i < nums.size(); ++i)
        {
            if (nums[i] == nums[i - 1])
            {
                return true;
            }
        }
        return false;
    }
};