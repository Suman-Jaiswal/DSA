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

int solve(int arr[], int n, int sum)
{
    if (sum == 0)
        return 1;
    if (n == 0)
        return 0;
    int res = solve(arr, n - 1, sum);
    if (arr[n - 1] <= sum)
        res += solve(arr, n, sum - arr[n - 1]);

    return res;
}

int main()
{
    int sum = 4;
    int n = 3;
    int coins[n] = {1, 2, 3};

    cout << solve(coins, n, sum);

    return 0;
}