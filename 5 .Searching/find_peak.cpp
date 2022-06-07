#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int solve(int arr[], int l, int r)
{
    if (l - r == 0)
        return arr[l];
    if (l - r == 1)
        return max(arr[l], arr[r]);

    int mid = (l + r) / 2;
    if (arr[mid] >= arr[mid - 1] and arr[mid] >= arr[mid + 1])
        return arr[mid];
    if (arr[mid - 1] >= arr[mid])
    {
        return solve(arr, l, mid - 1);
    }
    else
        return solve(arr, mid + 1, r);
}

int main()
{
    int arr[] = {21, 20, 15, 10, 5, 5, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    if (n == 1)
        return arr[0];

    cout << solve(arr, 0, n - 1);

    return 0;
}