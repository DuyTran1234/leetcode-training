#include <vector>
using namespace std;

class Solution
{
public:
    void rotate(vector<int> &nums, int k)
    {
        int n = nums.size();
        if (n < 2)
        {
            return;
        }
        k = k % n;
        if (k == 0)
        {
            return;
        }
        vector<int> rs;

        for (int i = n - k; i < n; ++i)
        {
            rs.push_back(nums[i]);
        }
        for (int i = 0; i < n - k; ++i)
        {
            rs.push_back(nums[i]);
        }
        nums = rs;
    }
};