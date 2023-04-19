#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> sortArrayByParity(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums;
        }
        vector<int> rs(nums.size());
        int left = 0;
        int right = nums.size() - 1;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] % 2 == 0)
            {
                rs[left++] = nums[i];
            }
            else
            {
                rs[right--] = nums[i];
            }
        }
        return rs;
    }
};