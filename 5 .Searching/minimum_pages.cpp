#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isFisible(int arr[], int k, int n, int ans)
{
    int req = 1, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (sum + arr[i] > ans)
        {
            req++;
            sum = arr[i];
        }
        else
            sum += arr[i];
    }
    return (req <= k);
}

int minPages(int arr[], int k, int n)
{
    int mx = arr[0], sum = arr[0];
    for (int i = 1; i < n; i++)
    {
        mx = max(mx, arr[i]);
        sum += arr[i];
    }
    int low = mx, high = sum, res = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (isFisible(arr, k, n, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
            low = mid + 1;
    }
    return res;
}

int main()
{
    int arr[] = {10, 20, 10, 30}, k = 2, n = sizeof(arr) / sizeof(arr[0]);

    cout << minPages(arr, k, n);

    return 0;
}