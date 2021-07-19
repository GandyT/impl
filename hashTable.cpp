#include <iostream>
#include <list>
#include <cstring>
using namespace std;

/* 
PRACTICE HASH TABLE TO STORE PHONE NUMBERS MAPPED TO NAMES
*/
class HashTable
{

private:
    list<pair<int, string>> table[10];

    int getHash(int key)
    {
        return key % 10;
    }

public:
    bool isEmpty()
    {
        for (int i = 0; i < 10; ++i)
        {

            if (table[i].size() != 0)
                return false;
        }

        return true;
    }
    void insert(int key, string value)
    {
        int hash = getHash(key);

        bool exists = false;

        for (auto itr = table[hash].begin(); itr != table[hash].end(); ++itr)
        {

            if (itr->first == key)
            {
                exists = true;
                table[hash].erase(itr);
                cout << "[INFO] Key exists already. Replaced" << endl;
            }
        }

        table[hash].emplace_back(hash, value);
    }
    void printAll()
    {
        for (int i = 0; i < 10; ++i)
        {
            for (auto itr = table[i].begin(); itr != table[i].end(); ++itr)
            {
                cout << itr->first << " " << itr->second << endl;
            }
        }
    }
};

/* 
TYPE 
g++ hashTable.cpp
.\a.exe

to run this file
*/
int main()
{
    HashTable table;

    if (table.isEmpty())
    {
        cout << "[INFO] isEmpty works." << endl;
    }
    else
    {
        cout << "[WARN] isEmpty does not work." << endl;
    }

    table.insert(700, "Bobby");
    table.insert(801, "Danny");
    table.printAll();

    return 0;
}
