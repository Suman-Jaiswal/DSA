#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin >> n;

    int table[256];
    table[0] = 0;

    for (int i = 0; i < 256; i++)
    {
        table[i] = (i & 1) + table[i / 2];
    }

    int res = table[n & 0xff];
    n >>= 8;
    res += table[n & 0xff];
    n >>= 8;
    res += table[n & 0xff];
    n >>= 8;
    res += table[n & 0xff];

    cout << res;

    return 0;
}