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

int solve(int n, int a, int b, int c)
{
    int dp[n + 1];
    dp[0] = 0;
    for (int i = 1; i < n + 1; i++)
    {
        dp[i] = -1;
        if (i - a >= 0)
            dp[i] = max(dp[i], dp[i - a]);
        if (i - b >= 0)
            dp[i] = max(dp[i], dp[i - b]);
        if (i - c >= 0)
            dp[i] = max(dp[i], dp[i - c]);

        if (dp[i] != -1)
            dp[i]++;
    }
    return dp[n];
}

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;

    cout << solve(n, a, b, c);

    return 0;
}