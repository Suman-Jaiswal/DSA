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
    v3(dp, int, val + 1, INT_MAX);
    dp[0] = 0;

    for (int i = 1; i < val + 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (coins[j] <= i)
                if (dp[i - coins[j]] != INT_MAX)
                    dp[i] = min(dp[i], dp[i - coins[j]] + 1);
        }
    }

    return dp[val];
}

int main()
{
    int n = 3;
    int coins[n] = {3, 4, 1};

    cout << solve(coins, n, 5);

    return 0;
}