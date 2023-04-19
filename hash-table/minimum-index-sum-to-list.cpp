#include <vector>
#include <unordered_map>
#include <string>
#include <utility>
#include <iostream>
using namespace std;

class Solution
{
public:
    vector<string> findRestaurant(vector<string> &list1, vector<string> &list2)
    {
        unordered_map<string, pair<int, int>> umap; // first: length, second: sum
        vector<string> rs;
        int min = __INT_MAX__;
        for (int i = 0; i < list1.size(); ++i)
        {
            umap[list1[i]].first = 1;
            umap[list1[i]].second += i;
        }
        for (int i = 0; i < list2.size(); ++i)
        {
            umap[list2[i]].first++;
            umap[list2[i]].second += i;
            if (umap[list2[i]].second < min && umap[list2[i]].first > 1)
            {
                min = umap[list2[i]].second;
            }
        }
        for (auto it = umap.begin(); it != umap.end(); ++it)
        {
            if ((*it).second.first > 1 && (*it).second.second == min)
            {
                rs.push_back((*it).first);
            }
        }

        return rs;
    }
};

int main()
{
    Solution *sol = new Solution();
    vector<string> list1{"Shogun", "Tapioca Express", "Burger King", "KFC"};
    vector<string> list2{"Piatti", "The Grill at Torrey Pines", "Hungry Hunter Steakhouse", "Shogun"};
    sol->findRestaurant(list1, list2);
}