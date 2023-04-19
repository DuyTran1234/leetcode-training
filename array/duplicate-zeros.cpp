#include <vector>
using namespace std;

class Solution
{
public:
    void duplicateZeros(vector<int> &arr)
    {
        vector<int> rs;
        int size = 0;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (arr[i] != 0)
            {
                rs.push_back(arr[i]);
                ++size;
            }
            else
            {
                rs.push_back(arr[i]);
                ++size;
                if (size >= arr.size())
                {
                    break;
                }
                rs.push_back(arr[i]);
                ++size;
            }
            if (size >= arr.size())
            {
                break;
            }
        }
        arr = rs;
    }
};