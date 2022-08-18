#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool Mycomp(pair<int, int> a, pair<int, int> b)
{
    return (a.second > b.second);
}

int maxProfit(pair<int, int> arr[], int n)
{
    sort(arr, arr + n, Mycomp);
    for (size_t i = 0; i < n; i++)
    {
        cout << arr[i].second << " " << arr[i].first << endl;
    }

    int taken[n] = {false};
    int lastDeadline = arr[0].first;
    for (size_t i = 0; i < n; i++)
    {
        lastDeadline = max(lastDeadline, arr[i].first);
    }

    bool slots[lastDeadline] = {false};

    int res = arr[0].second;

    int slot = arr[0].first;

    slots[slot - 1] = true;

    for (int i = 1; i < n; i++)
    {
        int value = arr[i].second;
        int slot = arr[i].first;
        slot--;
        if (slots[slot] == false)
        {
            res += value;
            slots[slot] = true;
        }
        else
        {
            while (slots[slot] == true and slot > 0)
                slot--;
        }
        if (slots[slot] == false)
        {
            res += value;
            slots[slot] = true;
        }
    }

    return res;
}

int main()
{
    pair<int, int> arr[] = {
        make_pair(4, 50),
        make_pair(1, 5),
        make_pair(1, 20),
        make_pair(5, 10),
        make_pair(5, 80),
    };

    int n = sizeof(arr) / sizeof(arr[0]);

    cout << maxProfit(arr, n);

    return 0;
}