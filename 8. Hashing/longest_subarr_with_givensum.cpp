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

int main()
{
    int arr[] = {8, 3, -7, -4, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = -8;

    cout << largestSubarrayWithSumX(arr, n, sum);
}