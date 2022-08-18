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

int solve(int n)
{
    v2(dp, int, n + 1);
    dp[0] = 1;
    dp[1] = 1;
    for (int i = 2; i < n + 1; i++)
    {
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            int left = j, right = i - j - 1;
            dp[i] += dp[left] * dp[right];
        }
    }

    return dp[n];
}

int main()
{
    int n;
    cin >> n;

    cout << solve(n);

    return 0;
}