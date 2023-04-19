#include <vector>
#include <set>
using namespace std;

class Solution
{
public:
    int thirdMax(vector<int> &nums)
    {
        set<int> rs;
        for (int i = 0; i < nums.size(); ++i)
        {
            rs.insert(nums[i]);
        }
        auto it = rs.rbegin();
        if (rs.size() < 3)
        {
            return *it;
        }
        else
        {
            int count = 2;
            for (it; it != rs.rend(); ++it)
            {
                --count;
                if (count < 0)
                {
                    return *it;
                }
            }
            return *it;
        }
    }
};