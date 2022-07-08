#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int arr[], int n)
{
    unordered_set<int> h(arr, arr + n);
    int res = 1;
    for (auto x : h)
    {
        if (h.find(x - 1) == h.end())
        {
            int cur = 1;
            while (h.find(x + cur) != h.end())
            {
                cur++;
            }
            res = max(res, cur);
        }
    }
    return res;
}

int main()
{
    int arr[] = {1, 3, 9, 2, 8, 2};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << solve(arr, n);

    return 0;
}