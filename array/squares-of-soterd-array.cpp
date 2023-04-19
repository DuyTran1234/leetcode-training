#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution
{
public:
    vector<int> sortedSquares(vector<int> &nums)
    {
        int size = nums.size();
        int left = 0;
        int right = size - 1;
        vector<int> rs(size);
        int index = size - 1;
        while (left <= right)
        {
            if (abs(nums[left]) > abs(nums[right]))
            {
                rs[index] = nums[left] * nums[left];
                ++left;
            }
            else
            {
                rs[index] = nums[right] * nums[right];
                --right;
            }
            --index;
        }
        return rs;
    }
};