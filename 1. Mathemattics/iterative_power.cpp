#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int x, n, res = 1;
    cin >> x >> n;
    while (n > 0)
    {
        if (n % 2 != 0)
        {
            res = res * x;
        }
        x = x * x;
        n = n / 2;
    }
    cout << res;
    return 0;
}