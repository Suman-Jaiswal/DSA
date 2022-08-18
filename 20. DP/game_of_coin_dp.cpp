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

int sol(int arr[], int n)
{
    mat2(dp, int, n, n);
    loop(i, 0, n - 1)
    {
        dp[i][i + 1] = max(arr[i], arr[i + 1]);
    }
    for (int gap = 3; gap < n; gap += 2)
    {
        loop(i, 0, n - gap)
        {
            int j = i + gap;
            dp[i][j] = max(
                arr[i] + min(dp[i + 2][j], dp[i + 1][j - 1]),
                arr[j] + min(dp[i][j - 2], dp[i + 1][j - 1]));
        }
    }
    return dp[0][n - 1];
}

int main()
{
    int n = 4;

    int arr[] = {20, 5, 4, 6};

    cout << sol(arr, n);

    return 0;
}