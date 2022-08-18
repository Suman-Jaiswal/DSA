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

int solve(int f, int e)
{
    mat2(dp, int, e + 1, f + 1);
    for (int i = 0; i < e + 1; i++)
    {
        dp[i][0] = 0;
        dp[i][1] = 1;
    }
    for (int i = 0; i < f + 1; i++)
    {
        dp[0][i] = 0;
        dp[1][i] = i;
    }
    int res;
    for (int i = 2; i < e + 1; i++)
    {
        for (int j = 2; j < f + 1; j++)
        {
            dp[i][j] = INT_MAX;
            for (int x = 1; x < f + 1; x++)
            {
                res = max(dp[i - 1][x - 1], dp[i][j - x]);
                if (res < dp[i][j])
                    dp[i][j] = res + 1;
            }
        }
    }

    return dp[e][f];
}

int main()
{
    int f = 3;
    int e = 2;

    cout << solve(f, e);

    return 0;
}