#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &mat)
    {
        vector<int> rs;
        int rowLength = mat.size();
        int colLength = mat[0].size();

        if (colLength < 2)
        {
            for (int i = 0; i < rowLength; ++i)
            {
                rs.push_back(mat[i][0]);
            }
            return rs;
        }

        for (int i = 0; i < colLength; ++i)
        {
            int left = 0;
            int right = i;
            int bound = right;

            while (left <= bound || right >= 0)
            {
                if ((left + right) % 2 == 0)
                {
                    if (right < rowLength && left < colLength)
                    {
                        rs.push_back(mat[right][left]);
                    }
                }
                else
                {
                    if (left < rowLength && right < colLength)
                    {
                        rs.push_back(mat[left][right]);
                    }
                }
                ++left;
                --right;
            }
        }
        for (int i = 1; i < rowLength; ++i)
        {
            int left = i;
            int right = colLength - 1;
            int bound = right;

            while (left <= bound || right >= 0)
            {
                if ((left + right) % 2 == 0)
                {
                    if (right < rowLength && left < colLength)
                    {
                        rs.push_back(mat[right][left]);
                    }
                }
                else
                {
                    if (left < rowLength && right < colLength)
                    {
                        rs.push_back(mat[left][right]);
                    }
                }
                ++left;
                --right;
            }
        }
        return rs;
    }
};