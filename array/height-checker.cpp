#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int heightChecker(vector<int> &heights)
    {
        vector<int> clone = heights;
        sort(clone.begin(), clone.end());
        int count = 0;
        for (int i = 0; i < clone.size(); ++i)
        {
            if (heights[i] != clone[i])
            {
                ++count;
            }
        }
        return count;
    }
};