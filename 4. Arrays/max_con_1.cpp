#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n = 9, arr[n] = {1, 0, 1, 1, 1, 1, 0, 1, 1};

    int res = 0, c = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i])
        {
            c++;
            res = max(res, c);
        }
        else
        {
            c = 0;
        }
    }
    cout << res;
    return 0;
}