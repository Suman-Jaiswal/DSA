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

bool ispalind(string s, int l, int r)
{
    while (l <= r)
    {
        if (s[l] != s[r])
            return false;
        l++;
        r--;
    }
    return true;
}

int solve(string s, int n)
{
    mat2(dp, int, n, n);

    for (int i = 0; i < n; i++)
    {
        dp[i][i] = 0;
    }

    for (int gap = 1; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;
            if (ispalind(s, i, j))
                dp[i][j] = 0;
            else
            {
                dp[i][j] = INT_MAX;
                for (int k = i; k < j; k++)
                {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][k] + dp[k + 1][j]);
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main()
{
    string s = "geek";

    cout << solve(s, s.length());

    return 0;
}