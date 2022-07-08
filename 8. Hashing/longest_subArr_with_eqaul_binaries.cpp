#include <bits/stdc++.h>
using namespace std;

int largestSubarrayWithSumX(int arr[], int n, int sum)
{
    int prefix_sum = 0, res = 0;
    unordered_map<int, int> ump;

    for (int i = 0; i < n; i++)
    {
        prefix_sum += arr[i];
        if (prefix_sum == sum)
            res = i + 1;
        if (ump.find(prefix_sum) == ump.end())
            ump.insert({prefix_sum, i});
        if (ump.find(prefix_sum - sum) != ump.end())
            res = max(res, i - ump[prefix_sum - sum]);
    }
    return res;
}

int largestOneZeroSubarray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        arr[i] = (arr[i] == 0) ? -1 : 1;
    return largestSubarrayWithSumX(arr, n, 0);
}

int main()
{
    int arr[] = {1, 1, 1, 0, 1, 0, 1, 1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << largestOneZeroSubarray(arr, n);
}