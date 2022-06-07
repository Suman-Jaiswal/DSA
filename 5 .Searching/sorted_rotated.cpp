#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int binarySearch_Iterative(int arr[], int l, int r, int x)
{
    while (r >= l)
    {
        int mid = (r + l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
        {
            l = mid + 1;
        }
        else
            r = mid - 1;
    }

    return -1;
}

int solve(int arr[], int l, int r, int x)
{
    int mid = (l + r) / 2;
    if (arr[mid] == x)
        return mid;
    if (arr[l] == x)
        return 0;
    if (arr[r] == x)
        return r;
    if (arr[mid] > arr[l]) // left side sorted
    {
        if (x > arr[l] and x < arr[mid])
        {
            return binarySearch_Iterative(arr, l + 1, mid - 1, x);
        }
    }
    return solve(arr, mid + 1, r - 1, x);
}

int main()
{
    int arr[] = {3, 4, 5, 6, 7, 1, 2};
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 1;
    cout << solve(arr, 0, n - 1, x);

    return 0;
}