#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDisappearedNumbers(vector<int> &nums)
    {
        vector<int> clone(nums.size());
        vector<int> rs;
        for (int i = 0; i < nums.size(); ++i)
        {
            clone[nums[i] - 1] = nums[i];
        }
        for (int i = 0; i < clone.size(); ++i)
        {
            if (clone[i] == 0)
            {
                rs.push_back(i + 1);
            }
        }
        return rs;
    }
};