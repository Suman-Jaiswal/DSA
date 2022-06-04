#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n = 4, arr[n] = {10, 12, 8, 4};

    int current = arr[0] % 2, res = 1, c = 1;

    for (int i = 1; i < n; i++)
    {
        if (arr[i] % 2 == !current)
        {
            c++;
            res = max(res, c);
        }
        else
            c = 1;
        current = arr[i] % 2;
    }
    cout << res;

    return 0;
}