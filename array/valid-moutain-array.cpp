#include <vector>
using namespace std;

class Solution
{
public:
    bool validMountainArray(vector<int> &arr)
    {
        if (arr.size() < 3)
        {
            return false;
        }
        if (arr[0] > arr[1])
        {
            return false;
        }
        int point = -1;
        for (int i = 1; i < arr.size(); ++i)
        {
            if (arr[i - 1] >= arr[i])
            {
                point = i - 1;
                break;
            }
        }
        if (point == -1)
        {
            return false;
        }
        for (int i = point + 1; i < arr.size(); ++i)
        {
            if (arr[i] >= arr[i - 1])
            {
                return false;
            }
        }
        return true;
    }
};