#include <bits/stdc++.h>
using namespace std;
#define ll long long int

int minCoins(int coin[], int n, int am)
{
    sort(coin, coin + n, greater<int>());
    int res = 0;
    for (size_t i = 0; i < n; i++)
    {
        int c = coin[i];
        if (c <= am)
        {
            int num = floor(am / c);
            am = am - num * c;
            res = res + num;
        }
        if (am == 0)
            break;
    }
    return res;
}

int main()
{
    int coin[] = {5, 10, 2, 1}, n = 4, amount = 57;

    cout << minCoins(coin, n, amount);

    return 0;
}