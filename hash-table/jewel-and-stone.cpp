#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Solution
{
public:
    int numJewelsInStones(string jewels, string stones)
    {
        int count = 0;
        vector<char> table(58, -1);
        for (int i = 0; i < jewels.size(); ++i)
        {
            table[jewels[i] - 65] = jewels[i];
        }

        for (int i = 0; i < stones.size(); ++i)
        {
            if (table[stones[i] - 65] != -1)
            {
                ++count;
            }
        }
        return count;
    }
};

int main()
{
    Solution *sol = new Solution();
    std::cout << sol->numJewelsInStones("z", "ZZ") << "\n";
}