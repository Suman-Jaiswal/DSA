#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int maxWater(int arr[], int n)
{
    int res = 0, l = 0, h = n - 1;
    while (l < h)
    {
        int gap = h - l - 1;
        if (arr[l] < arr[h])
        {
            res = max(res, min(arr[l], arr[h]) * gap);
            l++;
        }
        else
        {
            res = max(res, min(arr[l], arr[h]) * gap);
            h--;
        }
    }
    return res;
}

int main()
{
    int n;
    cin >> n;
    int height[n];
    for (size_t i = 0; i < n; i++)
    {
        cin >> height[i];
    }

    cout << maxWater(height, n);

    return 0;
}