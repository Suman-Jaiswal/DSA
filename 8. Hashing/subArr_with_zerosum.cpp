#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool result(int arr[], int n)
{
    int preSum = arr[0];
    unordered_set<int> set;
    set.insert(preSum);
    for (size_t i = 1; i < n; i++)
    {
        preSum += arr[i];
        if (preSum == 0)
            return true;
        if (set.find(preSum) != set.end())
            return true;

        set.insert(preSum);
    }
    return false;
}

int main()
{
    int arr[] = {-3, 4, -3, -1, 1};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << result(arr, n);

    return 0;
}