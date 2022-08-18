// longest common subsequence

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size) vector<type> name(size)
#define v3(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col) vector<vector<type>> name(row, vector<type>(col));
#define mat3(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int solve(string s1, string s2, int n, int m, vector<vector<int>> &dp)
{
    loop(i, 1, n + 1)
    {
        loop(j, 1, m + 1)
        {
            if (s1[i - 1] == s2[j - 1])
            {
                cout << s1[i - 1] << " ";
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }
    return dp[n][m];
}

int main()
{
    string s1 = "AXYZ";
    string s2 = "BAZ";

    int n = s1.length();
    int m = s2.length();

    mat2(dp, int, n + 1, m + 1);

    loop(i, 0, n + 1)
    {
        loop(j, 0, m + 1)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }

    cout << solve(s1, s2, n, m, dp);

    return 0;
}