#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_set<int> uset;
        unordered_set<int> subSet;
        // vector<int> rs;
        for (int value : nums1)
        {
            uset.insert(value);
        }
        for (int value : nums2)
        {
            if (uset.find(value) != uset.end())
            {
                subSet.insert(value);
            }
        }

        return vector<int>(subSet.begin(), subSet.end());
    }
};