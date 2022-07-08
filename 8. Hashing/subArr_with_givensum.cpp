#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool result(int arr[], int n, int sum)
{
    int preSum = 0;
    unordered_set<int> set;

    for (size_t i = 0; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == sum)
            return true;
        if (set.find(preSum - sum) != set.end())
            return true;

        set.insert(preSum);
    }
    return false;
}

int main()
{
    int arr[] = {-3, 4, -3, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int sum = 1;

    cout << result(arr, n, sum);

    return 0;
}