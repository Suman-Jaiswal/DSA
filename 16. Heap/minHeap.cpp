// binary tree should be complete and every node is smaller than its decendents.

#include <bits/stdc++.h>
using namespace std;

class MinHeap
{
    vector<int> arr;
    int size;

public:
    MinHeap()
    {
        size = 0;
    }

    int left(int i) { return (2 * i + 1); }
    int right(int i) { return (2 * i + 2); }
    int parent(int i) { return (i - 1) / 2; }

    void insert(int x)
    {
        arr.push_back(x);
        int i = arr.size() - 1;
        while (i > 0)
        {
            if (arr[parent(i)] > arr[i])
            {
                swap(arr[i], arr[parent(i)]);
                i = parent(i);
            }
            else
                break;
        }
    }

    void printHeap()
    {
        for (int x : arr)
            cout << x << " ";
    }
};

int main()
{
    MinHeap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(40);
    h.insert(50);
    h.insert(100);
    h.insert(25);
    h.insert(45);
    h.insert(12);
    h.printHeap();
    return 0;
}
