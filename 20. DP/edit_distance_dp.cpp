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

int solve(string s1, string s2, int m, int n, vector<vector<int>> &dp)
{
    loop(i, 1, m + 1)
        loop(j, 1, n + 1)
    {
        if (s1[i - 1] == s2[j - 1])
            dp[i][j] = dp[i - 1][j - 1];
        else
        {
            dp[i][j] = 1 + min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]);
        }
    }
    return dp[m][n];
}

int main()
{
    string s1 = "saturday";
    string s2 = "sunday";

    int m = s1.size();
    int n = s2.size();

    mat2(dp, int, m + 1, n + 1);

    loop(i, 0, m + 1) dp[i][0] = i;
    loop(i, 0, n + 1) dp[0][i] = i;

    cout << solve(s1, s2, m, n, dp);

    return 0;
}