#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution
{
public:
    bool isValidSudoku(vector<vector<char>> &board)
    {
        unordered_map<string, int> umap;
        int n = 9;
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (board[i][j] != '.')
                {
                    string rowKey = "row" + to_string(i) + ":" + board[i][j];
                    string colKey = "col" + to_string(j) + ":" + board[i][j];
                    int subBoad = (i / 3) * 3 + j / 3;
                    string key = to_string(subBoad) + ":" + board[i][j];
                    umap[rowKey]++;
                    umap[colKey]++;
                    umap[key]++;
                    if (umap[rowKey] > 1 || umap[colKey] > 1 || umap[key] > 1)
                    {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
