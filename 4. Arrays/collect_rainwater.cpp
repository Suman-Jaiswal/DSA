#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    // naive soln;
    int n = 5, arr[n] = {5, 0, 6, 2, 3};

    int res = 0;

    // for (int i = 1; i < n - 1; i++)
    // {
    //     int l_max = arr[i];
    //     for (int j = 0; j < i; j++)
    //     {
    //         l_max = max(arr[j], l_max);
    //     }
    //     int r_max = arr[i];
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         r_max = max(arr[j], r_max);
    //     }

    //     res += min(l_max, r_max) - arr[i];
    // }

    // efficient

    int l_max[n], r_max[n];

    l_max[0] = arr[0];
    r_max[n - 1] = arr[n - 1];

    for (int i = 1; i < n; i++)
    {
        l_max[i] = max(l_max[i - 1], arr[i]);
    }

    for (int i = n - 2; i >= 0; i--)
    {
        r_max[i] = max(r_max[i + 1], arr[i]);
    }

    for (int i = 1; i < n - 1; i++)
    {
        res += min(l_max[i], r_max[i]) - arr[i];
    }

    cout << res;
    return 0;
}