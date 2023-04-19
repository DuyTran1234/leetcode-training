#include <vector>
#include <climits>
using namespace std;

class Solution
{
public:
    vector<int> replaceElements(vector<int> &arr)
    {
        int max = INT_MIN;
        int n = arr.size();
        vector<int> rs(n);
        int index = rs.size() - 1;
        rs[index] = -1;
        --index;

        for (int i = n - 1; i >= 0; --i)
        {
            if (arr[i] > max)
            {
                max = arr[i];
            }
            rs[index] = max;
            --index;
            if (index < 0)
            {
                break;
            }
        }
        return rs;
    }
};