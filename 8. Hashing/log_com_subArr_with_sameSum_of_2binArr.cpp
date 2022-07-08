#include <bits/stdc++.h>
using namespace std;
#define ll long long int

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

int solve(int arr1[], int arr2[], int n)
{
    int arr[n];
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = arr1[i] - arr2[i];
    }
    return largestSubarrayWithSumX(arr, n, 0);
}

int main()
{
    int arr1[] = {0, 1, 0, 0, 0, 0};
    int arr2[] = {1, 0, 1, 0, 0, 1};
    int n = sizeof(arr1) / sizeof(arr1[0]);

    cout << solve(arr1, arr2, n);

    return 0;
}
