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
    if (n == 1)
        return arr[0];
    int prev_prev = arr[0];
    int prev = max(arr[0], arr[1]);
    int res = prev;

    for (int i = 3; i < n + 1; i++)
    {
        res = max(prev, prev_prev + arr[i - 1]);
        prev_prev = prev;
        prev = res;
    }

    return res;
}

int main()
{
    int n = 4;
    int arr[n] = {10, 5, 15, 20};

    cout << solve(arr, n);

    return 0;
}