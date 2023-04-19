#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> getRow(int rowIndex)
    {
        if (rowIndex == 0)
        {
            return {1};
        }
        if (rowIndex == 1)
        {
            return {1, 1};
        }
        vector<int> rs({1, 2, 1});
        int mem = -1;
        for (int count = 2; count < rowIndex; ++count)
        {
            for (int i = 1; i < rs.size(); ++i)
            {
                mem = rs[i - 1];
                rs[i - 1] = rs[i] + mem;
            }
            rs.insert(rs.begin(), 1);
        }
        return rs;
    }
};