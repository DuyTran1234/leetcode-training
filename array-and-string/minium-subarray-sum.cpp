#include <vector>
using namespace std;

class Solution
{
public:
    int minSubArrayLen(int target, vector<int> &nums)
    {
        if (nums.size() == 1)
        {
            if (nums[0] >= target)
            {
                return 1;
            }
            return 0;
        }
        int left = 0;
        int right = 1;
        int sum = nums[left];
        int min = nums[left] >= target ? 1 : __INT_MAX__;
        int n = nums.size();

        while (right < n)
        {
            sum += nums[right];
            if (sum >= target)
            {
                min = std::min(min, right - left + 1);
                sum -= nums[left];
                sum -= nums[right];
                ++left;
            }
            else
            {
                ++right;
            }
        }
        return min == __INT_MAX__ ? 0 : min;
    }
};