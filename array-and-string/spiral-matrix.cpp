#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> rs;
        int rowLength = matrix.size();
        int colLength = matrix[0].size();

        if (colLength < 2)
        {
            for (int i = 0; i < rowLength; ++i)
            {
                rs.push_back(matrix[i][0]);
            }
            return rs;
        }
        int rowStart = 0;
        int colStart = colLength - 1;
        int rowEnd = rowLength - 1;
        int colEnd = 0;

        while (rowStart <= rowEnd && colStart >= colEnd)
        {
            for (int i = colEnd; i <= colStart; ++i)
            {
                rs.push_back(matrix[rowStart][i]);
            }
            ++rowStart;

            for (int i = rowStart; i <= rowEnd; ++i)
            {
                rs.push_back(matrix[i][colStart]);
            }
            --colStart;

            if (rowStart <= rowEnd)
            {
                for (int i = colStart; i >= colEnd; --i)
                {
                    rs.push_back(matrix[rowEnd][i]);
                }
                --rowEnd;
            }
            if (colStart >= colEnd)
            {
                for (int i = rowEnd; i >= rowStart; --i)
                {
                    rs.push_back(matrix[i][colEnd]);
                }
                ++colEnd;
            }
        }
        return rs;
    }
};