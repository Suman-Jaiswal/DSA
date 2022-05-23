#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n = 4;

    int k = floor(log2(n));
    int init = pow(2, k);

    while (k > 0)
    {
        if ((init & (1 << k)) != 0)
        {
            if ((n & (1 << (k - 1))) == 0)
                init = (init | (1 << (k - 1)));
        }
        else
        {
            if ((n & (1 << (k - 1))) != 0)
                init = (init | (1 << (k - 1)));
        }

        k--;
    }

    cout << init;

    return 0;
}