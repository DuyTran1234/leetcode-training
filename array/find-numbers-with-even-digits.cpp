#include <vector>
#include <string>
#include <cmath> /* log10 */

using namespace std;

class Solution
{
public:
    int findNumbers(std::vector<int> &nums)
    {
        int count = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            int digits = static_cast<int>(log10(nums[i]) + 1);
            if (digits % 2 == 0)
                ++count;
        }
        return count;
    }
};