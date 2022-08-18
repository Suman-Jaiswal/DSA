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

int mchain(int arr[], int n)
{
    mat2(dp, int, n, n);
    for (int i = 0; i < n - 2; i++)
    {
        dp[i][i + 1] = 0;
    }
    for (int gap = 2; gap < n; gap++)
    {
        for (int i = 0; i < n - gap; i++)
        {
            int j = i + gap;
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + arr[i] * arr[j] * arr[k]);
            }
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int arr[] = {20, 10, 30, 40};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << mchain(arr, n);

    return 0;
}