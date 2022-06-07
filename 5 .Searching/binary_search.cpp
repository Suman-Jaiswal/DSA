#include <bits/stdc++.h>
using namespace std;
#define ll long long int;

int binarySearch_Recursive(int arr[], int l, int r, int x)
{
    if (r >= l)
    {
        int mid = (r + l) / 2;
        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            return binarySearch_Recursive(arr, mid + 1, r, x);

        else
            return binarySearch_Recursive(arr, l, mid - 1, x);
    }

    return -1;
}
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
int main()
{
    int arr[] = {2, 3, 4, 10, 40, 50, 51, 52, 53, 55};
    int x = 55;
    int n = sizeof(arr) / sizeof(arr[0]);
    int result = binarySearch_Iterative(arr, 0, n - 1, x);
    (result == -1) ? cout << "not found" : cout << result;
    return 0;
}