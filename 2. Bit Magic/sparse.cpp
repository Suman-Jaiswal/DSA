#include <bits/stdc++.h>
using namespace std;
#define ll long long int

bool isSparse(int n)
{
    int prev = -1, k = -1;

    while (k != prev + 1 && n != 0)
    {
        prev = k;
        int sn = (n & ~(n - 1));
        n = (n & (n - 1));
        k = log2(sn) + 1;
    }

    if (k == prev + 1)
        return 0;
    else
        return 1;
}

int main()
{
    int t = 3;

    cout << isSparse(t);

    return 0;
}