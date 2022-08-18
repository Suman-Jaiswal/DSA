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

int solve(int arr[], int n)
{
    v3(dp, int, n, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] >= i - j)
            {
                if (dp[j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
    }
    if (dp[n - 1] == INT_MAX)
        return -1;
    return dp[n - 1];
}

int main()
{
    int n = 6;
    int arr[n] = {3, 4, 2, 1, 2, 1};

    cout << solve(arr, n);

    return 0;
}