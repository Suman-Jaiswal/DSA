#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n = 6, arr[n] = {-3, 8, -2, 4, -5, 6};

    int res = 0, maxending = arr[0];

    for (int i = 1; i < n; i++)
    {
        maxending = max(maxending + arr[i], arr[i]);
        res = max(res, maxending);
    }
    cout << res;

    return 0;
}