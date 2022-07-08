#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct MyHash
{
    int BUCKET;
    list<int> *table;
    MyHash(int b)
    {
        BUCKET = b;
        table = new list<int>[b];
    }
    void insert(int key)
    {
        int i = key % BUCKET;
        table[i].push_back(key);
    }
    void remove(int key)
    {
        int i = key % BUCKET;
        table[i].remove(key);
    }
    bool search(int key)
    {
        int i = key % BUCKET;
        for (auto x : table[i])
        {
            if (x == key)
                return true;

            return false;
        }
    }
};

int main()
{
    int t;

    return 0;
}