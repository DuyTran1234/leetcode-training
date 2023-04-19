#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> twoSum(vector<int> &numbers, int target)
    {
        int left = 0;
        int right = numbers.size() - 1;
        vector<int> rs;
        while (left < right)
        {
            if (numbers[left] + numbers[right] > target)
            {
                --right;
            }
            else if (numbers[left] + numbers[right] < target)
            {
                ++left;
            }
            else
            {
                rs.push_back(left + 1);
                rs.push_back(right + 1);
                break;
            }
        }
        return rs;
    }
};