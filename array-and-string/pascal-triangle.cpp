#include <vector>
using namespace std;

class Solution
{
public:
    vector<vector<int>> generate(int numRows)
    {
        if (numRows == 1)
        {
            return {{1}};
        }
        if (numRows == 2)
        {
            return {{1}, {1, 1}};
        }
        vector<vector<int>> pascal({{1}, {1, 1}});
        int count = 2;
        while (count < numRows)
        {
            vector<int> rs;
            rs.push_back(1);
            for (int i = 1; i < pascal[count - 1].size(); ++i)
            {
                rs.push_back(pascal[count - 1][i - 1] + pascal[count - 1][i]);
            }
            rs.push_back(1);
            ++count;
            pascal.push_back(rs);
        }
        return pascal;
    }
};