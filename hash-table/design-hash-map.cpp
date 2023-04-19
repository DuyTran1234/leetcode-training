#include <vector>
#include <algorithm>
#include <list>
#include <utility>
#include <iostream>
using namespace std;

class MyHashMap
{
private:
    int prime;
    vector<list<pair<int, int>>> map;

    int hash(int key)
    {
        return key % prime;
    }

    list<pair<int, int>>::iterator search(int key)
    {
        int hash = this->hash(key);
        for (auto i = map[hash].begin(); i != map[hash].end(); ++i)
        {
            if ((*i).first == key)
            {
                return i;
            }
        }
        return map[hash].end();
    }

public:
    MyHashMap()
    {
        this->prime = 10000;
        map = vector<list<pair<int, int>>>(prime);
    }

    void put(int key, int value)
    {
        int hash = this->hash(key);
        auto it = this->search(key);
        if (it == map[hash].end())
        {
            map[hash].push_back(pair<int, int>{key, value});
        }
        else
        {
            (*it).second = value;
        }
    }

    int get(int key)
    {
        int hash = this->hash(key);
        auto it = this->search(key);
        if (it == map[hash].end())
        {
            return -1;
        }
        else
        {
            return (*it).second;
        }
    }

    void remove(int key)
    {
        int hash = this->hash(key);
        auto it = this->search(key);
        if (it != map[hash].end())
        {
            map[hash].erase(it);
        }
    }

    void display()
    {
        for (int i = 0; i < this->prime; ++i)
        {
            for (auto iter = map[i].begin(); iter != map[i].end(); ++iter)
            {
                std::cout << "[" << (*iter).first << "," << (*iter).second << "]"
                          << "\n";
            }
        }
    }
};

int main()
{
    MyHashMap *map = new MyHashMap();
    map->put(1, 1);
    map->put(2, 2);

    std::cout << map->get(1) << "\n";
    std::cout << map->get(3) << "\n";

    map->put(2, 1);
}
// ["MyHashMap","put","put","get","get","put","get","remove","get"]
// [[],         [1,1],[2,2], [1],  [3], [2,1],[2],   [2],     [2]]