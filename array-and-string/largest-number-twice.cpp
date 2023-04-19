#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int dominantIndex(vector<int> &nums)
    {
        int max1, max2, index;
        if (nums[0] > nums[1])
        {
            max1 = nums[0];
            max2 = nums[1];
            index = 0;
        }
        else
        {
            max1 = nums[1];
            max2 = nums[0];
            index = 1;
        }

        for (int i = 2; i < nums.size(); ++i)
        {
            if (nums[i] > max1)
            {
                max2 = max1;
                max1 = nums[i];
                index = i;
            }
            if (nums[i] > max2 && nums[i] < max1)
            {
                max2 = nums[i];
            }
        }
        if (max1 >= max2 * 2)
        {
            return index;
        }
        return -1;
    }
};