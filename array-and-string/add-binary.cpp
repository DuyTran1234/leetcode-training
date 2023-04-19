#include <string>
#include <algorithm>
using namespace std;

class Solution
{
public:
    string addBinary(string a, string b)
    {
        string str = "";
        bool mem = false;
        int pointA = a.size() - 1;
        int pointB = b.size() - 1;

        while (pointA >= 0 && pointB >= 0)
        {
            if (a[pointA] == '0' && b[pointB] == '0')
            {
                char rs = mem ? '1' : '0';
                str.push_back(rs);
                mem = false;
            }
            else if (a[pointA] == '1' && b[pointB] == '1')
            {
                char rs = mem ? '1' : '0';
                str.push_back(rs);
                mem = true;
            }
            else
            {
                char rs = mem ? '0' : '1';
                str.push_back(rs);
            }
            --pointA;
            --pointB;
        }
        while (pointA >= 0)
        {
            if (a[pointA] == '0')
            {
                char rs = mem ? '1' : '0';
                str.push_back(rs);
                mem = false;
            }
            else
            {
                char rs = mem ? '0' : '1';
                str.push_back(rs);
            }
            --pointA;
        }
        while (pointB >= 0)
        {
            if (b[pointB] == '0')
            {
                char rs = mem ? '1' : '0';
                str.push_back(rs);
                mem = false;
            }
            else
            {
                char rs = mem ? '0' : '1';
                str.push_back(rs);
            }
            --pointB;
        }
        if (mem)
        {
            str.push_back('1');
        }
        reverse(str.begin(), str.end());
        return str;
    }
};