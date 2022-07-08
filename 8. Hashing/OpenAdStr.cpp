#include <bits/stdc++.h>
using namespace std;
#define ll long long int

struct myHash
{
    int *arr;
    int cap, size;
    myHash(int c)
    {
        cap = c;
        size = 0;
        for (int i = 0; i < cap; i++)
        {
            arr[i] = -1; // empty
        }
    }
    int hash(int key)
    {
        return key % cap;
    }
    bool insert(int key)
    {
        if (size == cap)
            return false;

        int i = hash(key);
        while (arr[i] != -1 and arr[i] != -2 and arr[i] != key)
        {
            i = (i + 1) % cap;
        }
        if (arr[i] == key)
            return false;
        else
        {
            arr[i] = key;
            size++;
            return true;
        }
    }
    bool search(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                return true;
            }
            i = (i + 1) % cap;
            if (i == h)
                return false;
        }
        return false;
    }
    bool erase(int key)
    {
        int h = hash(key);
        int i = h;
        while (arr[i] != -1)
        {
            if (arr[i] == key)
            {
                arr[i] = -2;
                return true;
            }
            i = (i + 1) % cap;
            if (i == h)
                return false;
        }
        return false;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
    }

    return 0;
}