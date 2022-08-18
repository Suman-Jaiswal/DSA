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

int solve(int arr[], int n, int sum, vector<vector<int>> &dp)
{
    loop(i, 1, sum + 1)
    {
        loop(j, 1, n + 1)
        {
            dp[i][j] = dp[i][j - 1];
            if (arr[j - 1] <= i)
                dp[i][j] += dp[i - arr[j - 1]][j];
        }
    }
    return dp[sum][n];
}

int main()
{
    int sum = 8;
    int n = 2;
    int coins[n] = {1, 2};

    mat2(dp, int, sum + 1, n + 1);

    loop(i, 0, n) dp[0][i] = 1;
    loop(i, 0, sum + 1) dp[i][0] = 0;

    cout << solve(coins, n, sum, dp);

    return 0;
}