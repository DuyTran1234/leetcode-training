#include <vector>
using namespace std;

class Solution
{
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n)
    {
        vector<int> rs;
        int cursor1 = 0;
        int cursor2 = 0;

        while (cursor1 < m && cursor2 < n)
        {
            if (nums1[cursor1] < nums2[cursor2])
            {
                rs.push_back(nums1[cursor1]);
                ++cursor1;
            }
            else
            {
                rs.push_back(nums2[cursor2]);
                ++cursor2;
            }
        }
        while (cursor1 < m)
        {
            rs.push_back(nums1[cursor1]);
            ++cursor1;
        }
        while (cursor2 < n)
        {
            rs.push_back(nums2[cursor2]);
            ++cursor2;
        }
        nums1 = rs;
    }
};