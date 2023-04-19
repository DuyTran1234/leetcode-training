#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findMaxConsecutiveOnes(vector<int> &nums)
    {
        int max = 0;
        int consecutive = 0;
        for (int i = 0; i < nums.size(); ++i)
        {
            if (nums[i] == 1)
            {
                ++consecutive;
            }
            if (consecutive > max)
            {
                max = consecutive;
            }
            if (nums[i] != 1)
            {
                consecutive = 0;
            }
        }
        return max;
    }
};