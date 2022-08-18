#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size) vector<type> name(size)
#define v3(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col) vector<vector<type>> name(row, vector<type>(col))
#define mat3(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int solve(int coins[], int n, int val)
{
    if (val == 0)
        return 0;
    int res = INT_MAX;
    for (size_t i = 0; i < n; i++)
    {
        if (coins[i] <= val)
        {
            int subres = solve(coins, n, val - coins[n - 1]);
            if (subres != INT_MAX)
                res = min(res, subres + 1);
        }
    }

    return res;
}

int main()
{
    int n = 3;
    int coins[n] = {25, 10, 5};

    cout << solve(coins, n, 30);

    return 0;
}