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
    if (n == 0)
        return 0;
    int res = INT_MAX;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] >= n - i)
        {
            int temp = solve(arr, i);
            if (temp != INT_MAX)
                res = min(res, temp + 1);
        }
    }
    return res;
}

int main()
{
    int n = 6;
    int arr[n] = {3, 4, 2, 1, 2, 1};

    cout << solve(arr, n - 1);

    return 0;
}