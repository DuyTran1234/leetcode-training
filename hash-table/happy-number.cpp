#include <iostream>
#include <unordered_set>
using namespace std;

class Solution
{
public:
    bool isHappy(int n)
    {
        unordered_set<int> uset;
        int rs = 0;
        while (n != 1)
        {
            if (uset.find(n) == uset.end())
            {
                uset.insert(n);
            }
            else
            {
                return false;
            }

            while (n != 0)
            {
                int digit = n % 10;
                rs += (digit * digit);
                n /= 10;
            }
            n = rs;
            if (rs == 1)
            {
                return true;
            }
            rs = 0;
        }
        return true;
    }
};

int main()
{
    Solution *sol = new Solution();
    sol->isHappy(20);
}