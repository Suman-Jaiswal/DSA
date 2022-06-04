#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n = 7, arr[n] = {2, 8, 3, 9, 6, 5, 4};

    int prefixSum[n];
    prefixSum[0] = arr[0];

    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + arr[i];
    }

    int t;
    cin >> t;
    while (t--)
    {
        int p, q;
        cin >> p >> q;
        cout << prefixSum[q] - (p == 0 ? 0 : prefixSum[p - 1]) << endl;
    }

    return 0;
}