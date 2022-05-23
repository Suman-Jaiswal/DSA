#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int main()
{
    int n;
    cin >> n;

    bool res = ((n & (n - 1)) == 0);

    cout
        << res;
    return 0;
}