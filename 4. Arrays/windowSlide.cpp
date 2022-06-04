#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n = 6, k = 3, arr[n] = {1, 8, 30, -5, 20, 7};
    int s = 0;
    for (int i = 0; i < k; i++)
    {
        s += arr[i];
    }
    int res = s;
    for (size_t i = 1; i + k - 1 < n; i++)
    {
        s = s - arr[i - 1] + arr[i + k - 1];
        res = max(res, s);
    }
    cout << res;

    return 0;
}