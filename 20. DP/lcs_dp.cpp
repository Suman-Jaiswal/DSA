// longest common subsequence

#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define loop(itr, start, end) for (int itr = start; itr < end; itr++)
#define v1(name, type) vector<type> name
#define v2(name, type, size, fill) vector<type> name(size, fill)
#define mat1(name, type) vector<vector<type>> name
#define mat2(name, type, row, col, fill) vector<vector<type>> name(row, vector<type>(col, fill))

int solve(string s1, string s2, int n, int m, vector<vector<int>> &memo)
{
    if (memo[n][m] != -1)
        return memo[n][m];

    if (n == 0 || m == 0)
        memo[n][m] = 0;
    else
    {
        if (s1[n - 1] == s2[m - 1])
        {
            memo[n][m] = 1 + solve(s1, s2, n - 1, m - 1, memo);
        }
        else
        {
            memo[n][m] = max(solve(s1, s2, n - 1, m, memo), solve(s1, s2, n, m - 1, memo));
        }
    }
    return memo[n][m];
}

int main()
{
    string s1 = "AXYZ";
    string s2 = "BAZ";

    int n = s1.length();
    int m = s2.length();

    mat2(memo, int, n + 1, m + 1, -1);

    cout << solve(s1, s2, n, m, memo);

    return 0;
}