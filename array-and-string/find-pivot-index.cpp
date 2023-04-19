#include <vector>
using namespace std;

class Solution
{
public:
    int pivotIndex(vector<int> &nums)
    {
        int n = nums.size();
        if (n == 1)
        {
            return 0;
        }
        int sumRight = 0;
        int sumLeft = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            sumRight += nums[i];
        }

        for (int i = 0; i < nums.size(); ++i)
        {
            sumRight -= nums[i];
            if (sumRight == sumLeft)
            {
                return i;
            }
            sumLeft += nums[i];
        }

        return -1;
    }
};