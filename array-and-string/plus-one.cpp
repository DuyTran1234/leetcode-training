#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> plusOne(vector<int> &digits)
    {
        bool mem = false;
        for (int i = digits.size() - 1; i >= 0; --i)
        {
            int rs = i == digits.size() - 1 ? digits[i] + mem + 1 : digits[i] + mem;
            mem = false;
            if (rs == 10)
            {
                mem = true;
                rs = rs % 10;
            }
            digits[i] = rs;
            if (!mem)
            {
                break;
            }
            if (i == 0)
            {
                digits.insert(digits.begin(), 1);
            }
        }
        return digits;
    }
};