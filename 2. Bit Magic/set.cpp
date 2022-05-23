#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n, k;
    cin >> n >> k;
    if ((n & (1 << (k - 1))) != 0)
    {
        cout << "yes";
    }
    else
        cout << "no";

    // or
    if (((n >> (k - 1)) & 1) == 1)
    {
        cout << "yes";
    }
    else
        cout << "no";

    return 0;
}