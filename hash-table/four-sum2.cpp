#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    int fourSumCount(vector<int> &nums1, vector<int> &nums2, vector<int> &nums3, vector<int> &nums4)
    {
        int count = 0;
        unordered_map<int, int> umap;
        for (int i = 0; i < nums1.size(); ++i)
        {
            for (int j = 0; j < nums2.size(); ++j)
            {
                umap[nums1[i] + nums2[j]]++;
            }
        }
        for (int i = 0; i < nums3.size(); ++i)
        {
            for (int j = 0; j < nums4.size(); ++j)
            {
                int key = -(nums3[i] + nums4[j]);
                umap[key];
            }
        }
        return count;
    }
};