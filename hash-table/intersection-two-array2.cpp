#include <vector>
#include <unordered_map>
#include <utility>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2)
    {
        unordered_map<int, int> umap; // first: check exists in 2 arrays, second: number appear
        vector<int> rs;

        for (int i = 0; i < nums1.size(); ++i)
        {
            umap[nums1[i]]++;
        }
        for (int i = 0; i < nums2.size(); ++i)
        {
            if (umap[nums2[i]] > 0)
            {
                umap[nums2[i]]--;
                rs.push_back(nums2[i]);
            }
        }
        return rs;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<int> list1{4, 9, 5};
    vector<int> list2{9, 4, 9, 8, 4};
    vector<int> rs = sol->intersect(list1, list2);
    for (int value : rs)
    {
        std::cout << value << "\n";
    }
}