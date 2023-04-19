#include <vector>
#include <list>
#include <algorithm>
using namespace std;

class MyHashSet
{
private:
    int prime;
    vector<list<int>> set;
    int getHash(int key)
    {
        return key % prime;
    }

public:
    MyHashSet()
    {
        this->prime = 10000;
        this->set = vector<list<int>>(prime);
    }

    void add(int key)
    {
        if (!this->contains(key))
        {
            int hash = this->getHash(key);
            set[hash].push_back(key);
        }
    }

    void remove(int key)
    {
        int hash = this->getHash(key);
        auto i = find(set[hash].begin(), set[hash].end(), key);
        if (i != set[hash].end())
        {
            set[hash].erase(i);
        }
    }

    bool contains(int key)
    {
        int hash = this->getHash(key);
        auto i = find(set[hash].begin(), set[hash].end(), key);
        return i != set[hash].end();
    }
};
