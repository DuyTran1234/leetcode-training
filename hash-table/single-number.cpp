#include <vector>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        if (nums.size() < 2)
        {
            return nums[0];
        }
        int rs = 0;
        for (int value : nums)
        {
            rs = rs ^ value;
        }
        return rs;
    }
};