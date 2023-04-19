#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int arrayPairSum(vector<int> &nums)
    {
        std::sort(nums.begin(), nums.end());
        int max = 0;
        for (int i = 0; i < nums.size(); i += 2)
        {
            max += nums[i];
        }
        return max;
    }
};