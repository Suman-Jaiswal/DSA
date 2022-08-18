#include <bits/stdc++.h>
using namespace std;

int sum(int arr[], int b, int e)
{
    int s = 0;
    for (int i = b; i <= e; i++)
        s += arr[i];
    return s;
}

int minPages(int arr[], int n, int k)
{
    vector<vector<int>> dp(n + 1, vector<int>(k + 1));

    for (int i = 0; i < n + 1; i++)
    {
        dp[i][1] = sum(arr, 0, i - 1);
    }
    for (int i = 0; i < k + 1; i++)
    {
        dp[1][i] = arr[0];
    }

    for (int i = 2; i < n + 1; i++)
    {
        for (int j = 2; j < k + 1; j++)
        {
            dp[i][j] = INT_MAX;
            for (int k = 1; k < i; k++)
            {
                dp[i][j] = min(dp[i][j], max(dp[k][j - 1], sum(arr, k, i - 1)));
            }
        }
    }
    return dp[n][k];
}

int main()
{
    int arr[] = {10, 20, 10, 30};
    int n = sizeof(arr) / sizeof(arr[0]);
    int k = 2;

    cout << minPages(arr, n, k);
}
