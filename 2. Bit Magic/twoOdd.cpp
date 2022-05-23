#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n = 10;
    int arr[10] = {3, 4, 3, 4, 5, 4, 4, 6, 7, 7};

    int XOR = 0, res1 = 0, res2 = 0;

    for (int i = 0; i < n; i++)
    {
        XOR = (XOR ^ arr[i]);
    }

    int sn = (XOR & ~(XOR - 1));

    for (int i = 0; i < n; i++)
    {
        if ((arr[i] & sn) != 0)
            res1 = res1 ^ arr[i];
        else
            res2 = res2 ^ arr[i];
    }

    cout << res1 << ", " << res2;

    return 0;
}