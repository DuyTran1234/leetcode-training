#include <vector>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool checkIfExist(vector<int> &arr)
    {
        unordered_set<int> uset;
        for (int i = 0; i < arr.size(); ++i)
        {
            if (uset.count(arr[i] * 2) || (arr[i] % 2 == 0 && uset.count(arr[i] / 2)))
            {
                return true;
            }
            uset.insert(arr[i]);
        }
        return false;
    }
};